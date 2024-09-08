// buttons.cpp
#include "buttons.h"

Buttons::Buttons(int sel_pin, int back_pin, int up_pin, int down_pin) {
  buttonPins[0] = sel_pin;
  buttonPins[1] = back_pin;
  buttonPins[2] = up_pin;
  buttonPins[3] = down_pin;
}

void Buttons::init() {
  for (int i = 0; i < 4; i++) {
    pinMode(buttonPins[i], INPUT_PULLUP);
  }
}

int Buttons::readButtons() {
  for (int i = 0; i < 4; i++) {
    if (digitalRead(buttonPins[i]) == LOW) {
      delay(100);
      return i;
    }
  }
}