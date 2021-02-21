#include "sensormap.h"

using namespace std;

// constructor
CSensorCollection::CSensorCollection(const ros::NodeHandle &nh) : nh_(nh)
{
    subTemp = nh_.subscribe<std_msgs::Float32MultiArray>("/temperatureActual", 100, &CSensorCollection::temperatureCallback, this);
    subOdom0 = nh_.subscribe<nav_msgs::Odometry>("jackal0/odom", 10, &CSensorCollection::odom0Callback, this);
    subOdom1 = nh_.subscribe<nav_msgs::Odometry>("jackal1/odom", 10, &CSensorCollection::odom1Callback, this);
    subOdom2 = nh_.subscribe<nav_msgs::Odometry>("jackal2/odom", 10, &CSensorCollection::odom2Callback, this);
    subOdom3 = nh_.subscribe<nav_msgs::Odometry>("jackal3/odom", 10, &CSensorCollection::odom3Callback, this);
    subOdom4 = nh_.subscribe<nav_msgs::Odometry>("jackal4/odom", 10, &CSensorCollection::odom4Callback, this);
    subOdom5 = nh_.subscribe<nav_msgs::Odometry>("jackal5/odom", 10, &CSensorCollection::odom5Callback, this);
    
    // create a thread
    main_thread_ = boost::thread (&CSensorCollection::mainLoop, this);
}

// destructor
CSensorCollection::~CSensorCollection(){
    main_thread_.interrupt();
    main_thread_.join();
}


// callback for odom
void CSensorCollection::odom0Callback(const nav_msgs::Odometry::ConstPtr& msg){

  odomX0 = msg->pose.pose.position.x;
  odomY0 = msg->pose.pose.position.y;
  ROS_INFO("Seq: [%d]", msg->header.seq);
  ROS_INFO("Position-> x: [%f], y: [%f], z: [%f]", msg->pose.pose.position.x,msg->pose.pose.position.y, msg->pose.pose.position.z);
	
}

void CSensorCollection::odom1Callback(const nav_msgs::Odometry::ConstPtr& msg){

  odomX1 = msg->pose.pose.position.x;
  odomY1 = msg->pose.pose.position.y;
  ROS_INFO("Seq: [%d]", msg->header.seq);
  ROS_INFO("Position-> x: [%f], y: [%f], z: [%f]", msg->pose.pose.position.x,msg->pose.pose.position.y, msg->pose.pose.position.z);
	
}

void CSensorCollection::odom2Callback(const nav_msgs::Odometry::ConstPtr& msg){

  odomX2 = msg->pose.pose.position.x;
  odomY2 = msg->pose.pose.position.y;
  ROS_INFO("Seq: [%d]", msg->header.seq);
  ROS_INFO("Position-> x: [%f], y: [%f], z: [%f]", msg->pose.pose.position.x,msg->pose.pose.position.y, msg->pose.pose.position.z);
	
}

void CSensorCollection::odom3Callback(const nav_msgs::Odometry::ConstPtr& msg){

  odomX3 = msg->pose.pose.position.x;
  odomY3 = msg->pose.pose.position.y;
  ROS_INFO("Seq: [%d]", msg->header.seq);
  ROS_INFO("Position-> x: [%f], y: [%f], z: [%f]", msg->pose.pose.position.x,msg->pose.pose.position.y, msg->pose.pose.position.z);
	
}

void CSensorCollection::odom4Callback(const nav_msgs::Odometry::ConstPtr& msg){

  odomX4 = msg->pose.pose.position.x;
  odomY4 = msg->pose.pose.position.y;
  ROS_INFO("Seq: [%d]", msg->header.seq);
  ROS_INFO("Position-> x: [%f], y: [%f], z: [%f]", msg->pose.pose.position.x,msg->pose.pose.position.y, msg->pose.pose.position.z);
	
}

void CSensorCollection::odom5Callback(const nav_msgs::Odometry::ConstPtr& msg){

  odomX5 = msg->pose.pose.position.x;
  odomY5 = msg->pose.pose.position.y;
  ROS_INFO("Seq: [%d]", msg->header.seq);
  ROS_INFO("Position-> x: [%f], y: [%f], z: [%f]", msg->pose.pose.position.x,msg->pose.pose.position.y, msg->pose.pose.position.z);
	
}


// callback for temp
void CSensorCollection::temperatureCallback(const std_msgs::Float32MultiArray::ConstPtr& msg){

  int i = 0;
  for(std::vector<float>::const_iterator it = msg->data.begin(); it != msg->data.end(); ++it)
  {
    temperatureActual[i] = *it;
    ROS_INFO("Temperature: [%f]", *it);
    i++;            
  }
  return;
}

// main loop
void CSensorCollection::mainLoop(void)
{
    while (true)
    {             
        int temperatureAt0 = (static_cast<int>(odomX0) * 10) + static_cast<int>(odomY0);
        temperatureEstimated0[temperatureAt0] = temperatureActual[temperatureAt0];

        int temperatureAt1 = (static_cast<int>(odomX1) * 10) + static_cast<int>(odomY1);
        temperatureEstimated1[temperatureAt1] = temperatureActual[temperatureAt1];

        int temperatureAt2 = (static_cast<int>(odomX2) * 10) + static_cast<int>(odomY2);
        temperatureEstimated2[temperatureAt2] = temperatureActual[temperatureAt2];

        int temperatureAt3 = (static_cast<int>(odomX3) * 10) + static_cast<int>(odomY3);
        temperatureEstimated3[temperatureAt3] = temperatureActual[temperatureAt3];

        int temperatureAt4 = (static_cast<int>(odomX4) * 10) + static_cast<int>(odomY4);
        temperatureEstimated4[temperatureAt4] = temperatureActual[temperatureAt4];

        int temperatureAt5 = (static_cast<int>(odomX5) * 10) + static_cast<int>(odomY5);
        temperatureEstimated5[temperatureAt5] = temperatureActual[temperatureAt5];
        
        // sleep for 20 msec
        boost::this_thread::sleep_for (boost::chrono::milliseconds (20));
    }
}


int main(int argc, char **argv)
{
  ros::init(argc, argv, "sensormap");
  ros::NodeHandle nh_;
  //run
  CSensorCollection sensor(nh_);
  ros::spin();
  
  //write data to files TODO: function template
  std::ofstream measuredTemperature0;
  measuredTemperature0.open("/home/sivaranjani/jackal_navigation/src/multi_jackal_tutorials/iofiles/MeasuredTemperature0.csv");
  for(int i=0; i<100; i++)
  {
    measuredTemperature0 << temperatureEstimated0[i] << '\n';
  }
  measuredTemperature0.close();



  return 0;
}
