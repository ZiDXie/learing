# nuc上车前

## 安装ubuntu(如果拿到的硬盘没有系统)

下载ubuntu服务器版本镜像

安装服务器版本，一路确定跳转到选择镜像，选择一个合适的镜像源

![](https://img2024.cnblogs.com/blog/967675/202403/967675-20240322173935643-965887955.png)

配置磁盘分区，给/swap分配16g，/efi分配512m，剩下的硬盘空间全部挂载到/目录下。选下面的Custom storage layout

![](https://img2024.cnblogs.com/blog/967675/202403/967675-20240322174254829-1795025193.png)

AVAILABLE DEVICES为空闲空间，USED　DEVICES为使用的分区

![](https://img2024.cnblogs.com/blog/967675/202403/967675-20240322174352456-515191639.png)

下面name和username填dynamicx,server's name填兵种的名字，密码dynamicx

![](https://img2024.cnblogs.com/blog/967675/202403/967675-20240322174805007-343495798.png)

后面一路默认直接完成。

## 安装ssh，并通过ssh用你的电脑操控nuc

将自己的电脑连接上wifi，然后用一根网线将nuc和你的电脑连接。这时你的电脑左上方会出现有线连接的图标。进入有线连接，点击设置，点击IPV4,设置“与其他计算机共享网络”（类似的意思）。

![](/home/xie/.var/app/com.github.marktext.marktext/config/marktext/images/2025-04-20-20-32-10-image.png)

```bash
sudo apt install openssh-server
```

在nuc上使用`ip a`查看nuc的ip地址。在你的电脑上输入指令`ssh dynamicx@“nuc的ip地址”`这样你就能在你的电脑上操控nuc了

## 安装easywifi

在github上搜索easywifi,第一个就是。将源代码clone下来，注意要用http。

安装easywifi依赖：

```bash
sudo apt-get install network-manager-config-connectivity-ubuntu
```

进入easywifi文件夹，输入

```bash
sudo python3 easywifi.py
```

成功运行easywifi，运行 `1*<!–Scan for networks–>` 搜索wifi，然后运行 ``5*<!–Setup new network–>` 输入wifi名称和密码，让nuc连上wifi。和nuc连上同一个wifi，继续用ssh操控nuc。

## 安装ros

[[14个ROS版本任你选]一键安装+Docker使用指南 | 鱼香ROS](https://fishros.org.cn/forum/topic/351/14%E4%B8%AAros%E7%89%88%E6%9C%AC%E4%BB%BB%E4%BD%A0%E9%80%89-%E4%B8%80%E9%94%AE%E5%AE%89%E8%A3%85-docker%E4%BD%BF%E7%94%A8%E6%8C%87%E5%8D%97)

### 安装catkin tools

catkin tools官方文档：[Catkin Command Line Tools &mdash; catkin_tools 0.0.0 documentation](https://catkin-tools.readthedocs.io/en/latest/) 如果你使用catkin build时需要你安装osrf-pycommon>0.1.1这个依赖，请输入以下指令：

```bash
sudo apt-get install python3-pip
pip3 install osrf-pycommon
```

## 免密登陆设置

当我们远程连接NUC的时候，需要输入密码，但是这样的话可能会比较麻烦，因此最好我们配置免密登陆，可以省去很多麻烦

在自己的电脑上输入命令：

```bash
ssh-copy-id dynamicx@host
```

回车之后还需要输入一次密码，输入完之后就可以了，以后每次都可以免密登陆。

## 优化

你会发现开机很慢，这是一个系统服务导致的，可以设置将其跳过。

```bash
sudo vim /etc/netplan/01-netcfg.yaml
```

注：这个文件可能不叫这个名字，可能需要转到/etc/netplan这个目录下看看。

在网卡的下一级目录中增加`optional: true`

修改完后生效设置

```bash
 sudo netplan apply
```

阻止nuc休眠,nuc长时间不用会休眠，会给工作带来一定麻烦。因此需要设置阻止nuc休眠。输入以下指令：

```bash
sudo systemctl mask sleep.target suspend.target hibernate.target hybrid-sleep.target
```

## 换内核

使用 [xanmod](https://xanmod.org) 。

我们需要更换一个实时性更强的内核，这样的内核通常名字里会带有“rt”（realtime）。在这个网站往下拉会看到“Install via Terminal”(通过命令行安装)。根据提示安装自己想要的内核（目前队内使用的是实时性内核为: **Linux version 6.1.38-rt12-x64v3-xanmod1** ）。

使用指令 `sudo dpkg --get-selections | grep linux-image` 来查看你想要安装的内核是否安装成功。

## 配置上电电脑自动开机

重启，开机按F2进入[BIOS](https://so.csdn.net/so/search?q=BIOS&spm=1001.2101.3001.7020)。  
找[power](https://so.csdn.net/so/search?q=power&spm=1001.2101.3001.7020)->Secondary Power Settings。  
将After Power Failure设置为 Power On。cooling选项里将Fan Control Mode设置为Fixed，Fixed Duty Cycle设为100。 **关闭安全启动** 然后退出BIOS，正常启动。

P.S: 如果能进入linux系统，那么可以执行 `sudo systemctl reboot --firmware-setup` ，重启直接不进入系统，而进入bios。

## 测试新内核的实时性和can总线传输速率

## 将主仓的代码拉进nuc编译

进入`rm_bingup/scripts/autostart/environment`

```bash
bash deploy.sh 兵种名字
```

## 配置开机免密登录

创建 systemd override 配置

```bash
sudo mkdir -p /etc/systemd/system/getty@tty1.service.d
sudo nano /etc/systemd/system/getty@tty1.service.d/override.conf
```

添加以下内容（替换用户名）

```ini
ExecStart= 
ExecStart=-/sbin/agetty --autologin your_username --noclear %I $TERM
```

将 `your_username` 替换为你自己的用户名

## 配置sudo免密

# 上车后
