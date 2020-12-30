int GREEN_LED = 13;
int YELLOW_LED = 12;
int RED_LED = 11;
int WATER_SENSOR_PIN = A5;
int WATER_LEVEL;
int BUZZER = 8;
boolean BUZZED = false;

void setup() {
  pinMode(GREEN_LED, OUTPUT);
  pinMode(YELLOW_LED, OUTPUT);
  pinMode(RED_LED, OUTPUT);
  Serial.begin(9600);
  pinMode(BUZZER, OUTPUT);
}

void dance() {
  digitalWrite(GREEN_LED, HIGH);
  digitalWrite(YELLOW_LED, HIGH);
  digitalWrite(RED_LED, HIGH);
  delay(1000);
  digitalWrite(GREEN_LED, LOW);
  delay(1000);
  digitalWrite(YELLOW_LED, LOW);
  delay(1000);
  digitalWrite(RED_LED, LOW);
}

void loop() {
  resetLights();
  WATER_LEVEL = analogRead(WATER_SENSOR_PIN);
  Serial.println(WATER_LEVEL);
  if (WATER_LEVEL <= 400) {
    BUZZED = false;
  } else if (WATER_LEVEL <= 500) {
    digitalWrite(GREEN_LED, HIGH);
  } else if (WATER_LEVEL <= 550) {
    digitalWrite(YELLOW_LED, HIGH);
    digitalWrite(RED_LED, HIGH);
    if (!BUZZED) {
      tone(BUZZER, 2000);
      delay(1000);
      noTone(BUZZER);
      BUZZED = true;
    }
  } else {
    digitalWrite(RED_LED, HIGH);
    if (!BUZZED) {
      tone(BUZZER, 2000);
      delay(1000);
      noTone(BUZZER);
      BUZZED = true;
    }
  }
  delay(1000);
}

void resetLights() {
  digitalWrite(GREEN_LED, LOW);
  digitalWrite(YELLOW_LED, LOW);
  digitalWrite(RED_LED, LOW);
}
