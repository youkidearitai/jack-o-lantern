#include <stdlib.h>
#define MAX_READ_BYTE 128

int trickOrTreatCallLevel = 220;

int dist() {
  int analogPin = analogRead(0);

  if (analogPin < trickOrTreatCallLevel) {
    return -1;
  }
  
  return analogPin;
}

int getTrickOrTreatCallLevel() {
  char str[MAX_READ_BYTE] = {'\0'};
  char c;
  
  if (Serial.available() == 0) {
    return trickOrTreatCallLevel;
  }
  
  for (int i = 0; c != -1 || i < MAX_READ_BYTE; c = Serial.read(), i++) {
    str[i] = c;
  }
  
  return atoi(str);
}

void setup() {
  pinMode(11, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int distance;
  
  trickOrTreatCallLevel = getTrickOrTreatCallLevel();
  distance = dist();
  
  if (distance == -1) {
    digitalWrite(11, HIGH);
  } else {  
    for (int i = 0;i < 20; i++) {
      digitalWrite(11, HIGH);
      delay(50);
      digitalWrite(11, LOW);
      delay(50);
    }
    Serial.println(distance);
  }  
}
