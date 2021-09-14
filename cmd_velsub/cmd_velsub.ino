#include <ros.h>
#include <std_msgs/String.h>
#include <std_msgs/UInt16.h>
#include<tf/transform_broadcaster.h>
#include<nav_msgs/Odometry.h>
#include<geometry_msgs/Twist.h>


ros::NodeHandle nh;
 
 
void Control(const geometry_msgs::Twist& cmd_vel)
{

  Serial.println(cmd_vel.linear.x);
  Serial.println(cmd_vel.angular.z);

 
}
 
ros::Subscriber <geometry_msgs::Twist>  sub("cmd_vel", &Control );
 

 
 
 
 
void setup()
{
       
	nh.initNode();
	nh.subscribe(sub);// subscribe 
        Serial.begin(57600);
}
 
void loop()
{
	
	nh.spinOnce();
	delay(1000);
 
 
}
