#include<SoftwareSerial.h>
#include <Servo.h>
SoftwareSerial bluetooth(12,13);   //rx==13,tx=12
Servo myservo0;
Servo myservo1;
Servo myservo3;
Servo myservo4;
int pos = 0;
int pos1=0;
int pos3=0;
int pos4=0; 
  

void setup() {  
  // put your setup code here, to run once:
bluetooth.begin(9600);
myservo0.attach(9);
myservo1.attach(11);
myservo3.attach(10);
myservo4.attach(3);
Serial.begin(9600);
Serial.println("pair with bluetooth");


}

void loop() {
  // put your main code here, to run repeatedly:
if(bluetooth.available())
{
  char ch=bluetooth.read();
  Serial.println("the charecter sent is bluethooth app is " + String(ch));
  if(String(ch)=="8")
  {
    
     pos=pos+5;
     if (pos<180)
      myservo0.write(pos);
     else
     myservo0.write(pos-5);
      
                   
    }
    else if(String(ch)=="2")
    {
      pos=pos-5;
      myservo0.write(pos);
    }
    else if(String(ch)=="E")
    {
      pos=0;
      pos1=90;
      pos4=45;
      
      myservo0.write(pos);
      myservo1.write(pos1);
      myservo4.write(pos4);
    }
    else if(String(ch)=="6")
    { 
     pos1=pos1+5;
      myservo1.write(pos1);
    }
  else if(String(ch)=="4")
  {
    pos1=pos1-5;
      myservo1.write(pos1);
  }
  else if(String(ch)=="C")
  {
     
    pos3=45;
      myservo3.write(pos3);
    
  }
  else if(String(ch)=="D")
  {
    pos3=0;
    myservo3.write(pos3);
  }
  else if(String(ch)=="X")
    { 
     pos4=pos4+10;
      myservo4.write(pos4);
    }
  else if(String(ch)=="Y")
  {
    pos4=pos4-10;
      myservo4.write(pos4);
  }
 
}
}
