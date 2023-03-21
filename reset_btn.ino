bool laststate = HIGH;
bool currentstate;
unsigned long lastDebounceTime = 0;
const byte DEBOUNCE_DELAY = 50;
const int LONG_PRESS_TIME  = 1000;

unsigned long pressedTime  = 0;
unsigned long releasedTime = 0;

void resetbtn() {
  currentstate = digitalRead(rstbtn);
  Serial.println(currentstate);

  if (currentstate != laststate) {
    lastDebounceTime = millis();
  }
//error not triggering
  if ((millis() - lastDebounceTime) > DEBOUNCE_DELAY) {

    if (currentstate != laststate) {
      
      Serial.println("continue counting...");
      state = countingState;
    }   
  }
  laststate = currentstate;
}

void resetcount() {
  currentstate = digitalRead(rstbtn);

  if (laststate == HIGH && currentstate == LOW)       // button is pressed
    pressedTime = millis();
  else if (laststate == LOW && currentstate == HIGH) { // button is released
    releasedTime = millis();
    long pressDuration = releasedTime - pressedTime;

    if ( pressDuration > LONG_PRESS_TIME )
      Serial.println("count reset");

  }
  laststate = currentstate;
}
