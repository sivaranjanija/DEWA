# Problem 1
 

## Steps to run

Please run the launch as follows:

```bash
roslaunch localisation_gpu_odom_ins custom_ekf_localisation.launch 

```

and then run:

```bash
rosbag play path_to/data/ros_bag_data.bag --topics /imu/data /warthog_velocity_controller/odom /navsat/fix 

```
