#define counter1 4
#define counter2 5
#define counter3 6
#define rstbtn 7
#define sendCountbttn 3

#include <SPI.h>              // include libraries
#include <LoRa.h>

const byte countingState = 0x0;
const byte toSendState = 0x1;
const byte sendingState = 0x2;
byte state = countingState;     //default state of device
byte numSentMsg = 0;                   // track how many msgs already sent

bool changeState = true;

void setup() {

  pinMode(counter1, INPUT);
  pinMode(counter2, INPUT);
  pinMode(counter3, INPUT);

  pinMode(sendCountbttn, INPUT_PULLUP);
  pinMode(rstbtn, INPUT_PULLUP);

  attachInterrupt(digitalPinToInterrupt(sendCountbttn), my_interrupt_handler, FALLING);

  Serial.begin(9600);
  Serial.println("fishcounter");

  stateIRsensor_init();
  LoRaSetup();
  lcd_setup();
  Serial.println("counting state");
}

void loop() {

  startCounting();        //default state is counting, when interrupt is pressed. pause counting, start sending
  sendFishCount();        //only start sending when button(interrupt) is pressed    
  resetcountORsendmsg(); 
  navigate_display();
}
