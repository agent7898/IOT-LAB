/*
 * Experiment 1: Blink 5 LEDs back and forth.
 *
 * Pin Connections:
 *   LED | ESP32   | Arduino UNO
 *   L1  | GPIO 2  | D5
 *   L2  | GPIO 4  | D6
 *   L3  | GPIO 5  | D7
 *   L4  | GPIO 18 | D8
 *   L5  | GPIO 19 | D9
 */

// Define GPIO pins for the LEDs (ESP32 pins; use {5, 6, 7, 8, 9} for UNO)
const int ledPins[] = {2, 4, 5, 18, 19};
// Number of LEDs = total array size / size of one element
const int numLeds = sizeof(ledPins) / sizeof(ledPins[0]);

// setup() runs once at power-on / reset
void setup() {
  for (int i = 0; i < numLeds; i++) {
    pinMode(ledPins[i], OUTPUT);     // pinMode(pin, mode): set pin as OUTPUT to drive the LED
    digitalWrite(ledPins[i], LOW);   // digitalWrite(pin, value): LOW = 0V, LED off at start
  }
}

// loop() runs repeatedly forever
void loop() {
  // Blink LEDs from left to right (L1 -> L5)
  for (int i = 0; i < numLeds; i++) {
    digitalWrite(ledPins[i], HIGH);  // HIGH = 3.3V/5V, LED on
    delay(1000);                     // delay(ms): wait 1000 ms = 1 second
    digitalWrite(ledPins[i], LOW);   // LED off
  }

  // Blink LEDs from right to left (L4 -> L2); ends are skipped so they don't blink twice
  for (int i = numLeds - 2; i > 0; i--) {
    digitalWrite(ledPins[i], HIGH);
    delay(1000);
    digitalWrite(ledPins[i], LOW);
  }
}
