#include <FlexiTimer2.h>
#include <ros.h>
#include <std_msgs/String.h>
#include <std_msgs/UInt16.h>
#include<tf/transform_broadcaster.h>
#include<nav_msgs/Odometry.h>
#include<geometry_msgs/Twist.h>
#include <PID_v1.h>
double Setpoint_left, Input_left, Output_left;
PID myPID_left(&Input_left, &Output_left, &Setpoint_left,0.8,5,0, DIRECT);
double Setpoint_right, Input_right, Output_right;
PID myPID_right(&Input_right, &Output_right, &Setpoint_right,0.8,5,0, DIRECT);

double plus_left=0;
double speed_left;
int left_z=22;
int left_En=11;
int left_f=24;

double plus_right=0;
double speed_right;
int right_z=48;
int right_En=12;
int right_f=46;

ros::NodeHandle nh;

void Control(const geometry_msgs::Twist& cmd_vel)
{
  
  Setpoint_left = cmd_vel.linear.x - cmd_vel.angular.z * 0.4 / 2.0;
  Setpoint_right = cmd_vel.linear.x + cmd_vel.angular.z * 0.4 / 2.0;
  Setpoint_left=Setpoint_left*100*60/22.5;
  Setpoint_right=Setpoint_right*100*60/22.5;

}

ros::Subscriber <geometry_msgs::Twist>  sub("turtle1/cmd_vel", &Control );

void setup() {
 Serial.begin(57600);
  //电机驱动 
 pinMode(left_z, OUTPUT);
 pinMode(left_En, OUTPUT);
 pinMode(left_f, OUTPUT);
 pinMode(right_z, OUTPUT);
 pinMode(right_En, OUTPUT);
 pinMode(right_f, OUTPUT);


 //中断-速度反馈

attachInterrupt(4,getplus_left,RISING);//Q1
attachInterrupt(5,getplus_right,RISING);//Q1

 FlexiTimer2::set(100, get_speed);
 
 FlexiTimer2::start();
 
 Input_left = speed_left;
 Input_right = speed_right;
 myPID_left.SetSampleTime(100);
 myPID_right.SetSampleTime(100);

 myPID_left.SetMode(AUTOMATIC);
 myPID_right.SetMode(AUTOMATIC); 
 nh.initNode();
 nh.subscribe(sub);// subscribe 
 
}
 
   

void loop() {
  
     Input_left = speed_left;
     myPID_left.Compute();

     analogWrite(left_En,Output_left);
     digitalWrite(left_z, HIGH);
     digitalWrite(left_f, LOW); 
     
     Input_right = speed_right;
     myPID_right.Compute();

     analogWrite(right_En,Output_right);
     digitalWrite(right_z, HIGH);
     digitalWrite(right_f, LOW);
     nh.spinOnce();
     delay(100);
}

void get_speed()
  {
     speed_left=plus_left/260*60*10;
     plus_left=0;
     speed_right=plus_right/260*60*10;
     plus_right=0;

   
     
    }




void getplus_left()
{
  plus_left++;
  }
void getplus_right()
{
  plus_right++;
  }
  
  
  




 
 

 

 

 
 
