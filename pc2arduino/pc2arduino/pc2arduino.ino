#include <ros.h>
#include <std_msgs/String.h>
#include <std_msgs/UInt16.h>
 
ros::NodeHandle nh;
 
 
void Control(const std_msgs::UInt16& cmd_msg)
{
  if(cmd_msg.data == 1)
  
  {
      Serial.println("COM is ready");
  }
  if(cmd_msg.data == 0)
  {
      digitalWrite(13, HIGH);  
      Serial.println("aaaaaa");
  }
 
}
 
ros::Subscriber <std_msgs::UInt16>  sub("PC2Arduino", &Control );
 

 
 
 
 
void setup()
{
        Serial.begin(57600);
	nh.initNode();
	nh.subscribe(sub);// subscribe 
 
}
 
void loop()
{
	
	nh.spinOnce();
	delay(1000);
 
 
}
