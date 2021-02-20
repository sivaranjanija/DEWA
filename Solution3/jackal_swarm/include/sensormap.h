// includes
#include <ros/ros.h>
#include <nav_msgs/Odometry.h>
#include "std_msgs/Float32MultiArray.h"
#include <iostream>
#include<fstream>
#include <vector>

// boost includes
#include "boost/chrono.hpp"
#include "boost/thread.hpp"

using namespace std;

float temperatureObserved[100];

class CSensorCollection
{

private:
// ros variables
    ros::NodeHandle nh_;
    ros::Subscriber subTemp, subOdom;
    float temperatureActual[100];
    float temperatureEstimated[100];
    float odomX, odomY; 

// methods
    void temperatureCallback(const std_msgs::Float32MultiArray::ConstPtr& msg);
    void odomCallback(const nav_msgs::Odometry::ConstPtr& msg);

public:

   
// constructor
    CSensorCollection(const ros::NodeHandle &nh);

    // desturctor
    ~CSensorCollection();

    // thread
    boost::thread main_thread_;

    // thread execution function
    void mainLoop (void);
};

