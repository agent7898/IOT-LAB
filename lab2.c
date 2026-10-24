/*
 * Experiment 2: Interface a relay with Arduino board.
 *
 * Pin Connections:
 *   Relay     | ESP32   | Arduino UNO
 *   Relay 1/2 | GPIO 15 | D7
 */

// Define the relay control pin (any digital pin can be used)
const int relayPin = 7;

void setup() {
  pinMode(relayPin, OUTPUT);       // Set the relay pin as output
  digitalWrite(relayPin, HIGH);    // Relay is active LOW, so HIGH keeps it OFF initially
}

void loop() {
  digitalWrite(relayPin, LOW);     // Turn ON relay (connects the load)
  delay(1000);                     // Wait 1 second

  digitalWrite(relayPin, HIGH);    // Turn OFF relay (disconnects the load)
  delay(1000);                     // Wait 1 second
}
