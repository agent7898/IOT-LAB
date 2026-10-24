/*
 * Experiment 11: Water level detection system using Ultrasonic sensor.
 * Sensor is mounted on top of the tank; smaller distance = higher water level.
 *
 * Pin Connections:
 *   Component       | ESP32   | Arduino UNO
 *   Ultrasonic TRIG | GPIO 5  | D9
 *   Ultrasonic ECHO | GPIO 18 | D10
 */

const int trigPin = 5;
const int echoPin = 18;

void setup() {
  Serial.begin(115200);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

// Returns distance (cm) from sensor to the water surface
long getDistance() {
  digitalWrite(trigPin, LOW);  delayMicroseconds(2);    // Clear TRIG
  digitalWrite(trigPin, HIGH); delayMicroseconds(10);   // 10 us pulse starts a measurement
  digitalWrite(trigPin, LOW);
  long duration = pulseIn(echoPin, HIGH);   // Echo HIGH time in us (round trip)
  long distance = duration * 0.034 / 2;     // 0.034 cm/us speed of sound, /2 for one way
  return distance;
}

void loop() {
  long distance = getDistance();
  Serial.print("Water Level Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
  delay(1000);
}
