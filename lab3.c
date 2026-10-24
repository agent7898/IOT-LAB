/*
 * Experiment 3: Intrusion detection system using Ultrasonic and sound sensor.
 *
 * Pin Connections:
 *   Component         | ESP32   | Arduino UNO
 *   Ultrasonic TRIG   | GPIO 13 | D9
 *   Ultrasonic ECHO   | GPIO 12 | D10
 *   Sound Sensor OUT  | GPIO 14 | D8
 *   Buzzer            | GPIO 15 | D7
 */

// Pin definitions
const int trigPin = 9;     // Sends the ultrasonic pulse
const int echoPin = 10;    // Receives the reflected pulse
const int buzzerPin = 7;   // Alarm output

long duration;   // Echo pulse time in microseconds
int distance;    // Calculated distance in cm

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzerPin, OUTPUT);

  Serial.begin(9600);   // Serial.begin(baud): start serial monitor at 9600 bits/sec
}

void loop() {
  // --- Ultrasonic sensor distance measurement ---
  digitalWrite(trigPin, LOW);    // Make sure TRIG is low first (clean pulse)
  delayMicroseconds(2);          // delayMicroseconds(us): wait 2 us

  digitalWrite(trigPin, HIGH);   // 10 us HIGH pulse tells HC-SR04 to send 8 ultrasonic bursts
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // pulseIn(pin, HIGH): returns how long (us) ECHO stays HIGH = round-trip time of sound
  duration = pulseIn(echoPin, HIGH);
  // Speed of sound = 0.034 cm/us; divide by 2 because sound travels there and back
  distance = duration * 0.034 / 2;

  // --- Intrusion Detection Condition ---
  if (distance < 50) {                  // Threshold: object closer than 50 cm
    digitalWrite(buzzerPin, HIGH);      // Alarm ON
    Serial.println("Intrusion Detected!");  // println() prints text + newline
  } else {
    digitalWrite(buzzerPin, LOW);       // Alarm OFF
  }

  // Print distance for debugging (print() = no newline)
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  delay(500);
}
