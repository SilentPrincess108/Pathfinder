//Tested: no
//Works: probably also no

int B1 = D0;
int B2 = D1;
int B3 = D2;
int B4 = D3;

int L1 = D4;
int L2 = D5;
int L3 = D6;
int L4 = D10;

int leds[] = {L1, L2, L3, L4};
int buttons[] = {B1, B2, B3, B4};
int sequence[3];
int points = 0;
int lives = 3;

void setup() {
  pinMode(B1, INPUT_PULLUP);
  pinMode(B2, INPUT_PULLUP);
  pinMode(B3, INPUT_PULLUP);
  pinMode(B4, INPUT_PULLUP);

  pinMode(L1, OUTPUT);
  pinMode(L2, OUTPUT);
  pinMode(L3, OUTPUT);
  pinMode(L4, OUTPUT);

  long start = millis();

}

void loop() {
  //gen # of leds to turn on
  //turn them on, one by one, in random order
  //turn them off
  //await input
  //check input (if under certain time)
  //add points or remove lights

  genSequence();

  if (checkInput()){
    points += 1;
  }
  else{
    lives -= 1;
  }

  if (lives == 0){
    exit(0);
  }


}

int genRandNum(){
  return random(0, 3);
}

int genSequence(){
  int numLed = genRandNum();
  for (int i = 0; i < numLed; i++){
    int ledNum = genRandNum();
    sequence[i] = ledNum;
    digitalWrite(leds[ledNum], HIGH);
    delay(1000);
    digitalWrite(leds[ledNum], LOW);
  }
}

int waitForPress(){
  int count = 0;
  while(true){
    for (int i = 0; i < 4; i++){
      if (digitalRead(buttons[i]) == HIGH){ //click detected
        delay(200);
        return i;
        }
      }
    }
  }

int checkInput(){
  for (int i = 0; i < 4; i++){
    int pressed = waitForPress();
    if (pressed != sequence[i]){
      return false; //wrong sequence
    }
  }
  return true; //right sequence
}
