#include <Servo.h> //includes the Servo library 

Servo myServo;  // create servo object to control a servo
const int trigPin = 10; //assign variable for pins on arduino
const int echoPin = 11;

long duration;
int distance;
int i = 0;    // variable to store the servo position

void setup() {
  myServo.attach(9);// attaches the servo on pin 9 to the servo object
  Serial.begin(9600);// initializing the serial port 9600
  
  //pinMode specifies which pin act as INPUT or OUTPUT
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  myServo.write(0); //write angle 0 to servo
}

void loop() {
  
  for (i = 0; i <= 180; i += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myServo.write(i);              // tell servo to go to position in variable 'pos'
    delay(50);
    distance = calcDist();
    Serial.print(i);//send current deg to serial port
    Serial.print(",");
    Serial.print(distance);//send distance val to s p
    Serial.print(".");
  }
  for (i = 180; i >= 0; i -= 1) { // goes from 180 degrees to 0 degrees
    myServo.write(i);              // tell servo to go to position in variable 'pos'
    delay(50);// waits 15ms for the servo to reach the position
    distance = calcDist();
    Serial.print(i);//send current deg to serial port
    Serial.print(",");
    Serial.print(distance);//send distance val to s p
    Serial.print(".");
  }
}

int calcDist()
{
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = duration*0.034/2;
  return distance;
}

