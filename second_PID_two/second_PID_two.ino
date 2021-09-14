#include <FlexiTimer2.h>

#include <PID_v1.h>
double Setpoint_left, Input_left, Output_left;
PID myPID_left(&Input_left, &Output_left, &Setpoint_left,0.8,5,0, DIRECT);
double Setpoint_right, Input_right, Output_right;
PID myPID_right(&Input_right, &Output_right, &Setpoint_right,0.8,5,0, DIRECT);

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
  
  //电机驱动 
 pinMode(left_z, OUTPUT);
 pinMode(left_En, OUTPUT);
 pinMode(left_f, OUTPUT);
 pinMode(right_z, OUTPUT);
 pinMode(right_En, OUTPUT);
 pinMode(right_f, OUTPUT);


 //中断-速度反馈

attachInterrupt(0,getplus_left,RISING);//Q1
attachInterrupt(1,getplus_right,RISING);//Q1

 FlexiTimer2::set(100, get_speed);
 
 FlexiTimer2::start();
 Serial.begin(9600);
 Input_left = speed_left;
 Input_right = speed_right;
 myPID_left.SetSampleTime(100);
 myPID_right.SetSampleTime(100);
 Setpoint_left = 10;
 Setpoint_right = 10;
 myPID_left.SetMode(AUTOMATIC);
 myPID_right.SetMode(AUTOMATIC); 
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
