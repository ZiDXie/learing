# 如何在docker部署ros

***该教程可以实现高版本ubuntu或者其他系统部署ros1,或者进行ros环境的隔离***

使用以下的docker-compose，使用的是osrf的ros镜像，也可使用鱼香的镜像。

```yml
services:
  ros_noetic_desktop:
    image: osrf/ros:noetic-desktop-full
    container_name: ros1
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


