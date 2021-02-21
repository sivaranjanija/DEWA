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

float temperatureEstimated0[100], temperatureEstimated1[100], temperatureEstimated2[100], temperatureEstimated3[100], temperatureEstimated4[100], temperatureEstimated5[100];

class CSensorCollection
{

private:
// ros variables
    ros::NodeHandle nh_;
    ros::Subscriber subTemp, subOdom0, subOdom1, subOdom2, subOdom3, subOdom4, subOdom5;
    float temperatureActual[100];
    float odomX0, odomY0, odomX1, odomY1, odomX2, odomY2, odomX3, odomY3, odomX4, odomY4, odomX5, odomY5; 

// methods
    void temperatureCallback(const std_msgs::Float32MultiArray::ConstPtr& msg);
    void odom0Callback(const nav_msgs::Odometry::ConstPtr& msg);
    void odom1Callback(const nav_msgs::Odometry::ConstPtr& msg);
    void odom2Callback(const nav_msgs::Odometry::ConstPtr& msg);
    void odom3Callback(const nav_msgs::Odometry::ConstPtr& msg);
    void odom4Callback(const nav_msgs::Odometry::ConstPtr& msg);
    void odom5Callback(const nav_msgs::Odometry::ConstPtr& msg);

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

