int dist() {
  int i = 0;
  int analogPin = analogRead(0);

  if (analogPin < 220) {
    return 0;
  }
  
  for (i = 0;i < 20; i++) {
    digitalWrite(11, HIGH);
    delay(50);
    digitalWrite(11, LOW);
    delay(50);
  }
  
  return 1;
}

void setup() {
  // put your setup code here, to run once:
  pinMode(11, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (dist() == 0) {
    digitalWrite(11, HIGH);
  } else {
    Serial.println("1");
  }
  
}
