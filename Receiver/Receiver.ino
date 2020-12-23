/*
* Arduino Wireless Communication Tutorial
*       Example 1 - Receiver Code
*                
* by Dejan Nedelkovski, www.HowToMechatronics.com
* 
* Library: TMRh20/RF24, https://github.com/tmrh20/RF24/
*/

#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

const int relayPin = 6;

RF24 radio(7, 8); // CE, CSN

const byte address[6] = "00001";

void setup() {
  Serial.begin(9600);
  radio.begin();
  radio.openReadingPipe(0, address);
  radio.setPALevel(RF24_PA_MIN);
  radio.startListening();

  pinMode(relayPin, OUTPUT);

}

void loop() {
  while (radio.available()) {
    char text1[32] = "";
    char text2[32] = "";
    radio.read(&text1, sizeof(text1));
    radio.read(&text2, sizeof(text2));
    if(strcmp(text1,"nakkivene")==0){
      Serial.println("abid");
      digitalWrite(relayPin, HIGH);
    }
    /* if(strcmp(text2,"kirkkovene")==0){
      Serial.println("hamed");
      digitalWrite(relayPin, LOW);
    }*/
    else{
      Serial.println("wallah");
      digitalWrite(relayPin, LOW);
    }
   delay(25);
 }
}
