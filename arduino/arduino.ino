//MOTOR 1 and 2 PINS
int ena = 5;
int in1 = 6;
int in2 = 7;
int in3 = 8;
int in4 = 9;
int enb = 10;


//PIR Sensor
const int led = 1; // Led positive terminal to the digital pin 9.             
const  int sensor = 2; // signal pin of sensor to digital pin 5.                        
int val;                


//ultrasonic sensor right
const int trigPin = 11;
const int echoPin = 12;
float duration, distance;


//ultrasonic sensor left
const int trigPinL = 4;
const int echoPinL = 3;
float durationL, distanceL;


void setup() {
Serial.begin(9600);


 //PIR Sensor
 pinMode(led, OUTPUT); // Led is determined as an output here.   
 pinMode(sensor, INPUT); // PIR motion sensor is determined is an input here. 


//ultrasonic sensor right
pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT);


//ultrasonic sensor left
pinMode(trigPinL, OUTPUT);
pinMode(echoPinL, INPUT);


// DC motor with L298N driver
pinMode(ena, OUTPUT);
pinMode(in1, OUTPUT);
pinMode(in2, OUTPUT);
pinMode(enb, OUTPUT);
pinMode(in3, OUTPUT);
pinMode(in4, OUTPUT);


// turn all motors off
digitalWrite(in1,LOW);
digitalWrite(in2,LOW);
digitalWrite(in3,LOW);
digitalWrite(in4,LOW);


// start rotating after not detecting any movements
unsigned long startTime = millis(); // Record the start time
while (millis() - startTime < 20000) { // Run the loop for 10 seconds
 Serial.println("No human detected...");


 // right ultrasonic sensor
 digitalWrite(trigPin, LOW);
 delayMicroseconds(2);
 digitalWrite(trigPin, HIGH);
 delayMicroseconds(10);
 digitalWrite(trigPin, LOW);
 duration = pulseIn(echoPin, HIGH);
 distance = (duration*.0343)/2;
 Serial.print("Distance Right: ");
 Serial.println(distance);


 // left ultrasonic sensor
 digitalWrite(trigPinL, LOW);
 delayMicroseconds(2);
 digitalWrite(trigPinL, HIGH);
 delayMicroseconds(10);
 digitalWrite(trigPinL, LOW);
 durationL = pulseIn(echoPinL, HIGH);
 distanceL = (durationL*.0343)/2;
 Serial.print("Distance Left: ");
 Serial.println(distanceL);
 if(distance < 40){ // right ultrasonic sensor
  digitalWrite(in1,HIGH);
  digitalWrite(in2,LOW);
  digitalWrite(in3,LOW);
  digitalWrite(in4,LOW);
  analogWrite(ena, 120);
  analogWrite(enb, 120);
  delay(250);
 }else if(distanceL < 40){
  digitalWrite(in1,LOW);
  digitalWrite(in2,LOW);
  digitalWrite(in3,HIGH);
  digitalWrite(in4,LOW);
  analogWrite(ena, 120);
  analogWrite(enb, 120);
  delay(250);
 }else{
  digitalWrite(in1,HIGH);
  digitalWrite(in2,LOW);
  digitalWrite(in3,HIGH);
  digitalWrite(in4,LOW);
  analogWrite(ena, 120);
  analogWrite(enb, 120);
  delay(250);
 }
}


//PIR Sensor detection testing
  //MOTOR_A CLOCKWISE MAX SPEED // rotate first
  digitalWrite(in1,HIGH);
  digitalWrite(in2,LOW);
  digitalWrite(in3,LOW);
  digitalWrite(in4,HIGH);
  analogWrite(ena, 60);
  analogWrite(enb, 60);
  delay(5000);
while(digitalRead(sensor) == LOW){ // while human not found, rotates
  //MOTOR_A CLOCKWISE MAX SPEED
  digitalWrite(in1,HIGH);
  digitalWrite(in2,LOW);
  digitalWrite(in3,LOW);
  digitalWrite(in4,HIGH);
  analogWrite(ena, 60);
  analogWrite(enb, 60);
}


// now the direction is correct, moving towards detected human
distance = 30.0;
distanceL = 30.0;
while(distance > 25 || distanceL > 25){
 // right ultrasonic sensor
 digitalWrite(trigPin, LOW);
 delayMicroseconds(2);
 digitalWrite(trigPin, HIGH);
 delayMicroseconds(10);
 digitalWrite(trigPin, LOW);
 duration = pulseIn(echoPin, HIGH);
 distance = (duration*.0343)/2;
 Serial.print("Distance Right: ");
 Serial.println(distance);


 // left ultrasonic sensor
 digitalWrite(trigPinL, LOW);
 delayMicroseconds(2);
 digitalWrite(trigPinL, HIGH);
 delayMicroseconds(10);
 digitalWrite(trigPinL, LOW);
 durationL = pulseIn(echoPinL, HIGH);
 distanceL = (durationL*.0343)/2;
 Serial.print("Distance Left: ");
 Serial.println(distanceL);


  digitalWrite(in1,HIGH);
  digitalWrite(in2,LOW);
  digitalWrite(in3,HIGH);
  digitalWrite(in4,LOW);
  analogWrite(ena, 100);
  analogWrite(enb, 100);
}


Serial.println("Yes human detected...");
  digitalWrite(in1,LOW);
  digitalWrite(in2,LOW);
  digitalWrite(in3,LOW);
  digitalWrite(in4,LOW);


 unsigned long startTime2 = millis(); // Record the start time
 while (millis() - startTime2 < 10000) { // Run the loop for 10 seconds
  digitalWrite(led, HIGH);
  delay(1000);
  digitalWrite(led, LOW);
  delay(1000);
 }


//  while(1){ // while human not found, rotates
//    //MOTOR_A CLOCKWISE MAX SPEED
//    digitalWrite(in1,HIGH);
//    digitalWrite(in2,LOW);
//    digitalWrite(in3,LOW);
//    digitalWrite(in4,HIGH);
//    analogWrite(ena, 100);
//    analogWrite(enb, 100);
//  }


// //MOTOR_A CLOCKWISE MAX SPEED
// digitalWrite(in1,HIGH);
// digitalWrite(in2,LOW);
// analogWrite(enb, 60);
// //MOTOR_B CLOCKWISE MAX SPEED
// digitalWrite(in3,HIGH);
// digitalWrite(in4,LOW);
// analogWrite(enb, 60);
// delay(2000);


// //STOP
// digitalWrite(in1,LOW);
// digitalWrite(in2,LOW);
// digitalWrite(in3,LOW);
// digitalWrite(in4,LOW);
// delay(2000);


// //MOTOR_A COUNTERCLOCKWISE MAX SPEED
// digitalWrite(in1,LOW);
// digitalWrite(in2,HIGH);
// analogWrite(ena, 60);


// //MOTOR_B COUNTERCLOCKWISE MAX SPEED
// digitalWrite(in3,LOW);
// digitalWrite(in4,HIGH);
// analogWrite(enb, 60);
// delay(2000);


// //STOP
// digitalWrite(in1,LOW);
// digitalWrite(in2,LOW);
// digitalWrite(in3,LOW);
// digitalWrite(in4,LOW);
// delay(2000);


// //MOTOR_A CLOCKWISE HALF SPEED
// digitalWrite(in1,HIGH);
// digitalWrite(in2,LOW);
// analogWrite(ena, 50);
// //MOTOR_B CLOCKWISE HALF SPEED
// digitalWrite(in3,HIGH);
// digitalWrite(in4,LOW);
// analogWrite(enb, 50);
// delay(2000);


// //STOP
// digitalWrite(in1,LOW);
// digitalWrite(in2,LOW);
// digitalWrite(in3,LOW);
// digitalWrite(in4,LOW);
// delay(2000);


// //MOTOR_A COUNTERCLOCKWISE MAX SPEED
// digitalWrite(in1,LOW);
// digitalWrite(in2,HIGH);
// analogWrite(ena, 50);


// //MOTOR_B COUNTERCLOCKWISE MAX SPEED
// digitalWrite(in3,LOW);
// digitalWrite(in4,HIGH);
// analogWrite(enb, 50);
// delay(2000);


// //STOP
// digitalWrite(in1,LOW);
// digitalWrite(in2,LOW);
// digitalWrite(in3,LOW);
// digitalWrite(in4,LOW);
// delay(2000);
}


void loop() {


}
