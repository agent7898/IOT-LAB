/*
 * Experiment 6: Classify dry and wet waste with the moisture sensor.
 *
 * Pin Connections:
 *   Component          | ESP32   | Arduino UNO
 *   Moisture Sensor A0 | GPIO 32 | A0
 */

// #define replaces the name with the value at compile time (use A0 for Arduino UNO)
#define MOISTURE_SENSOR_PIN 34

void setup() {
  Serial.begin(115200);   // 115200 baud: faster serial speed, common for ESP32
  delay(1000);            // Give sensor/serial time to settle
  Serial.println("Moisture-Based Waste Classification Started...");
}

void loop() {
  // Sensor output is high when dry and drops as moisture increases (0-4095 on ESP32)
  int moistureValue = analogRead(MOISTURE_SENSOR_PIN);
  Serial.print("Moisture Sensor Value: ");
  Serial.println(moistureValue);

  if (moistureValue > 2000) {          // Above threshold = little water = dry
    Serial.println("Waste Type: DRY");
  } else {
    Serial.println("Waste Type: WET");
  }

  Serial.println("----------------------");
  delay(2000);   // Delay for readability
}
