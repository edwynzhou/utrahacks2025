//MOTOR1 PINS
int ena = 5;
int in1 = 6;
int in2 = 7;
int in3 = 8;
int in4 = 9;
int enb = 10;


void setup() {
 Serial.begin(9600);


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
 while (digitalRead(PIR) == LOW) {
   Serial.println("No human detected...");
  
   digitalWrite(in1,HIGH);
   digitalWrite(in2,LOW);
   digitalWrite(in3,HIGH);
   digitalWrite(in4,LOW);
   analogWrite(ena, 60);
   analogWrite(enb, 60);
   delay(1000);
 }


 Serial.println("Yes human detected...");
   digitalWrite(in1,LOW);
   digitalWrite(in2,LOW);
   digitalWrite(in3,LOW);
   digitalWrite(in4,LOW);
   delay(3000);


 while(1){ // while human not found, rotates
   //MOTOR_A CLOCKWISE MAX SPEED
   digitalWrite(in1,HIGH);
   digitalWrite(in2,LOW);
   digitalWrite(in3,LOW);
   digitalWrite(in4,LOW);
   analogWrite(ena, 60);
 }


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
