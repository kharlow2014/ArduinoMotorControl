// Keaton Harlow
// 4/19/2017
// Test for h-bridge using a microcontroller
// One button for forward, one button for reverse

// Defining the pins for forward and reverse output
#define EXTEND       2
#define RETRACT      3
// Defining the pins for forward and reverse input
#define EXT_BUTTON   10
#define RET_BUTTON   11
// Defining the pins to check that h-bridge voltage is low on reverse side
#define EXT_CHECK    6
#define RET_CHECK    5

void setup() {
  pinMode(EXTEND, OUTPUT);
  pinMode(RETRACT, OUTPUT);
  pinMode(EXT_BUTTON, INPUT);
  pinMode(RET_BUTTON, OUTPUT);
  pinMode(EXT_CHECK, INPUT);
  pinMode(RET_CHECK, INPUT);
}

int fbutton = 0;
int rbutton = 0;

void loop() {
  fbutton = digitalRead(EXT_BUTTON);
  rbutton = digitalRead(RET_BUTTON);
  if(fbutton == HIGH && rbutton == LOW) {
    digitalWrite(RETRACT, LOW);
    if(digitalRead(RET_CHECK) == LOW) {
      digitalWrite(EXTEND, HIGH);
    }
  }
  else if(rbutton == HIGH && fbutton == LOW) {
    digitalWrite(EXTEND, LOW);
    if(digitalRead(EXT_CHECK) == LOW) {
      digitalWrite(RETRACT, HIGH);
    }
  }
  else {
    digitalWrite(EXTEND, LOW);
    digitalWrite(RETRACT, LOW);
  }
}
