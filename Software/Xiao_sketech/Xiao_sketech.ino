
#include <HID-Project.h>  // pulls in Gamepad, Keyboard, Mouse, etc.

const int numRows = 4;
const int numCols = 5;
const int rowPins[numRows] = {0, 1, 2, 3};    // D0–D3
const int colPins[numCols] = {6, 7, 8, 9, 10}; // D6–D10

bool lastState[4][5] = {0};

void setup() {
  // matrix setup...
  for (int i = 0; i < numRows; i++) {
    pinMode(rowPins[i], OUTPUT);
    digitalWrite(rowPins[i], HIGH);
  }
  for (int j = 0; j < numCols; j++) {
    pinMode(colPins[j], INPUT_PULLUP);
  }

  Gamepad.begin();  // initialize gamepad HID
}

void loop() {
  // scan each row
  for (int i = 0; i < numRows; i++) {
    digitalWrite(rowPins[i], LOW);
    for (int j = 0; j < numCols; j++) {
      bool pressed = !digitalRead(colPins[j]);
      int buttonNumber = i * numCols + j + 1; // HID buttons are 1-indexed

      if (pressed && !lastState[i][j]) {
        Gamepad.press(buttonNumber);
        lastState[i][j] = true;
      }
      else if (!pressed && lastState[i][j]) {
        Gamepad.release(buttonNumber);
        lastState[i][j] = false;
      }
    }
    digitalWrite(rowPins[i], HIGH);
  }

  Gamepad.write();   // send the updated button states
  delay(5);          // simple debounce
}
