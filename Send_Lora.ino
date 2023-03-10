void sendLoraEvery(int interval){
  timer++;


  if(timer > interval){
    //send to LoRa
    Serial.println("LoRa sent"); 
    timer = 0;
  }
}
