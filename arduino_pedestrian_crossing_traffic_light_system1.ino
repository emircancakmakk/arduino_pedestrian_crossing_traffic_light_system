// C++ code
//
int push_button = 0;

int counter;

void setup()
{
  pinMode(2, INPUT);
  Serial.begin(9600);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
}

void loop()
{
  push_button = digitalRead(2);
  Serial.println(push_button);

  if (push_button == 0) {
    digitalWrite(11, HIGH);
    digitalWrite(10, HIGH);
  } else {
    digitalWrite(11, LOW);
    digitalWrite(12, HIGH);
    delay(3000); // Wait for 3000 millisecond(s)
    digitalWrite(12, LOW);
    digitalWrite(13, HIGH);
    delay(3000); // Wait for 3000 millisecond(s)
    digitalWrite(10, LOW);
    digitalWrite(9, HIGH);
    
    unsigned long startTime = millis();
    while (millis() - startTime < 10000) {
      tone(8, 200); // Play tone
      delay(200); // Wait for 200 milliseconds
      noTone(8); // Stop tone
      delay(200); // Wait for 200 milliseconds
    }
    
    for (counter = 0; counter < 3; ++counter) {
      digitalWrite(9, HIGH);
      delay(1000); // Wait for 1000 millisecond(s)
      digitalWrite(9, LOW);
      delay(1000); // Wait for 1000 millisecond(s)
    }
    delay(3000); // Wait for 3000 millisecond(s)
    digitalWrite(10, HIGH);
    digitalWrite(13, LOW);
    digitalWrite(12, HIGH);
    delay(3000); // Wait for 3000 millisecond(s)
    digitalWrite(12, LOW);
  }
}