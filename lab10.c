/*
 * Experiment 10: Set up a UART protocol and pass a string through it.
 * Type "LED ON", "LED OFF" or "STATUS" in Serial Monitor (line ending: Newline).
 *
 * Pin Connections:
 *   Component | ESP32  | Arduino UNO
 *   LED       | GPIO 2 | D13
 */

#define LED_PIN 2              // GPIO2 for ESP32, use 13 for Arduino Uno

String inputString = "";       // To store incoming serial data
bool stringComplete = false;   // Set true when a full line ('\n') is received

void setup() {
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(9600);          // UART at 9600 baud (8 data bits, no parity, 1 stop bit)
  Serial.println("UART Command Processor Initialized.");
  inputString.reserve(200);    // reserve(n): pre-allocate 200 bytes to avoid re-allocation
}

void loop() {
  // When a complete command is received
  if (stringComplete) {
    processCommand(inputString);
    inputString = "";          // Clear buffer for next command
    stringComplete = false;
  }
}

// serialEvent() is called automatically between loop() runs when new data arrives
void serialEvent() {
  while (Serial.available()) {          // available(): number of bytes waiting in buffer
    char inChar = (char)Serial.read();  // read(): take one byte from the buffer
    inputString += inChar;              // Append to the command string

    // Check for end of line
    if (inChar == '\n') {
      stringComplete = true;
    }
  }
}

void processCommand(String command) {
  command.trim();   // Remove newline or extra whitespace

  // equalsIgnoreCase(): compare strings ignoring upper/lower case
  if (command.equalsIgnoreCase("LED ON")) {
    digitalWrite(LED_PIN, HIGH);
    Serial.println("LED is turned ON");
  }
  else if (command.equalsIgnoreCase("LED OFF")) {
    digitalWrite(LED_PIN, LOW);
    Serial.println("LED is turned OFF");
  }
  else if (command.equalsIgnoreCase("STATUS")) {
    int state = digitalRead(LED_PIN);   // Reading an OUTPUT pin returns its last written state
    if (state == HIGH) {
      Serial.println("LED STATUS: ON");
    } else {
      Serial.println("LED STATUS: OFF");
    }
  }
  else {
    Serial.print("Unknown Command: ");
    Serial.println(command);
  }
}
