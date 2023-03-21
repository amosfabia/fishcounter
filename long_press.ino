/*
 * Created by ArduinoGetStarted.com
 *
 * This example code is in the public domain
 *
 * Tutorial page: https://arduinogetstarted.com/tutorials/arduino-button-long-press-short-press
 */

// constants won't change. They're used here to set pin numbers:
const int LONG_PRESS_TIME  = 2000; // 1000 milliseconds

// Variables will change:
int lastState = LOW;  // the previous state from the input pin
int currentState;     // the current reading from the input pin
unsigned long pressedTime  = 0;
unsigned long releasedTime = 0;


void resetcountORsendmsg() {
  // read the state of the switch/button:
  currentState = digitalRead(rstbtn);

  if(lastState == HIGH && currentState == LOW)        // button is pressed
    pressedTime = millis();
  else if(lastState == LOW && currentState == HIGH) { // button is released
    releasedTime = millis();

    long pressDuration = releasedTime - pressedTime;

    if( pressDuration > LONG_PRESS_TIME )
      if(state == countingState){
        Serial.println("fish count reset");
        fishcount = 0;
      }
      else if(state == toSendState){
        Serial.println("Sending count...");
        state = sendingState;
      }
  }

  // save the the last state
  lastState = currentState;
}
