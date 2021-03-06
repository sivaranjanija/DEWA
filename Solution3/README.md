# Problem 3
 
* [Pre-requisite Installation](#installation)

## Single Jackal mapping an area of 100 meters squared

![Demo](demo3_1.gif)

Please watch the full demo [here](https://youtu.be/LJV_LT58Zkw).

## Jackal Swarm mapping

![Demo](demo3_2.gif)

Please watch the full demo [here](https://youtu.be/N3_2EN2Z1rM).

## <a name="installation"/>Installation

- run the [TemperatureGradient.ipynb](TemperatureGradient.ipynb) to generate temperatureActual.csv and place that file in [iofiles](jackal_swarm/iofiles). The sensor data in this file is published as a topic for further sensing by the robot.

- A map of 100 meters squared is created and placed in [maps](jackal_swarm/maps). 

Please refer the [video](https://youtu.be/1VrOWcbaLtk) demonstrating successful build

Please make sure that ros-kinetic is installed and is sourced in ~/.bashrc as source /opt/ros/kinetic/setup.bash


```bash
mkdir -p ~/jackal_ws/src
cd ~/jackal_ws
catkin_make
source devel/setup.bash
```

Copy the packages in Solution3 inside src and then :

- PLease edit the file [jackal_swarm/src/sensormap.cpp](jackal_swarm/src/sensormap.cpp) line 78 to save the generated temperature from jackal to [iofiles](jackal_swarm/iofiles).

```bash
catkin_make
source devel/setup.bash
```

- Please run the following in individual terminal, sourcing devel/setup.bash.

```bash
sudo apt-get install ros-kinetic-jackal-desktop 
roslaunch jackal_gazebo jackal_world.launch config:=front_laser

```
```bash
roslaunch jackal_swarm jackal_measure_temperature.launch

```

Please wait for the jackal to scan the entire 10*10 map, only then the recovered heat map will be populated completely, otherwise the temperature for only those cells where the jackal travelled will be there.You can see the generated MeasuredTemperature.csv file in [iofiles](jackal_swarm/iofiles)

- run the [RecoveredHeatMap.ipynb](RecoveredHeatMap.ipynb) to view the recovered heatmap from the Jackal generated MeasuredTemperature.csv file in [iofiles](jackal_swarm/iofiles)

Please refer the [video](https://youtu.be/a0N091pNz5k) demonstrating successful build

- Please run the following in individual terminal, sourcing devel/setup.bash
```bash
roslaunch multi_jackal_tutorials six_jackal.launch rviz:=true
rosrun multi_jackal_tutorials waypointmultiRobot1

```

