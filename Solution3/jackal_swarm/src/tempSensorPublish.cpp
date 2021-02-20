//required includes
#include <ros/ros.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "std_msgs/MultiArrayLayout.h"
#include "std_msgs/MultiArrayDimension.h"
#include "std_msgs/Float32MultiArray.h"

using namespace std;

int main(int argc, char **argv){
	
  ros::init(argc, argv, "tempSensorPublish");
  ros::NodeHandle n;
  //publish temperature sensor data in a topic
  ros::Publisher temperature_pub = n.advertise<std_msgs::Float32MultiArray>("/temperatureActual",1000);
  ros::Rate loop_rate(10);
  while (ros::ok())
  {
    //read temperature data from a file
    ifstream temp("/home/sivaranjani/Desktop/temperatureActual.csv");
    if(!temp.is_open()) std::cout << "File not opened"<< '\n';
    int i;
    string val;
    float temperatureActual[100];
    i = 0;
    while(!temp.eof())
    {
      getline(temp, val, ',');
      temperatureActual[i]  = stof(val);
      i++;      
    }
    temp.close();
    std_msgs::Float32MultiArray msg;
    for(i = 0; i < 100; i++)
    {
      std::cout << " " << temperatureActual[i];
      msg.data.push_back(temperatureActual[i]);
     }
             
     temperature_pub.publish(msg);
     ROS_INFO("%d", msg.data);
     ros::spinOnce();
     loop_rate.sleep();         
  }
  return 0;
}
