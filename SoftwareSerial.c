#include <SoftwareSerial.h>

SoftwareSerial BTserial(2, 3); // RX | TX

const int led1 = 8;  // LED 1 pin
const int led2 = 9;  // LED 2 pin

void setup() {
  Serial.begin(9600);
  BTserial.begin(9600);

  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);

  Serial.println("Waiting for Bluetooth data...");
}

void loop() {
  if (BTserial.available()) {
    char c = BTserial.read();

    // Ignore newline characters
    if (c == '\r' || c == '\n') {
      return;
    }

    Serial.print("Received: ");
    Serial.println(c);

    if (c == '1') {
      Serial.println("Turning on LEDs");
      digitalWrite(led1, HIGH);
      digitalWrite(led2, HIGH);
    } 
    else if (c == '0') {
      Serial.println("Turning off LEDs");
      digitalWrite(led1, LOW);
      digitalWrite(led2, LOW);
    }
  }
}