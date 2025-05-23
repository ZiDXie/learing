# linux新版clion使用配置stm32环境

***本教程需要使用clion2025.1以上，其他版本使用openocd或其他工具，使用opend请查阅其他教程***

***本教程基于linux,windows类似，stlink测试成功，其他烧录器没有测试***

| 工具           | 版本              |
| ------------ | --------------- |
| CLion        | CLion 2025.1及以上 |
| STM32CubeCLT |                 |
| STM32CubeMX  |                 |
| OpenOCD      |                 |

## 软件的下载及安装

- CLion：新版本（2025.1.1）已经支持非商用免费，无需再找破解。

- cubemx：[STM32CubeMX - STM32Cube initialization code generator - STMicroelectronics](https://www.st.com/en/development-tools/stm32cubemx.html)

- cubeclt：[STM32CubeCLT - Toolset for third-party integrated development environment (IDE) providers, allowing the use of STMicroelectronics proprietary tools within their own IDE frameworks - STMicroelectronics](https://www.st.com/en/development-tools/stm32cubeclt.html)

- openocd

cubeclt包含了各种编译链工具，如`arm-none-eabi-`、`ninja`、`cmake`等

## clion环境的配置

***Warning***

首先找到`cubeclt`安装后的工具位置，`cubeclt`安装的时候会将ubuntu的`cmake`环境设置为`cubeclt`工具链里面的，如在使用终端需要修改cmake为系统本身的版本，在`bashrc`文件输入：

```bash
export PATH=/usr/bin:$PATH
```

在clion的配置如图

![](/home/xie/.config/marktext/images/2025-05-22-21-06-32-image.png)

![](/home/xie/.config/marktext/images/2025-05-22-20-27-11-image.png)

## 测试环境是否正常

首先创建一个工程（以f407zgt6为例），clion通过cubemx创建文件查阅网上的资料。cubemx最后的`toolchain`选择`cmake`和`cubeide`都可以。如果没了解过`HAL`库和`cubemx`的请查阅网上资料。

如果环境正常，在clion里面构建效果如图

![](/home/xie/.config/marktext/images/2025-05-22-21-02-20-image.png)

![](/home/xie/.config/marktext/images/2025-05-22-20-49-26-image.png)

## 烧录

linux环境需要先连接stm32 gdb，在终端输入（提示没有命令的需要安装工具）

```bash
st-util 
```

成功的画面（或者有其他的输出，只要没报错就行）

![](/home/xie/.config/marktext/images/2025-05-22-21-00-43-image.png)

连接后再烧录

![](/home/xie/.config/marktext/images/2025-05-22-20-53-05-image.png)

烧录后需要`ctrl+c`断开`gdb`连接才能运行程序

## 单机程序及FreeRTOS的调试

***Warning***

需要调试`FreeRTOS`的需要按照以下设置，否则调试会报错

![](/home/xie/.config/marktext/images/2025-05-22-21-07-54-image.png)

![](/home/xie/.config/marktext/images/2025-05-22-21-09-29-image.png)

- 可执行文件：`/opt/st/stm32cubeclt_1.18.0/STLink-gdb-server/bin/ST-LINK_gdbserver`
- 程序员：`/opt/st/stm32cubeclt_1.18.0/STM32CubeProgrammer/bin`

![](/home/xie/.config/marktext/images/2025-05-22-21-13-18-image.png)

![](/home/xie/.config/marktext/images/2025-05-22-21-15-23-image.png)

然后正常调试即可


