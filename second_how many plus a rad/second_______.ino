

double plusQ1=0;







void setup() {
  




 //中断-速度反馈

attachInterrupt(1,getplusQ1,RISING);//Q1

 
 Serial.begin(9600);
  
}
 
   

void loop() {
  Serial.println(plusQ1);


    
}





 void getplusQ1()
{
  plusQ1++;
  
  }

  
