#include "waypointmulti.h"

// constructor
CMultiJackal::CMultiJackal(const ros::NodeHandle &nh) : nh_(nh)
{
   
    // create threads for each Jackal
    jackal0_thread_ = boost::thread (&CMultiJackal::jackal0Loop, this);
    jackal1_thread_ = boost::thread (&CMultiJackal::jackal1Loop, this);
    jackal2_thread_ = boost::thread (&CMultiJackal::jackal2Loop, this);
    jackal3_thread_ = boost::thread (&CMultiJackal::jackal3Loop, this);
    jackal4_thread_ = boost::thread (&CMultiJackal::jackal4Loop, this);
    jackal5_thread_ = boost::thread (&CMultiJackal::jackal5Loop, this);
}

// destructor
CMultiJackal::~CMultiJackal(){
    jackal0_thread_.interrupt();
    jackal0_thread_.join();
    jackal1_thread_.interrupt();
    jackal1_thread_.join();
    jackal2_thread_.interrupt();
    jackal2_thread_.join();
    jackal3_thread_.interrupt();
    jackal3_thread_.join();
    jackal4_thread_.interrupt();
    jackal4_thread_.join();
    jackal5_thread_.interrupt();
    jackal5_thread_.join();
}

// jackal0 loop
void CMultiJackal::jackal0Loop(void)
{
    while (true)
    {             
        //tell the action client that we want to spin a thread by default
        MoveBaseClient ac("jackal0/move_base", true);
  
        //wait for the action server to come up
        while(!ac.waitForServer(ros::Duration(5.0))){
          ROS_INFO("Waiting for the move_base action server to come up");
        }

        move_base_msgs::MoveBaseGoal goal;

        goal.target_pose.header.frame_id = "jackal0/odom";
        goal.target_pose.header.stamp = ros::Time::now();
        float x[4], y[4];
        float z_[2] = {0.671, -0.741};
        float w_[2] = {0.734, 0.679};
        float z, w;
        bool flag = true;
        for(int i = 0; i < 4; i++)
        {
          x[i] =  0.5 - i ;
          if (flag) {z = z_[0]; w = w_[0];}
          else {z = z_[1]; w= w_[1];}
          for(int j = 0; j < 4; j++)
          {
            if (flag) {y[j] = 0.5 - j;}
            else {y[j] = 0.5 - j;}
            goal.target_pose.pose.position.y = y[j];
            goal.target_pose.pose.position.x = x[i]; 
            goal.target_pose.pose.orientation.z = z;
            goal.target_pose.pose.orientation.w = w;
            ROS_INFO("Sending goal");
            ac.sendGoal(goal);
            ac.waitForResult();
            if(ac.getState() == actionlib::SimpleClientGoalState::SUCCEEDED)
              ROS_INFO("Success");
            else
              ROS_INFO("Failure, possibly check quaternion");
            }
            flag = !flag;
         } 

        // sleep for 20 msec
        boost::this_thread::sleep_for (boost::chrono::milliseconds (10));
    }
}

// jackal1 loop
void CMultiJackal::jackal1Loop(void)
{
    while (true)
    {             
        //tell the action client that we want to spin a thread by default
        MoveBaseClient ac("jackal1/move_base", true);
  
        //wait for the action server to come up
        while(!ac.waitForServer(ros::Duration(5.0))){
          ROS_INFO("Waiting for the move_base action server to come up");
        }

        move_base_msgs::MoveBaseGoal goal;

        goal.target_pose.header.frame_id = "jackal1/odom";
        goal.target_pose.header.stamp = ros::Time::now();
        float x[4], y[4];
        float z_[2] = {0.671, -0.741};
        float w_[2] = {0.734, 0.679};
        float z, w;
        bool flag = true;
        for(int i = 0; i < 4; i++)
        {
          x[i] = 0.5 + i;
          if (flag) {z = z_[0]; w = w_[0];}
          else {z = z_[1]; w= w_[1];}
          for(int j = 0; j < 4; j++)
          {
            if (flag) {y[j] = 0.5 + j ;}
            else {y[j] = 0.5 + j;}
            goal.target_pose.pose.position.y = y[j];
            goal.target_pose.pose.position.x = x[i]; 
            goal.target_pose.pose.orientation.z = z;
            goal.target_pose.pose.orientation.w = w;
            ROS_INFO("Sending goal");
            ac.sendGoal(goal);
            ac.waitForResult();
            if(ac.getState() == actionlib::SimpleClientGoalState::SUCCEEDED)
              ROS_INFO("Success");
            else
              ROS_INFO("Failure, possibly check quaternion");
            }
            flag = !flag;
         } 

        // sleep for 20 msec
        boost::this_thread::sleep_for (boost::chrono::milliseconds (10));
    }
}

// jackal2 loop
void CMultiJackal::jackal2Loop(void)
{
    while (true)
    {             
        //tell the action client that we want to spin a thread by default
        MoveBaseClient ac("jackal2/move_base", true);
  
        //wait for the action server to come up
        while(!ac.waitForServer(ros::Duration(5.0))){
          ROS_INFO("Waiting for the move_base action server to come up");
        }

        move_base_msgs::MoveBaseGoal goal;

        goal.target_pose.header.frame_id = "jackal2/odom";
        goal.target_pose.header.stamp = ros::Time::now();
        float x[4], y[4];
        float z_[2] = {0.671, -0.741};
        float w_[2] = {0.734, 0.679};
        float z, w;
        bool flag = true;
        for(int i = 0; i < 4; i++)
        {
          x[i] = 0.5 + i ;
          if (flag) {z = z_[0]; w = w_[0];}
          else {z = z_[1]; w= w_[1];}
          for(int j = 0; j < 4; j++)
          {
            if (flag) {y[j] = 0.5 - j;}
            else {y[j] = 0.5 - j;}
            goal.target_pose.pose.position.y = y[j];
            goal.target_pose.pose.position.x = x[i]; 
            goal.target_pose.pose.orientation.z = z;
            goal.target_pose.pose.orientation.w = w;
            ROS_INFO("Sending goal");
            ac.sendGoal(goal);
            ac.waitForResult();
            if(ac.getState() == actionlib::SimpleClientGoalState::SUCCEEDED)
              ROS_INFO("Success");
            else
              ROS_INFO("Failure, possibly check quaternion");
            }
            flag = !flag;
         } 

        // sleep for 20 msec
        boost::this_thread::sleep_for (boost::chrono::milliseconds (10));
    }
}

// jackal3 loop
void CMultiJackal::jackal3Loop(void)
{
    while (true)
    {             
        //tell the action client that we want to spin a thread by default
        MoveBaseClient ac("jackal3/move_base", true);
 
        //wait for the action server to come up
        while(!ac.waitForServer(ros::Duration(5.0))){
          ROS_INFO("Waiting for the move_base action server to come up");
        }

        move_base_msgs::MoveBaseGoal goal;

        goal.target_pose.header.frame_id = "jackal3/odom";
        goal.target_pose.header.stamp = ros::Time::now();
        float x[4], y[4];
        float z_[2] = {0.671, -0.741};
        float w_[2] = {0.734, 0.679};
        float z, w;
        bool flag = true;
        for(int i = 0; i < 4; i++)
        {
          x[i] = 0.5 - i;
          if (flag) {z = z_[0]; w = w_[0];}
          else {z = z_[1]; w= w_[1];}
          for(int j = 0; j < 4; j++)
          {
            if (flag) {y[j] = 0.5 + j ;}
            else {y[j] = 0.5 + j ;}
            goal.target_pose.pose.position.y = y[j];
            goal.target_pose.pose.position.x = x[i]; 
            goal.target_pose.pose.orientation.z = z;
            goal.target_pose.pose.orientation.w = w;
            ROS_INFO("Sending goal");
            ac.sendGoal(goal);
            ac.waitForResult();
            if(ac.getState() == actionlib::SimpleClientGoalState::SUCCEEDED)
              ROS_INFO("Success");
            else
              ROS_INFO("Failure, possibly check quaternion");
            }
            flag = !flag;
         } 

        // sleep for 20 msec
        boost::this_thread::sleep_for (boost::chrono::milliseconds (10));
    }
}

// jackal4 loop
void CMultiJackal::jackal4Loop(void)
{
    while (true)
    {             
        //tell the action client that we want to spin a thread by default
        MoveBaseClient ac("jackal4/move_base", true);
  
        //wait for the action server to come up
        while(!ac.waitForServer(ros::Duration(5.0))){
          ROS_INFO("Waiting for the move_base action server to come up");
        }

        move_base_msgs::MoveBaseGoal goal;

        goal.target_pose.header.frame_id = "jackal4/odom";
        goal.target_pose.header.stamp = ros::Time::now();
        float x[4], y[4];
        float z_[2] = {0.671, -0.741};
        float w_[2] = {0.734, 0.679};
        float z, w;
        bool flag = true;
        for(int i = 0; i < 4; i++)
        {
          x[i] = i + 0.5  ;
          if (flag) {z = z_[0]; w = w_[0];}
          else {z = z_[1]; w= w_[1];}
          for(int j = 0; j < 4; j++)
          {
            if (flag) {y[j] = j - 0.5;}
            else {y[j] = j - 0.5;}
            goal.target_pose.pose.position.y = y[j];
            goal.target_pose.pose.position.x = x[i]; 
            goal.target_pose.pose.orientation.z = z;
            goal.target_pose.pose.orientation.w = w;
            ROS_INFO("Sending goal");
            ac.sendGoal(goal);
            ac.waitForResult();
            if(ac.getState() == actionlib::SimpleClientGoalState::SUCCEEDED)
              ROS_INFO("Success");
            else
              ROS_INFO("Failure, possibly check quaternion");
            }
            flag = !flag;
         } 

        // sleep for 20 msec
        boost::this_thread::sleep_for (boost::chrono::milliseconds (10));
    }
}

// jackal5 loop
void CMultiJackal::jackal5Loop(void)
{
    while (true)
    {             
        //tell the action client that we want to spin a thread by default
        MoveBaseClient ac("jackal5/move_base", true);
  
        //wait for the action server to come up
        while(!ac.waitForServer(ros::Duration(5.0))){
          ROS_INFO("Waiting for the move_base action server to come up");
        }

        move_base_msgs::MoveBaseGoal goal;

        goal.target_pose.header.frame_id = "jackal5/odom";
        goal.target_pose.header.stamp = ros::Time::now();
        float x[4], y[4];
        float z_[2] = {0.671, -0.741};
        float w_[2] = {0.734, 0.679};
        float z, w;
        bool flag = true;
        for(int i = 0; i < 4; i++)
        {
          x[i] = 0.5 - i - 1;
          if (flag) {z = z_[0]; w = w_[0];}
          else {z = z_[1]; w= w_[1];}
          for(int j = 0; j < 4; j++)
          {
            if (flag) {y[j] = 0.5 + j - 1;}
            else {y[j] = 0.5 + j - 1;}
            goal.target_pose.pose.position.y = y[j];
            goal.target_pose.pose.position.x = x[i]; 
            goal.target_pose.pose.orientation.z = z;
            goal.target_pose.pose.orientation.w = w;
            ROS_INFO("Sending goal");
            ac.sendGoal(goal);
            ac.waitForResult();
            if(ac.getState() == actionlib::SimpleClientGoalState::SUCCEEDED)
              ROS_INFO("Success");
            else
              ROS_INFO("Failure, possibly check quaternion");
            }
            flag = !flag;
         } 

        // sleep for 20 msec
        boost::this_thread::sleep_for (boost::chrono::milliseconds (10));
    }
}


int main(int argc, char** argv){
  ros::init(argc, argv, "jackal_navigation_goals");

  ros::NodeHandle nh_;
  //run
  CMultiJackal sensor(nh_);
  
  ros::spin();

  return 0;
}
