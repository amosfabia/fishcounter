
void ISR_sendCount() {
  if (state == countingState) {
    state = toSendState;             // pause counting
    numSentMsg = 0;                   // reset tracking of msgs sent
    Serial.println("to send state");
  }
  else if (state == toSendState) {
    state = countingState;
    Serial.println("counting state");
  }

}
