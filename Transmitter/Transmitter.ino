/*
* Arduino Wireless Communication Tutorial
*     Example 1 - Transmitter Code
*                
* by Dejan Nedelkovski, www.HowToMechatronics.com
* 
* Library: TMRh20/RF24, https://github.com/tmrh20/RF24/
*/

#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

RF24 radio(7, 8); // CE, CSN

const byte address[6] = "00001";
const int buttonPin = 2;

int buttonState = 0;  

void setup() {
  Serial.begin(9600);
  radio.begin();
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_MIN);
  radio.stopListening();

  pinMode(buttonPin, INPUT_PULLUP);
}

void loop() {
  buttonState = digitalRead(buttonPin);

  const char text1[] = "nakkivene";
  const char text2[] = "kirkkovene";
  //radio.write(&text, sizeof(text));

  if (buttonState == LOW) {
    Serial.println(buttonState);
    radio.write(&text1, sizeof(text1));
  } 
  if (buttonState == HIGH) {
    Serial.println(buttonState);
    radio.write(&text2, sizeof(text2));
  }
  delay(25);
}
