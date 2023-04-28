
bool oldstate = 0;
bool oldstate_2 = 0;
bool oldstate_3 = 0;
bool isCounting = true;
int fishcount = 0;
int firstpress = 0; //for reset button

void stateIRsensor_init() {
  oldstate = digitalRead(counter1);
  oldstate_2 = digitalRead(counter2);
  oldstate_3 = digitalRead(counter3);
}

bool checkState(int pin , bool oldState) {
  bool newState = digitalRead(pin);


  if (newState != oldState) {
    if (newState != LOW) { //fall edge
      Serial.print("Falling edge  ");
    }
    else {
      Serial.print("Rising Edge  pin:");
      Serial.print(pin);
      Serial.print("  count: ");
      fishcount++;
      Serial.println(fishcount);
      count_display();
    }

  }
  return newState;
}

void startCounting() {
  if (state == countingState) {
    oldstate = checkState(counter1, oldstate);
    oldstate_2 = checkState(counter2, oldstate_2);
    oldstate_3 = checkState(counter3, oldstate_3);
  }
}
