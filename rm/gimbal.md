# 调整pid过程

## 云台

需要先将车上电时的程序都停止，因为车上自启程序时无法接受电脑发给他的数据，会造成冲突。

```bash
sudo systemctl stop rm_ecat_start.service rm_ecat_start.service 
sudo systemctl stop start_master.service 
```

然后手动跑程序

```bash
mon launch rm_config rm_ecat_hw.launch 
mon launch rm_config load_controllers.launch 
```

或者跑这个让所有程序跑起来

```bash
mon launch rm_bringup start.launch 
```

### yaw

调yaw轴时需要将pitch的pid和速度都给0,以防止pitch的干扰。先将joint_state_controller和robot_state_controller开起来。先将校准控制器开起来。然后关掉。调试云台将

开起来。

给pitch的pid为0

### 调整pid的方法

先给yaw轴一个正弦函数的速度值（注意需要修改发布的频率，否则会一直转）

然后打开plotjugger查看参数，云台采用的是双级PID，先调整速度环在调整位置环，调整速度环时无需给d

- 先给p，从0.2开始给，当尽可能将误差减小且电机不发抖时调i。从1开始，然后调位置环，当误差小于0.005时符合自瞄的标准。
  
  位置环从只给p，从10开始调整

- 调整后手动掰一下云台。查看是否会超调。

### pitch

同上，不过调pitch时需要将云台放平以防撞到机械限位。

# 如何调限位

## 云台

将云台手动扶到限位的位置，在plotjugger读取位置，将其记录在urdf的offset里面
