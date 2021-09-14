#include <FlexiTimer2.h>



double plus_left=0;
double speed_left;

int left_z=22;
int left_En=4;
int left_f=24;
double plus_right=0;
double speed_right;

int right_z=48;
int right_En=12;
int right_f=46;


void setup() {
  
 attachInterrupt(0,getplus_left,RISING);//Q1
attachInterrupt(1,getplus_right,RISING);//Q1

 FlexiTimer2::set(100, get_speed);
 
 FlexiTimer2::start();
 Serial.begin(9600); //电机驱动 
 pinMode(left_z, OUTPUT);
 pinMode(left_En, OUTPUT);
 pinMode(left_f, OUTPUT);
 pinMode(right_z, OUTPUT);
 pinMode(right_En, OUTPUT);
 pinMode(right_f, OUTPUT);
 Serial.begin(9600);

}
 
   

void loop() {
  

     analogWrite(left_En,100);
     digitalWrite(left_z, HIGH);
     digitalWrite(left_f, LOW); 
     

     analogWrite(right_En,100);
     digitalWrite(right_z, HIGH);
     digitalWrite(right_f, LOW);
}
void get_speed()
  {
     speed_left=plus_left/260*60*10;
     plus_left=0;
     speed_right=plus_right/260*60*10;
     plus_right=0;
     
     Serial.println(speed_right);
     Serial.println(speed_left);

     
     
    }




void getplus_left()
{
  plus_left++;
  }
void getplus_right()
{
  plus_right++;
  }
