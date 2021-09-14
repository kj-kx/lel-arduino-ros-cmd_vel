#include <FlexiTimer2.h>

#include <PID_v1.h>
double Setpointq1, Inputq1, Outputq1;
PID myPIDq1(&Inputq1, &Outputq1, &Setpointq1,0.7,16,0, DIRECT);


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
 Inputq1 = speedQ1;
 myPIDq1.SetSampleTime(100);
 Setpointq1 = 45;
 myPIDq1.SetMode(AUTOMATIC);
  
}
 
   

void loop() {
     Inputq1 = speedQ1;
     myPIDq1.Compute();
     analogWrite(QEn1,Outputq1);
     digitalWrite(QI1Z, HIGH);
     digitalWrite(QI1f, LOW); 
}


void get_speed()
  {
     speedQ1=plusQ1/260*60*10;
     plusQ1=0;
     
     Serial.println(speedQ1);

     
     
    }




 void getplusQ1()
{
  plusQ1++;
  }
