# 如何在docker部署ros

本教程使用docker compose管理docker容器

## 软件安装

docker_ce

docker_compose

### Docker用户权限问题

默认情况下，需要使用sudo权限来运行Docker命令，通过将用户添加到Docker用户组，可以在无需sudo的情况下运行Docker命令。 （如果当前用户没有加入Docker用户组并且没有sudo权限的话，会报错：permission denied while trying to connect to the Docker daemon socket at unix:///var/run/docker.sock:）

***如果是通过鱼香ROS一键安装脚本安装的Docker，应该是不会出现用户组的问题，一键安装的时候就已经设置好了，如果是自己单独安装的Docker则需要注意这个问题***

### 将当前用户加入到docker组

```bash
sudo gpasswd -a $USER docker
newgrp docker  #切换到docker组
```

## 镜像拉取

如果是本地的tar包镜像。在存放的地方打开终端

```bash
docker load -i my-image.tar
```

## 容器创建

### docker_compose.yml

创建一个属于文件夹用来管理不同的docker compose。创建一个docker_compose.yml

***该教程可以实现高版本ubuntu或者其他linux发行版本部署ros1,或者进行ros环境的隔离。***

使用以下的docker-compose，使用的是osrf的ros镜像，也可使用鱼香的镜像，或者自己的镜像。***按需修改或增减参数***

```yml
services:
  ros_noetic_desktop:
    image: osrf/ros:noetic-desktop-full[这里是镜像名字，按需修改]
    container_name: ros1p[容器名字，按需修改]
    privileged: true
    network_mode: "host"
    environment:
      - DISPLAY=$DISPLAY
      - NVIDIA_VISIBLE_DEVICES=all
      - NVIDIA_DRIVER_CAPABILITIES=all

    volumes:
      - /dev:/dev
      - /home/${USER}:/home/${USER}
      - /tmp/.X11-unix:/tmp/.X11-unix

    working_dir: /home/${USER}
    stdin_open: true
    tty: true
    command: bash
```

然后在存放docker_compose.yml的文件夹打开终端。输入

```bash
docker compose up
```

## 使用容器

### 优雅的打开docker

1. 创建一个文件夹用于存放启动命令，然后cd进入

2. 创建启动文件并编辑内容这步操作是允许用户只使用容器名对容器进行操作，省去输入docker的原生指令

3. 文件中输入以下内容并保存：
   
   ```bash
   xhost +local:docker
   echo "请输入指令控制<your_name>容器: 启动(s) 重启(r) 进入(e) 关闭(c):"
   read choose
   case $choose in
   s) docker start <your_name>;;
   r) docker restart <your_name>;;
   e) docker exec -it <your_name> /bin/bash;;
   c) docker stop <your_name>;;
   esac
   newgrp docker
   ```

4. 赋予文件可执行权限
   
   ```bash
   sudo chmod +x 文件名(your_name)
   #在~/.bashrc 中添加该文件所在路径
   echo 'export PATH=$PATH:/home/your_username/[file_path]/[file_name]' >> ~/.bashrc
   ```

    5.设置好后任意终端中输入`容器名` 即可进入容器

进入容器后要先`sudo apt update`才可以安装软件
