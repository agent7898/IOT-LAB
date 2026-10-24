/*
 * Experiment 7: Read the pH value of various substances like milk, lime and water.
 *
 * Pin Connections:
 *   Component | ESP32   | Arduino UNO
 *   P0        | GPIO 34 | A3
 *   VCC       | 5V      | 5V
 *   GND       | GND     | GND
 */

#define PH_SENSOR_PIN 36   // GPIO36 (VP on ESP32)

void setup() {
  Serial.begin(115200);
  // analogReadResolution(bits): set ADC to 12 bits -> values 0-4095 (ESP32 only)
  analogReadResolution(12);
}

void loop() {
  int adc_value = analogRead(PH_SENSOR_PIN);       // Read raw ADC value
  float voltage = (adc_value * 5.0) / 4095.0;      // Convert ADC count to voltage

  // Assume pH sensor gives 0V = pH 0 and 3.0V = pH 14 (standard range)
  float pH_value = (voltage / 3.0) * 14.0;         // Linear mapping to pH

  Serial.print("ADC: ");
  Serial.print(adc_value);
  Serial.print(" | Voltage: ");
  Serial.print(voltage, 3);        // print(value, 3): show 3 decimal places
  Serial.print(" V | Estimated pH: ");
  Serial.println(pH_value, 2);     // 2 decimal places

  delay(2000);   // Read every 2 seconds
}
