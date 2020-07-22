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
   double x = 0.15;   // in meters
   double y = 0.09;   // in meters
   double Q = 60;     // in degrees

   //inverse kinematic 
   double Q2 = acos((pow(x,2)+(pow(y,2))-(pow(L1,2))-(pow(L2,2)))/(2*L1*L2));
   double Q2d= Q2*(180*113/355); //convert from radians to degrees
   double Q1=Q-Q2d; 
   
   Serial.println(Q2);
   Serial.println(Q2d);
   Serial.println(Q1);

   Servo1.write(Q1);
   Servo2.write(Q2d); 
   delay(1000); 

}
