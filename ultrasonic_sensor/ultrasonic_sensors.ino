const int trigPin = 9;
const int echoPin = 10;


const int OutputPin = 12;


float duration, distance;
bool bool_FPGA = 0;


void setup() {
 pinMode(trigPin, OUTPUT);
 pinMode(OutputPin, OUTPUT);
 pinMode(echoPin, INPUT);
 Serial.begin(9600);
}


void loop() {
 digitalWrite(trigPin, LOW);
 delayMicroseconds(2);
 digitalWrite(trigPin, HIGH);
 delayMicroseconds(10);
 digitalWrite(trigPin, LOW);


 duration = pulseIn(echoPin, HIGH);
 distance = (duration*.0343)/2;
 Serial.print("Distance: ");
 Serial.println(distance);


 if(distance < 20){
   bool_FPGA = 1;
   digitalWrite(OutputPin, HIGH);
 }else{
   bool_FPGA = 0;
   digitalWrite(OutputPin, LOW);
 }
 Serial.print("bool_FPGA: ");
 Serial.println(bool_FPGA);


 delay(100); // use 10
}




