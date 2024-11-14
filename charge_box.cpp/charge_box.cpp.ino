

//COUNTDOWN red LED
#define COUNTDOWN 3

//CHARGE pin

#define CHARGE 10



// global vars


unsigned long currentTime;
unsigned long beginningTime;
unsigned long lightupTime;
int blinkInterval = 500; 
int COUNTDOWN = 15000;
unsigned long  previousBlinkTime;


int lightUp = -1; 
bool isBlinkingOn = false; 




void setup() {

  pinMode(COUNTDOWN, OUTPUT);
  digitalWrite(COUNTDOWN, LOW);

  pinMode(CHARGE, OUTPUT);
  digitalWrite(CHARGE, LOW);


  beginningTime = millis();
  lightupTime = beginningTime + COUNTDOWN;
}

void loop() {

  currentTime = millis(); 



  if (currentTime >= lightupTime && lightUp == -1) {
   
    digitalWrite(CHARGE, HIGH);
    lightUp = 1; 
  }

   if (currentTime - previousBlinkTime >= blinkInterval && lightUp == -1) {
    isBlinkingOn = !isBlinkingOn;
    digitalWrite(COUNTDOWN, isBlinkingOn ? HIGH : LOW);
    previousBlinkTime = currentTime; 
   }
}





