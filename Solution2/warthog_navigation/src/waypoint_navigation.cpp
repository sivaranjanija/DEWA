//required includes
#include <ros/ros.h>
#include <iostream>
#include <move_base_msgs/MoveBaseAction.h>
#include <actionlib/client/simple_action_client.h>


typedef actionlib::SimpleActionClient<move_base_msgs::MoveBaseAction> MoveBaseClient;

float x[6] = {1.5, 5, 8, 5, 1.5, 0}; 
float y[6] = {1.5, 1.5, 5 , 8.5, 8.5, 5};
float z[6] = {0.267, 0.730, 0.955, 0.947, -0.758, -0.327};
float w[6] = {0.964, 0.683, 0.296, -0.320, 0.652, 0.945};
int lenght0fWaypoints = 6;

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
  for(int numTimes = 0; numTimes < 2; numTimes++)
  {
    for( int i = 0; i < lenght0fWaypoints; i = i + 1 ) 
    {
      goal.target_pose.pose.position.x = x[i];
      goal.target_pose.pose.position.y = y[i];
      goal.target_pose.pose.orientation.z = z[i];
      goal.target_pose.pose.orientation.w = w[i];
      ROS_INFO("Sending goal");
      ac.sendGoal(goal);

      ac.waitForResult();
 
      if(ac.getState() == actionlib::SimpleClientGoalState::SUCCEEDED)
        ROS_INFO("Success");
      else
        ROS_INFO("Failure");
    }
  }
  return 0;
}
