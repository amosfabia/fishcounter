#define counter1 4
#define counter2 5
#define counter3 6
#define rstbtn 7
#define sendCountbttn 3

#include <SPI.h>              // include libraries
#include <LoRa.h>

byte countingState = 0x0;
byte toSendState = 0x1;
byte sendingState = 0x2;
byte state = countingState;     //default state of device

void setup() {

  pinMode(counter1, INPUT);
  pinMode(counter2, INPUT);
  pinMode(counter3, INPUT);

  pinMode(sendCountbttn, INPUT_PULLUP);
  pinMode(rstbtn, INPUT_PULLUP);

  attachInterrupt(digitalPinToInterrupt(sendCountbttn), ISR_sendCount, FALLING);

  Serial.begin(9600);
  Serial.println("fishcounter");

  stateIRsensor_init();
  LoRaSetup();
  Serial.println("counting state");
}

void loop() {

  startCounting();        //default state is counting, when interrupt is pressed. pause counting, start sending
  sendFishCount();        //only start sending when button(interrupt) is pressed    
  resetcountORsendmsg(); 

}
