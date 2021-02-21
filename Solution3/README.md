# Problem 3
 
* [Pre-requisite Installation](#installation)


## <a name="installation"/>Installation

Please follow the [**installation**](https://www.clearpathrobotics.com/assets/guides/kinetic/jackal/simulation.html) instructions prior executing the launch file. Once the jackal_naivgation workspace is ready, clone these 2 repos along with the repos [here](https://github.com/NicksSimulationsROS/multi_jackal) as packages and execute:

```bash
cd jackal_navigation/
catkin_make
source devel/setup.bash 
```

## <a href="usage"/>Steps to Follow

- run the [TemperatureGradient.ipynb](TemperatureGradient.ipynb) to generate temperatureActual.csv and place in [iofiles](jackal_swarm/iofiles)

- Please run the launch as follows:

```bash
roslaunch jackal_swarm jackal_measure_temperature.launch
```

```bash
roslaunch multi_jackal_tutorials multijackal_measure_temperature.launch 

```

