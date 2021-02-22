# Problem 1
 

## Steps to build and run the solution

Please refer the [build process video](https://youtu.be/vNdZsEwVvc4) of the successful build.

Please make sure that ros-kinetic is installed and is sourced in ~/.bashrc as source /opt/ros/kinetic/setup.bash


```bash
mkdir -p ~/catkin_ws/src
cd ~/catkin_ws
catkin_make
source devel/setup.bash
```

Copy localisation_gpu_odom from Solutions1 folder and paste in ~/catkin_ws/src, and launch


```bash
roslaunch localisation_gpu_odom_ins custom_localisation.launch 
```

In another terminal, run the input

```bash
rosbag play path_to_input/data/ros_bag_data.bag --topics /imu/data /warthog_velocity_controller/odom /navsat/fix 

```

Filtered output in another terminal

```bash
rostopic echo /odometry/filtered

```
