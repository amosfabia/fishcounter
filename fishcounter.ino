#define pin_1 2
#define pin_2 3
#define pin_3 4
#define rstbtn 7
#define bounce_delay 10 //wait 50millisecond for bouncing

bool oldstate = 0;
bool oldstate_2 = 0;
bool oldstate_3 = 0;


int fishcount = 0;
int firstpress = 0; //for reset button
int timer = 0;


void setup() {
  
  pinMode(pin_1, INPUT);
  pinMode(pin_2, INPUT);
  pinMode(pin_3, INPUT);
  pinMode(rstbtn, INPUT_PULLUP);
  Serial.begin(9600);

  oldstate = digitalRead(pin_1);
  oldstate_2 = digitalRead(pin_2);
  oldstate_3 = digitalRead(pin_3);
}

void loop() {

  oldstate = checkState(pin_1, oldstate);
  oldstate_2 = checkState(pin_2, oldstate_2);
  oldstate_3 = checkState(pin_3, oldstate_3);
  sendLoraEvery(10000);

}
