#include <FlexiTimer2.h>

double plusQ1=0;
double speedQ1;



int QI1Z=51;
int QEn1=6;
int QI1f=53;


void setup() {
  
  //电机驱动 
 pinMode(QI1Z, OUTPUT);
 pinMode(QEn1, OUTPUT);
 pinMode(QI1f, OUTPUT);




 //中断-速度反馈

attachInterrupt(0,getplusQ1,RISING);//Q1

 
 FlexiTimer2::set(100, get_speed);
 FlexiTimer2::start();
 Serial.begin(9600);
  
}
 
   

void loop() {
  
     digitalWrite(QI1Z,HIGH);
     analogWrite(QEn1, int((10/12)*255));
     digitalWrite(QI1f, LOW); 

    
}


void get_speed()
  {
     speedQ1=plusQ1/260*60*10;
     plusQ1=0;

     Serial.println(speedQ1);
     Serial.println("rad/min");

    }


 void getplusQ1()
{
  plusQ1++;
  }

  
