# CAN驱动电机

以rm2006电机为例，在ubuntu下使用can通信驱动。

参考资料：

- [rm2006使用说明](https://rm-static.djicdn.com/tem/17348/RM%20M2006%20P36%E7%9B%B4%E6%B5%81%E6%97%A0%E5%88%B7%E5%87%8F%E9%80%9F%E7%94%B5%E6%9C%BA%E4%BD%BF%E7%94%A8%E8%AF%B4%E6%98%8E.pdf)
- [rmc610](https://rm-static.djicdn.com/tem/RM%20C610%E6%97%A0%E5%88%B7%E7%94%B5%E6%9C%BA%E8%B0%83%E9%80%9F%E5%99%A8%E4%BD%BF%E7%94%A8%E8%AF%B4%E6%98%8E%20%E5%8F%91%E5%B8%83%E7%89%88.pdf)
- [How To Use SocketCAN With The Command-Line In Linux](https://blog.mbedded.ninja/programming/operating-systems/linux/how-to-use-socketcan-with-the-command-line-in-linux/)
- [How To Use SocketCAN With C++ In Linux](https://blog.mbedded.ninja/programming/operating-systems/linux/how-to-use-socketcan-with-c-in-linux/)

------

## 前期准备

- 如果您想在 CAN 接口上发送/接收数据，您应该安装`can-utils` ：

  ```
  sudo apt install can-utils
  ```

- 要将数据发送到 CAN 总线，请使用`cansend`实用程序：

  ```
  cansend can0 123#1122334455667788
  ```

  上述命令将在 can0 上发送一条 CAN 消息，标识符为 0x123，数据字节为 `[ 0x11, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77, 0x88 ]` 。值始终被视为十六进制。

- 要实时显示总线上收到的消息列表，请使用`candump`实用程序：

  ```
  candump can0
  ```

------

## CAN驱动

### 初始化

启用特定的 SocketCAN 接口也称为“启动接口” ，使用can转usb链接。

```
sudo ip link set can1 up type can bitrate 1000000  
```

`can1` 是一个 CAN 总线接口

`bitrate 1000000`配置 CAN 总线的波特率为 **1 Mbps**，参数值可在[rmc610](https://rm-static.djicdn.com/tem/RM%20C610%E6%97%A0%E5%88%B7%E7%94%B5%E6%9C%BA%E8%B0%83%E9%80%9F%E5%99%A8%E4%BD%BF%E7%94%A8%E8%AF%B4%E6%98%8E%20%E5%8F%91%E5%B8%83%E7%89%88.pdf)找到。

### 查看can电调ID

rmc610闪多少下代表ID多少，按下按键可以更换ID。

### 电调接受报文

rmc610为例，一个电调ID数据有高八位和第八位，因为数据范围为-10000～10000。对应电流范围-10A～10A。一个标识符控制四个电调ID。

发送时需将二进制16位数据转换成16进制数据。想发送多少A的电流将对应电流值线性映射到二进制上。反之同理。其余无需发送电流的电调ID值为。例如给电调ID为3的电机发送二进制值为512：

```
cansend can0 200#0000000001FF0000
```

式中`200`为标识符`0x200`

#### 使用脚本循环发送指令

仅发送一次无法使电机持续旋转。可以使用脚本发送指令。

```shell
#!/bin/bash
while true
do
cansend can1 200#0000000001FF0000
sleep 0.001
done                
```

`sleep 0.001`代表的是发送频率为`1KHz`，具体频率值可在[rmc610](https://rm-static.djicdn.com/tem/RM%20C610%E6%97%A0%E5%88%B7%E7%94%B5%E6%9C%BA%E8%B0%83%E9%80%9F%E5%99%A8%E4%BD%BF%E7%94%A8%E8%AF%B4%E6%98%8E%20%E5%8F%91%E5%B8%83%E7%89%88.pdf)查找。

------

### 电调反馈报文

标识符:0x200 + 电调 ID(如:ID 为1，该标识符为 0x201)

转子转速值的单位为:rpm（转/分）

转子机械角度值范围:0~8191（对应转子机械角度为 0~360°）

在实际驱动电机，电机无法直接识别机械值，只能识别电流值，在代码中编写过程使用的是国际单位值。所以需将国际单位值经过一系列转换变成电流值发送给电机。

例如，发送电流01FF,扭矩为对应`二进制/10000*10 *0.18`

0.18为N*m/A，特征参数可在电机使用说明给出。



