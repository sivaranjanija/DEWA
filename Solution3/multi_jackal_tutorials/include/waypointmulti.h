//required includes
#include <ros/ros.h>
#include <iostream>
#include <move_base_msgs/MoveBaseAction.h>
#include <actionlib/client/simple_action_client.h>
// boost includes
#include "boost/chrono.hpp"
#include "boost/thread.hpp"

class CMultiJackal
{

private:
// ros variables
    ros::NodeHandle nh_;

public:

  typedef actionlib::SimpleActionClient<move_base_msgs::MoveBaseAction> MoveBaseClient;
   
// constructor
    CMultiJackal(const ros::NodeHandle &nh);

    // desturctor
    ~CMultiJackal();

    // threads
    boost::thread jackal0_thread_;
    boost::thread jackal1_thread_;
    boost::thread jackal2_thread_;
    boost::thread jackal3_thread_;
    boost::thread jackal4_thread_;
    boost::thread jackal5_thread_;

    // thread execution functions
    void jackal0Loop(void);
    void jackal1Loop(void);
    void jackal2Loop(void);
    void jackal3Loop(void);
    void jackal4Loop(void);
    void jackal5Loop(void);
};

