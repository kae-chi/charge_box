#include <SPI.h>
#include <SD.h>

//define relevant pins

//countdown red LED
#define countDown 3

//charge pin

#define charge 10



// global vars


unsigned long currentTime;
unsigned long beginningTime;
unsigned long lightupTime;
int blinkInterval = 1000; 
int countdown = 15000;
unsigned long  previousBlinkTime;


int litUp = -1; 
bool isBlinkingOn = false; 




void setup() {

  pinMode(countDown, OUTPUT);
  digitalWrite(countDown, LOW);

  pinMode(charge, OUTPUT);
  digitalWrite(charge, LOW);


  beginningTime = millis();
  lightupTime = beginningTime + countdown;
}

void loop() {

  currentTime = millis(); 



 
   currentTime = millis();


  if (currentTime >= lightupTime && litUp == -1) {
   
    digitalWrite(charge, HIGH);
    litUp = 1; 
  }

   if (currentTime - previousBlinkTime >= blinkInterval && litUp == -1) {
    isBlinkingOn = !isBlinkingOn;
    digitalWrite(countDown, isBlinkingOn ? HIGH : LOW);
    previousBlinkTime = currentTime; 
   }
}





