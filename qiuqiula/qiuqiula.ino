#include <FlexiTimer2.h>





int left_z=22;
int left_En=4;
int left_f=24;


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







