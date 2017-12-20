#include <ros/ros.h>
#include <geometry_msgs/Twist.h>
#include <sensor_msgs/Joy.h>


class TeleopTurtle
{
public:
  TeleopTurtle();

private:
  void joyCallback(const sensor_msgs::Joy::ConstPtr& joy);

  ros::NodeHandle nh_,n1;

  int linear_, angular_,linear1_, angular1_;;
  double l_scale_, a_scale_, b_scale_, d_scale_;
  ros::Publisher vel_pub_;
  ros::Publisher vel_pub1_;
  ros::Subscriber joy_sub_;

};


TeleopTurtle::TeleopTurtle():
  linear_(1),
  angular_(2),
 linear1_(4),
  angular1_(4)
{

  nh_.param("axis_linear", linear_, linear_);
  nh_.param("axis_angular", angular_, angular_);
   nh_.param("scale_angular", a_scale_, a_scale_);
  nh_.param("scale_linear", l_scale_, l_scale_);

nh_.param("axis_lin", linear1_, linear1_);
  nh_.param("axis_ang", angular1_, angular1_);
   nh_.param("scale_angular", b_scale_, b_scale_);
  nh_.param("scale_linear", d_scale_, d_scale_);


n1.param("axis_linear", linear_, linear_);
  n1.param("axis_angular", angular_, angular_);
   n1.param("scale_angular", a_scale_, a_scale_);
  n1.param("scale_linear", l_scale_, l_scale_);

n1.param("axis_lin", linear1_, linear1_);
  n1.param("axis_ang", angular1_, angular1_);
   n1.param("scale_angular", b_scale_, b_scale_);
  n1.param("scale_linear", d_scale_, d_scale_);




  vel_pub_ = nh_.advertise<geometry_msgs::Twist>("joy_vel", 1);
vel_pub1_ = n1.advertise<geometry_msgs::Twist>("joy_vel1", 1);


  joy_sub_ = nh_.subscribe<sensor_msgs::Joy>("joy", 10, &TeleopTurtle::joyCallback, this);

}

void TeleopTurtle::joyCallback(const sensor_msgs::Joy::ConstPtr& joy)
{
  geometry_msgs::Twist twist;
double k,l;
double q,w;
int st_13=3088;
int st_12=3088;
int th_12=804;


k=-a_scale_*joy->axes[angular_];
//l=-l_scale_*joy->axes[linear_];

w=d_scale_*joy->axes[linear1_];

//angular is left/right
//linear is front/back

  twist.angular.x = st_13 + k/(.002857*1.5);
  twist.angular.y = st_12 - k/(.002857*1.5);
 twist.linear.x = th_12 + (w)/0.0025;
twist.linear.y = (th_12 + (w)/0.0025)/2;
   
    vel_pub_.publish(twist);
 vel_pub1_.publish(twist);
}


int main(int argc, char** argv)
{
  ros::init(argc, argv, "teleop_turtle");
  TeleopTurtle teleop_turtle;

  ros::spin();
}
