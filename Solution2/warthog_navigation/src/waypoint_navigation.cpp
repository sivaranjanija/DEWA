//required includes
#include <ros/ros.h>
#include <iostream>
#include <move_base_msgs/MoveBaseAction.h>
#include <actionlib/client/simple_action_client.h>


typedef actionlib::SimpleActionClient<move_base_msgs::MoveBaseAction> MoveBaseClient;

int x[5] = { -4, 2, 4, 2, 4}; 
int y[5] = {-4, -4, 0 , 4, 4};
//float z[5] = {0, 0.47, 0.78, 1, -0.81};
float w[5] = {1, 1, 1, 1, 1};

int lenght0fWaypoints = 5;

int main(int argc, char** argv)
{
  ros::init(argc, argv, "waypointnavigationgoals");

  MoveBaseClient ac("move_base", true);

  //wait for the action server to come up
  while(!ac.waitForServer(ros::Duration(5.0)))
  {
    ROS_INFO("Waiting for the move_base action server to come up");
  }

  move_base_msgs::MoveBaseGoal goal;

  goal.target_pose.header.frame_id = "odom";
  goal.target_pose.header.stamp = ros::Time::now();
  for( int i = 0; i < lenght0fWaypoints; i = i + 1 ) 
  {
    goal.target_pose.pose.position.x = x[i];
    goal.target_pose.pose.position.y = y[i];
    //goal.target_pose.pose.orientation.z = z[i];
    goal.target_pose.pose.orientation.w = w[i];
    ROS_INFO("Sending goal");
    ac.sendGoal(goal);

    ac.waitForResult();
 
    if(ac.getState() == actionlib::SimpleClientGoalState::SUCCEEDED)
      ROS_INFO("Success");
    else
      ROS_INFO("Failure");
  }
  return 0;
}
