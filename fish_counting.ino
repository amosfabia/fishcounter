
bool oldstate = 0;
bool oldstate_2 = 0;
bool oldstate_3 = 0;
bool isCounting = true;
int fishcount = 0;
int firstpress = 0; //for reset button

void stateIRsensor_init(){
    oldstate = digitalRead(pin_1);
  //  oldstate_2 = digitalRead(pin_2);
  //  oldstate_3 = digitalRead(pin_3);
}

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

void startCounting() {
  if (isCounting) {
    oldstate = checkState(pin_1, oldstate);
    //  oldstate_2 = checkState(pin_2, oldstate_2);
    //  oldstate_3 = checkState(pin_3, oldstate_3);
  }
}
