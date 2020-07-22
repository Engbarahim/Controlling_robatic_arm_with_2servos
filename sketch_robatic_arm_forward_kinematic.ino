#include <Servo.h>

// Declare the Servo pins 
int servoPin1 = 3; 
int servoPin2 = 4; 

// Create a servo object 
Servo Servo1; 
Servo Servo2; 


void setup() {
   Servo1.attach(servoPin1);
   Servo2.attach(servoPin2);
   Servo1.write(0);
   Servo2.write(0);
   Serial.begin(9600);

}

void loop() {
  //given (input)
  
   double L1 = 0.15;  // in meters
   double L2 = 0.1;  // in meters
   double Q1d = 30;   // in degrees
   double Q2d = 60;   // in degrees
  

   //forward kinematic 
   double Q1 = Q1d*(0.0174533); //convert from degrees to radians
   double Q2 = Q2d*(0.0174533); //convert from degrees to radians
   double x = (L1*cos(Q1))+(L2*cos(Q1+Q2));
   double y = (L1*sin(Q1))+(L2*sin(Q1+Q2));
   double Q=Q1d+Q2d; 

   Serial.println(Q1,DEC);
   Serial.println(Q2,DEC);
   Serial.println(x,DEC);
   Serial.println(y,DEC);
   Serial.println(Q);

   Servo1.write(Q1d);
   Servo2.write(Q2d); 
   delay(1000); 

}
