# JoystickCarControl

We are using a KIA SOUL 2014 as our test car. More information can be found in our website(http://smartct.tamu.edu/index.html)

Steps to make the steering and trottle modules autonomous

1) Splice the blue and green wires in the steering and throttle module.
2) Connect the  blue wire from the throttle module to pin 13 and green wire to pin 12 of arduinno due to control the throtle.
3) Connect the green wire form steering module to pin 13 and blue wire to pin 12 of the arduino due to control the steering.
   For reference please have a look at the attached images.
4) Connect the joystick to the computer and copy paste the learn_joy folder to your "catkinworkspace/src/" 
5) run roscore
6) rosparam set joy_node/dev "/dev/input/js1"
7) In a new terminal rosrun joy joy_node
8) launch the required launch files by typing "roslaunch learning_joy turtle_joy.launch"
9) Upload the Arduino codes on corresponding arduinos by changing the port for each board.
10)Run "rosrun rosserial_python serial_node.py /dev/ttyACM0" & "rosrun rosserial_python serial_node1.py /dev/ttyACM1"


Now the car's steering and throttle module can be controlled using joystick.


