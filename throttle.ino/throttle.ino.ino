#define USE_USBCON
#include <ros.h>
#include <geometry_msgs/Twist.h>
//prev val 804,372
/*int pwm12 = 804; //800 works decently
int pwm13 = 453;*/

double x,y;

ros::NodeHandle raichu;

void velCallback1( const geometry_msgs::Twist& vel)
{ x = vel.linear.x ; 
  y = vel.linear.y;
 
  
 }

ros::Subscriber<geometry_msgs::Twist> sub1("joy_vel" , velCallback1);

void setup() { 
  Serial.begin(57600);
  
  pinMode(13,OUTPUT);
  pinMode(12,OUTPUT);
  raichu.initNode(); raichu.subscribe(sub1); }

void loop() {
  
 
  raichu.spinOnce();
analogWriteResolution(12);
  analogWrite(12, x);  ////green wire
analogWriteResolution(12);
  analogWrite(13,y); ///blue wire
Serial.println(x);
Serial.println(y);
delay(10); }





