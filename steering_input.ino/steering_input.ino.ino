#define USE_USBCON
#include <ros.h>
#include <geometry_msgs/Twist.h>
/*
int pwm13 = 3088;
int pwm12 = 3088; 
int f = 0;
*/
double x,y;
ros::NodeHandle pikachu;

void velCallback2( const geometry_msgs::Twist& vel)
{ x = vel.angular.x ; 
  y = vel.angular.y ;
  
  }

ros::Subscriber<geometry_msgs::Twist> sub("joy_vel" , velCallback2);

void setup() { 
  Serial.begin(57600);
  
  
  pikachu.initNode(); pikachu.subscribe(sub); 
  pinMode(13,OUTPUT);
  pinMode(12,OUTPUT);}

void loop() {pikachu.spinOnce();
 analogWriteResolution(12);
  analogWrite(12,x);
analogWriteResolution(12);
  analogWrite(13,y);
Serial.println(x);
Serial.println(y);
delay(10); }





