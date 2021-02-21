cmake_minimum_required(VERSION 2.8.3)
project(multi_jackal_tutorials)

## Compile as C++11, supported in ROS Kinetic and newer
add_compile_options(-std=c++11)

find_package(catkin REQUIRED COMPONENTS roslaunch)
find_package(catkin REQUIRED actionlib
  move_base_msgs
  roscpp std_msgs)
 find_package(Boost REQUIRED COMPONENTS thread chrono)

generate_messages(
   DEPENDENCIES
   std_msgs  # Or other packages containing msgs
 )

catkin_package(
  INCLUDE_DIRS include
  LIBRARIES multi_jackall_tutorials
  CATKIN_DEPENDS roscpp std_msgs
  DEPENDS system_lib
)
include_directories(include)
include_directories(
 ${catkin_INCLUDE_DIRS}
)

roslaunch_add_file_check(launch/one_jackal.launch)
roslaunch_add_file_check(launch/two_jackal.launch)
roslaunch_add_file_check(launch/three_jackal.launch)
roslaunch_add_file_check(launch/jackal_with_gps.launch)


add_executable(waypointmultiRobot1 src/waypointRobot1.cpp)
add_executable(multisensormap src/sensormap.cpp)

target_link_libraries(waypointmultiRobot1
   ${catkin_LIBRARIES}
 )
 target_link_libraries(multisensormap
   ${catkin_LIBRARIES}
   ${Boost_LIBRARIES}
 )

install(
	DIRECTORY launch rviz worlds
	DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION}
)
