// display.hpp
#ifndef DISPLAY_H
#define DISPLAY_H

#include <Adafruit_SSD1306.h>
#include <Wire.h>
#include <string>

class Display
{
public:
  Display(int16_t width, int16_t height, int8_t reset_pin, uint8_t address, int16_t SDA_pin, int16_t SCL_pin);

  bool startDisplay();

  void setWhite();

  void setDisplayText(std::string text, int16_t x, int16_t y, float size);
  void setDisplayText(const char* text, int16_t x, int16_t y, float size);
  void setDisplayText(int text, int16_t x, int16_t y, float size);
  void setDisplayTextF(float text, int16_t x, int16_t y, float size);

  void appendDisplayText(std::string text, int16_t x, int16_t y, float size);
  void appendDisplayText(const char* text, int16_t x, int16_t y, float size);
  void appendDisplayText(int text, int16_t x, int16_t y, float size);
  void appendDisplayTextF(float text, int16_t x, int16_t y, float size);

  void clear();

private:
  Adafruit_SSD1306 display;
  int16_t SDA, SCL;
  uint8_t screen_address;
  int16_t DISPLAY_WIDTH, DISPLAY_HEIGHT;
};

#endif  // DISPLAY_H
