#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);



void lcd_setup() {
  lcd.begin(16, 2);
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Fish Counter");
}

void navCount_display() {

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Fish Counter");
  lcd.setCursor(0, 1);
  lcd.print("count: ");
  count_display();
}

void navSend_display() {

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Send to LoRa");
  lcd.setCursor(0, 1);
  lcd.print("LongPress-send");
}

void count_display() {

  lcd.setCursor(7, 1);
  lcd.print(fishcount);
}

void countReset_display() {
  lcd.setCursor(7, 1);
  lcd.print("reset");
  delay(1000);
  lcd.setCursor(7, 1);
  lcd.print("0     ");
}

void sending_display() {
  lcd.setCursor(0, 1);
  lcd.print("Sending...      ");
}

void sendingFailed_display() {
  lcd.setCursor(0, 1);
  lcd.print("Sending Failed");
  delay(2000);
  lcd.setCursor(0, 1);
  lcd.print("LongPress-send");
}

void sendingSuccess_display() {
  lcd.setCursor(0, 1);
  lcd.print("Send Success! ");
}

void navigate_display() {
  if (changeState) {

    switch (state) {

      case countingState:
        navCount_display();
        changeState = false;
        break;
        
      case toSendState:
        navSend_display();
        changeState = false;
        break;

      case sendingState:
        sending_display();
        changeState = false;
        break;
    }
  }
}
