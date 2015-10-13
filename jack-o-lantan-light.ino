int trickOrTreatCallLevel = 220;

int dist() {
  int i = 0;
  int analogPin = analogRead(0);

  if (analogPin < trickOrTreatCallLevel) {
    return -1;
  }
  
  return analogPin;
}

void setup() {
  pinMode(11, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int distance = dist();
  
  if (distance == -1) {
    digitalWrite(11, HIGH);
  } else {  
    for (i = 0;i < 20; i++) {
      digitalWrite(11, HIGH);
      delay(50);
      digitalWrite(11, LOW);
      delay(50);
    }
  }
  
  Serial.println(distance);
  
}
