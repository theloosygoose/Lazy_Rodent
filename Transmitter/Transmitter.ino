#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

RF24 radio(7, 8); // CE, CSN
const int joyY = A0; // analog pin connected to Y output

const byte address[6] = "00001";

int joyVal;

void setup() {
  radio.begin();
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_MIN);
  radio.stopListening();

}

void loop() {
  joyVal = analogRead(joyY);
  joyVal = map(joyVal, 0, 1023, 0, 180);
  radio.write(&joyVal, sizeof(joyVal));
}
