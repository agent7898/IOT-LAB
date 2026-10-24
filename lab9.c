/*
 * Experiment 9: Weather station readings using Arduino.
 *
 * Libraries (Arduino IDE -> Library Manager):
 *   - "DHT sensor library" by Adafruit (Install All -> adds Adafruit Unified Sensor)
 *   - "Adafruit BMP085 Library" by Adafruit (Install All -> adds BusIO, Unified Sensor)
 *
 * Pin Connections:
 *   Component    | ESP32   | Arduino UNO
 *   DHT22 O/P    | GPIO 4  | D2
 *   BMP180 SDA   | GPIO 21 | A4
 *   BMP180 SCL   | GPIO 22 | A5
 */

#include <DHT.h>               // DHT11/DHT22 temperature & humidity sensor
#include <Wire.h>              // I2C communication (used by BMP180)
#include <Adafruit_BMP085.h>   // For BMP180 (BMP085-compatible) pressure sensor

#define DHTPIN 4               // Data pin of DHT22
#define DHTTYPE DHT22          // Sensor model

DHT dht(DHTPIN, DHTTYPE);      // DHT(pin, type): create sensor object
Adafruit_BMP085 bmp;           // BMP180 object (talks over I2C)

void setup() {
  Serial.begin(115200);
  dht.begin();                 // Initialise DHT sensor
  if (!bmp.begin()) {          // begin() returns false if BMP180 isn't found on I2C
    Serial.println("BMP180 not detected.");
    while (1);                 // Halt here forever
  }
}

void loop() {
  float temp = dht.readTemperature();           // Temperature in °C
  float hum = dht.readHumidity();               // Relative humidity in %
  float pressure = bmp.readPressure() / 100.0;  // Pa -> hPa (1 hPa = 100 Pa)

  Serial.print("Temp: ");     Serial.print(temp);     Serial.print(" °C, ");
  Serial.print("Humidity: "); Serial.print(hum);      Serial.print(" %, ");
  Serial.print("Pressure: "); Serial.print(pressure); Serial.println(" hPa");

  delay(2000);   // DHT22 needs ~2 s between readings
}
