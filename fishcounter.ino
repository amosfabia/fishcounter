#define pin_1 4
#define pin_2 5
#define pin_3 6
#define rstbtn 7
#define sendCountbttn 3

#include <SPI.h>              // include libraries
#include <LoRa.h>

void setup() {
  pinMode(sendCountbttn, INPUT_PULLUP);
  pinMode(pin_1, INPUT);
  //  pinMode(pin_2, INPUT);
  //  pinMode(pin_3, INPUT);
  pinMode(rstbtn, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(sendCountbttn), ISR_sendCount, FALLING);
  Serial.begin(9600);
  Serial.println("fishcounter");
  stateIRsensor_init();
  LoRaSetup();
}

void loop() {
  startCounting();
  sendFishCount();        //only start sending when button(interrupt) is pressed
  onReceive(LoRa.parsePacket());
}
