# Controlling_robatic_arm_with_2servos

How the Circuit works?

Arduino controls the robtaic arm via two servo motors, and to operate the servo motors, you should insert two values of angles - One for each servo motor. 
The inputs of the angles could be via several ways such as keybad or control panel. 

Code explanation: 

Controlling servo motors should be done by declaring the library of servo and the pins that connected to each servo, and then name each servo to be easily coding after that.

#include <Servo.h>
int servoPin1 = 3; 
int servoPin2 = 4; 
Servo Servo1; 
Servo Servo2; 

To use the forward or inverse kinematics, we should define the inputs, which are Link 1 length (L1), Link 2 lenght (L2). 
Then determine which kinematics to use (forward or inverse).
Inputs for forward: angle 1 (Q1) and angle 2 (Q2). 

   double Q1d = 30;   // in degrees
   double Q2d = 60;   // in degrees
   
Inputs for reverse: distance in x-axis (x), distance in y-axis (y), and angle of link 2 with x-axis (Q). 

   double x = 0.15;   // in meters
   double y = 0.09;   // in meters
   double Q = 60;     // in degrees
   
Use the equations to find the values, but you should know that sine and cosine functions deal with angles in radian in Arduino codes. so you have to convert before using them:
   
   double Q1 = Q1d*(0.0174533); //convert from degrees to radians
   double Q2 = Q2d*(0.0174533);
   
   double Q2d= Q2*(57.29578); //convert from radians to degrees

To use the kinematic equations in Arduino codes:

//inverse kinematic 
   double Q2 = acos((pow(x,2)+(pow(y,2))-(pow(L1,2))-(pow(L2,2)))/(2*L1*L2))
   double Q1=Q-Q2d; 
   
//inverse kinematic 
   double x = (L1*cos(Q1))+(L2*cos(Q1+Q2));
   double y = (L1*sin(Q1))+(L2*sin(Q1+Q2));
   double Q=Q1d+Q2d; 
