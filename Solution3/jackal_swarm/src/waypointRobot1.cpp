//required includes
#include <ros/ros.h>
#include <iostream>
#include <move_base_msgs/MoveBaseAction.h>
#include <actionlib/client/simple_action_client.h>

typedef actionlib::SimpleActionClient<move_base_msgs::MoveBaseAction> MoveBaseClient;

//int x[15] = { 0, 0, 0, 1, 1, 1, 1, 2, 2, 2, 2, 3, 3, 3, 3}; 
//int y[15] = {1, 2, 3, 3, 2, 1, 0, 0, 1, 2, 3, 3, 2, 1, 0};
//float z[5] = {0, 0.47, 0.78, 1, -0.81};

//int lenght0fWaypoints= 15;


int main(int argc, char** argv){
  ros::init(argc, argv, "simple_navigation_goals");
  float x[9];
  float y[9];
  float initX = 0.5;
  float initY = 0.5;
  float z_[2] = {0.671, -0.741};
  float w_[2] = {0.734, 0.679};
  float z, w;
  bool flag = true;

  //tell the action client that we want to spin a thread by default
   MoveBaseClient ac("move_base", true);

  //wait for the action server to come up
   while(!ac.waitForServer(ros::Duration(5.0))){
     ROS_INFO("Waiting for the move_base action server to come up");
   }

move_base_msgs::MoveBaseGoal goal;

goal.target_pose.header.frame_id = "odom";
goal.target_pose.header.stamp = ros::Time::now();
for(int i = 0; i < 10; i++)
  {
    x[i] = initX + i;
    if (flag) {z = z_[0]; w = w_[0];}
    else {z = z_[1]; w= w_[1];}
    for(int j = 0; j < 10; j++)
    {
      if (flag) {y[j] = initY + j;}
      else {y[j] = initY + 9 -j;}
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
  return 0;
}
