bool lastSteadyState = LOW;
bool lastFlickerableState = LOW;
bool currentState;
unsigned long lastDebounceTime = 0;
const byte DEBOUNCE_DELAY = 50;  

void resetbtn() {
  currentState = digitalRead(rstbtn);

  if (currentState != lastFlickerableState) {
    lastDebounceTime = millis();
    lastFlickerableState = currentState;
  }

  if ((millis() - lastDebounceTime) > DEBOUNCE_DELAY) {

    if (lastSteadyState == HIGH && currentState == LOW){
      Serial.println("continue counting...");
      state = countingState;
    }
      

    lastSteadyState = currentState;
  }
}
