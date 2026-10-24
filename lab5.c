/*
 * Experiment 5: Smart street light system using LDR sensor.
 *
 * Pin Connections:
 *   Component | ESP32   | Arduino UNO
 *   LED       | GPIO 25 | D5
 *   LDR       | GPIO 34 | A0
 */

const int ldrPin = A0;        // LDR connected to analog pin A0
const int lightPin = 5;       // LED or relay control pin
int lightThreshold = 500;     // Adjust threshold based on environment

void setup() {
  pinMode(ldrPin, INPUT);
  pinMode(lightPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // analogRead(pin): returns 0-1023 on UNO (0-4095 on ESP32); less light = lower value here
  int ldrValue = analogRead(ldrPin);
  Serial.print("LDR Value: ");
  Serial.println(ldrValue);

  if (ldrValue < lightThreshold) {
    digitalWrite(lightPin, HIGH);   // Turn ON light (dark environment)
  } else {
    digitalWrite(lightPin, LOW);    // Turn OFF light (bright environment)
  }

  delay(500);
}
