/*
 * Experiment 4: Control a DC motor with Arduino board.
 *
 * Pin Connections:
 *   Component         | ESP32   | Arduino UNO
 *   Relay 1/2         | GPIO 15 | D7
 *   Push Button 1/2   | GPIO 4  | D2
 *
 * Motor to Relay:
 *   - One motor terminal  -> + of power supply
 *   - Other motor terminal -> COM (Common) of relay
 *   - NO (Normally Open) of relay -> GND of power supply
 */

const int relayPin = 7;    // Relay control pin
const int buttonPin = 2;   // Push button pin

void setup() {
  pinMode(relayPin, OUTPUT);
  pinMode(buttonPin, INPUT);   // INPUT: pin reads the button's voltage level
  Serial.begin(9600);
}

void loop() {
  // digitalRead(pin): returns HIGH (1) or LOW (0) from the button
  int buttonState = digitalRead(buttonPin);
  Serial.println(buttonState);

  if (buttonState == 0) {             // Button pressed (pulls pin LOW)
    digitalWrite(relayPin, HIGH);     // Relay energised -> motor runs
  }
  else {
    digitalWrite(relayPin, LOW);      // Relay off -> motor stops
  }
}
