#include <SPI.h>
#include <Servo.h>
#include <nRF24L01.h>
#include <RF24.h>

Servo servo;
RF24 radio(7, 8); // CE, CSN

const byte address[6] = "00001";

void setup() {
  servo.attach(6);
  pinMode(2, OUTPUT);
  radio.begin();
  radio.openReadingPipe(0, address);
  radio.setPALevel(RF24_PA_MIN);
  radio.startListening();

}

void loop() {
  if (radio.available()) {
    int joyVal = 0;
    radio.read(&joyVal, sizeof(joyVal));
    servo.write(joyVal);
    digitalWrite(2, HIGH);

  }
}
