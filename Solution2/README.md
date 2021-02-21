# Problem 3
 
* [Pre-requisite Installation](#installation)


## <a name="installation"/>Installation

Please follow the [**installation**](https://www.clearpathrobotics.com/assets/guides/kinetic/warthog/WarthogInstallation.html) instructions prior executing the launch file. Once the warthog_ws workspace is ready, clone this repo as a package inside it and execute:

```bash
cd warthog_ws/
catkin_make
source devel/setup.bash 
```

## Usage

Please run the launch as follows:

```bash
roslaunch warthog_navigation warthog_waypoint_navigation.launch 

```

and then run:

```bash
rosrun warthog_navigation waypoint_navigation 

```
