#include "sensormap.h"

using namespace std;

// constructor
CSensorCollection::CSensorCollection(const ros::NodeHandle &nh) : nh_(nh)
{
    subTemp = nh_.subscribe<std_msgs::Float32MultiArray>("/temperatureActual", 100, &CSensorCollection::temperatureCallback, this);
    subOdom = nh_.subscribe<nav_msgs::Odometry>("/odometry/filtered", 10, &CSensorCollection::odomCallback, this);
    
    // create a thread
    main_thread_ = boost::thread (&CSensorCollection::mainLoop, this);
}

// destructor
CSensorCollection::~CSensorCollection(){
    main_thread_.interrupt();
    main_thread_.join();
}


// callback for odom
void CSensorCollection::odomCallback(const nav_msgs::Odometry::ConstPtr& msg){

  odomX = msg->pose.pose.position.x;
  odomY = msg->pose.pose.position.y;
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
        std::cout << "Odom X:" << static_cast<int>(odomX)<< "Odom Y:" << static_cast<int>(odomY) << '\n';
        //std::cout << "temperatureActual[1]:" << temperatureActual[1];
        
        //calc temp based on current pose; ((x)*10 + y) 
        int temperatureAt = (static_cast<int>(odomX) * 10) + static_cast<int>(odomY);
        temperatureEstimated[temperatureAt] = temperatureActual[temperatureAt];
        std::cout << "Estimatedlocation:" << temperatureAt << "Temperature:" << temperatureEstimated[temperatureAt] << '\n';
        temperatureObserved[temperatureAt] = temperatureActual[temperatureAt];

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
  for(int i=0; i<100; i++)
  {
    std::cout << "Temperature Observed at" << i << "is:" << temperatureObserved[i] << std::endl;
  }
  //write data to a file
  std::ofstream measuredTemperature;
  measuredTemperature.open("/home/sivaranjani/jackal_navigation/src/jackal_swarm/iofiles/MeasuredTemperature.csv");
  for(int i=0; i<100; i++)
  {
    measuredTemperature << temperatureObserved[i] << '\n';
  }
  measuredTemperature.close();

  return 0;
}
