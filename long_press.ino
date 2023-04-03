
const int LONG_PRESS_TIME  = 2000;

int lastState = LOW;
int currentState;
unsigned long pressedTime  = 0;
unsigned long releasedTime = 0;


void resetcountORsendmsg() {

  currentState = digitalRead(rstbtn);

  if (lastState == HIGH && currentState == LOW)       // button is pressed
    pressedTime = millis();
  else if (lastState == LOW && currentState == HIGH) { // button is released
    releasedTime = millis();

    long pressDuration = releasedTime - pressedTime;

    if ( pressDuration > LONG_PRESS_TIME )
      if (state == countingState) {
        Serial.println("fish count reset");
        countReset_display();
        fishcount = 0;
      }
      else if (state == toSendState) {
        Serial.println("Sending count...");        
        state = sendingState;
        changeState = true;
        numSentMsg = 0;                   // reset tracking of msgs sent
      }
  }

  // save the the last state
  lastState = currentState;
}
