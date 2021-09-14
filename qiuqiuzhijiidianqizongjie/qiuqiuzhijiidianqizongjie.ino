#include <ros.h>
#include <std_msgs/String.h>
#include <std_msgs/UInt16.h>
 
ros::NodeHandle nh;
 
 
void Control_erase(const std_msgs::UInt16& cmd_msg_erase)
{
  if(cmd_msg_erase.data == 1)
  
  {
      digitalWrite(26, HIGH);
  }
  if(cmd_msg_erase.data == 0)
  {
      digitalWrite(26, LOW);  
      
  }
 
}
void Control_rollandsweep(const std_msgs::UInt16& cmd_msg_rollandsweep)
{
  if(cmd_msg_rollandsweep.data == 1)
  
  {
      digitalWrite(28, HIGH);
  }
  if(cmd_msg_rollandsweep.data == 0)
  {
      digitalWrite(28, LOW);  
      
  }
 
}
void Control_fan(const std_msgs::UInt16& cmd_msg_fan)
{
  if(cmd_msg_fan.data == 1)
  
  {
      digitalWrite(30, HIGH);
  }
  if(cmd_msg_fan.data == 0)
  {
      digitalWrite(30, LOW);  
      
  }
 
}
void Control_upanddown(const std_msgs::UInt16& cmd_msg_upanddown)
{
  //if(cmd_msg_upanddown.data == 1)
  
  //{
   //   analogWrite(8, 220);
 // }
  //if(cmd_msg_upanddown.data == 0)
 // {
   //   analogWrite(8, 0);  
      
  //}
   analogWrite(8, cmd_msg_upanddown.data);  
 
}
void Control_stretch(const std_msgs::UInt16& cmd_msg_stretch)
{
  if(cmd_msg_stretch.data == 1)
  
  {
      digitalWrite(52, HIGH);
      digitalWrite(50, LOW);  
  }
  if(cmd_msg_stretch.data == 0)
  {
      digitalWrite(52, LOW);  
      digitalWrite(50, HIGH);
      
  }
 
}
ros::Subscriber <std_msgs::UInt16>  sub_erase("msg_erase", &Control_erase );
ros::Subscriber <std_msgs::UInt16>  sub_rollandsweep("msg_rollandsweep", &Control_rollandsweep );
ros::Subscriber <std_msgs::UInt16>  sub_fan("msg_fan", &Control_fan );
ros::Subscriber <std_msgs::UInt16>  sub_upanddown("msg_upanddown", &Control_upanddown );
ros::Subscriber <std_msgs::UInt16>  sub_stretch("msg_stretch", &Control_stretch );
 
void setup()
{
        pinMode(26, OUTPUT);
        pinMode(28, OUTPUT);
        pinMode(30, OUTPUT);
        pinMode(8, OUTPUT);
        pinMode(52, OUTPUT);
        pinMode(50, OUTPUT);
        Serial.begin(57600);
	nh.initNode();
	nh.subscribe(sub_erase);// subscribe 
        nh.subscribe(sub_rollandsweep);
        nh.subscribe(sub_fan);
        nh.subscribe(sub_upanddown);
        nh.subscribe(sub_stretch);
}
 
void loop()
{
	
	nh.spinOnce();
	delay(1000);
 
 
}
