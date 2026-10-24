/*
 * Experiment 8: Detect gas leakage in the surrounding environment.
 *
 * Pin Connections:
 *   Component | ESP32   | Arduino UNO
 *   MQ135 A0  | GPIO 15 | A0
 *   Buzzer    | GPIO 4  | D13
 */

const int gasSensorPin = A0;   // Use GPIO34 or GPIO36 if using ESP32 (input-only is fine for analog read)
const int buzzerPin = 13;      // Connect buzzer to digital pin

void setup() {
  Serial.begin(115200);
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  // MQ135 output voltage rises with gas concentration -> higher analog value
  int gasValue = analogRead(gasSensorPin);
  Serial.print("Gas Sensor Value: ");
  Serial.println(gasValue);

  if (gasValue > 300) {               // Threshold may vary depending on environment
    digitalWrite(buzzerPin, HIGH);    // Sound the alarm
    Serial.println("Gas leakage detected!");
  } else {
    digitalWrite(buzzerPin, LOW);
  }

  delay(1000);
}
