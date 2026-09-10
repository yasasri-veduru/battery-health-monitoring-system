#define BATTERY_PIN 34
#define TEMP_PIN 35
#define RELAY_PIN 26
#define LED_PIN 27
#define BUZZER_PIN 25
#define BUTTON_PIN 14
void setup() {
  Serial.begin(115200);
  pinMode(RELAY_PIN, OUTPUT);
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  digitalWrite(RELAY_PIN, LOW);
  digitalWrite(LED_PIN, LOW);
  digitalWrite(BUZZER_PIN, LOW);
  Serial.println("Battery Health System Test Started");
}
void loop() {
  int tempADC = analogRead(TEMP_PIN);
  Serial.print("Temperature NTC ADC: ");
  Serial.println(tempADC);
  int batteryADC = analogRead(BATTERY_PIN);
  float batteryPercent = (batteryADC / 4095.0) * 100.0;
  Serial.print("Battery Level: ");
  Serial.print(batteryPercent);
  Serial.println("%");
  if (digitalRead(BUTTON_PIN) == LOW) {
    Serial.println("Charging Button: PRESSED");
  } else {
    Serial.println("Charging Button: NOT PRESSED");
  }
  if (tempADC < 1500) {
    digitalWrite(LED_PIN, HIGH);
    digitalWrite(BUZZER_PIN, HIGH);
    digitalWrite(RELAY_PIN, LOW);
    Serial.println("⚠ HIGH TEMPERATURE ALERT!");
  }
  else {
    digitalWrite(LED_PIN, LOW);
    digitalWrite(BUZZER_PIN, LOW);
    digitalWrite(RELAY_PIN, HIGH);
    Serial.println("Temperature Normal");
  }
  Serial.println("-------------------------");
  delay(1000);
}