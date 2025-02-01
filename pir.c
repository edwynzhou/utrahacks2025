const int PIR = 8;           // PIR pin out connected to
const int ledPin =  13;      // LED pin

int PIRstate = 0;         // variable for reading the PIR status

void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  pinMode(PIR, INPUT);
}

void loop() {
  PIRstate = digitalRead(PIR);

  if (PIRstate == HIGH) {
    Serial.println("motion detected...");
    digitalWrite(ledPin, HIGH);
  } else {
    Serial.println("No motion detected...");
    digitalWrite(ledPin, LOW);
  }
}