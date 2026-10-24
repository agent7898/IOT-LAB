/*
 * Experiment 12: Interface a 4x4 keypad module to record keystrokes.
 *
 * Library (Arduino IDE -> Library Manager): "Keypad" by Mark Stanley, Alexander Brevig
 *
 * Pin Connections:
 *   Keypad | ESP32   | Arduino UNO
 *   R1     | GPIO 14 | D2
 *   R2     | GPIO 27 | D3
 *   R3     | GPIO 26 | D4
 *   R4     | GPIO 25 | D5
 *   C1     | GPIO 33 | D6
 *   C2     | GPIO 32 | D7
 *   C3     | GPIO 19 | D8
 *   C4     | GPIO 18 | D9
 */

#include <Keypad.h>

const byte ROWS = 4;
const byte COLS = 4;

// Character returned for each button position [row][column]
char keys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

byte rowPins[ROWS] = {14, 27, 26, 25};   // Modify as per your wiring
byte colPins[COLS] = {33, 32, 19, 18};   // Avoid GPIOs 34-39 (input-only, no pull-ups)

// Keypad(keymap, rowPins, colPins, numRows, numCols)
// makeKeymap() converts the 2D keys array into the format the library expects
Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

void setup() {
  Serial.begin(115200);
  Serial.println("Keypad Ready");
}

void loop() {
  // getKey(): scans the matrix, returns the pressed key or 0 (NO_KEY) if none
  char key = keypad.getKey();
  if (key) {
    Serial.print("Key Pressed: ");
    Serial.println(key);
  }
}
