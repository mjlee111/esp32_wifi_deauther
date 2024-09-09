// buttons.h
#ifndef BUTTONS_H
#define BUTTONS_H

#include <Arduino.h>

class Buttons
{
public:
  Buttons(int sel_pin, int back_pin, int up_pin, int down_pin);

  void init();
  int readButtons();

private:
  int buttonPins[4];
};

#endif