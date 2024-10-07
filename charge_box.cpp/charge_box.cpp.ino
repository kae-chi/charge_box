#include <SPI.h>
#include <SD.h>

//define relevant pins

//countdown red LED
#define countDown 4

//charge pin

#define charge 7



// global vars


unsigned long currentTime;
unsigned long beginningTime;
unsigned long lightupTime;
int countdown = 15;




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

  for (int i = 0; i < countdown; i++) {

     unsigned long desiredTime = currentTime + i;
    if (desiredTime >= currentTime) {
      digitalWrite(countDown, HIGH);
    }
    digitalWrite(countDown, LOW);
  }

  if (currentTime >= lightupTime) {
    digitalWrite(countDown, HIGH);
    digitalWrite(charge, HIGH);
  }
}
