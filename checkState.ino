bool checkState(int pin , bool oldState) {
  bool newState = digitalRead(pin);


  if (newState != oldState) {
    if (newState == LOW) { //fall edge
      Serial.print("Falling edge  ");
    }
    else {

      Serial.print("Rising Edge  pin:");
      Serial.print(pin);
      Serial.print("  count: ");
      fishcount++;
      Serial.println(fishcount);
    }

  }
  return newState;
}
