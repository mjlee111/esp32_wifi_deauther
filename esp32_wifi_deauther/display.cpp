// display.cpp
#include "display.h"

Display::Display(int16_t width, int16_t height, int8_t reset_pin, uint8_t address, int16_t SDA_pin, int16_t SCL_pin)
  : display(width, height, &Wire, reset_pin), screen_address(address), SDA(SDA_pin), SCL(SCL_pin)
{
}

bool Display::startDisplay()
{
  Wire.begin(SDA, SCL);
  if (!display.begin(SSD1306_SWITCHCAPVCC, screen_address))
  {
    for (;;)
      ;
  }

  display.display();
  delay(2000);

  display.clearDisplay();
  return true;
}

void Display::setDisplayText(std::string text, int16_t x, int16_t y, float size)
{
  if (text.length() > 21)
  {
    text = text.substr(0, 21);
  }
  display.clearDisplay();
  display.setTextColor(WHITE);
  display.setTextSize(size);
  display.setCursor(x * 6, y * 8);
  display.println(text.c_str());
  display.display();
}

void Display::setDisplayText(const char* text, int16_t x, int16_t y, float size)
{
  std::string str = text;
  setDisplayText(str, x, y, size);
}

void Display::setDisplayText(int text, int16_t x, int16_t y, float size)
{
  std::string str = std::to_string(text);
  setDisplayText(str, x, y, size);
}

void Display::appendDisplayText(std::string text, int16_t x, int16_t y, float size)
{
  if (text.length() > 21)
  {
    text = text.substr(0, 21);
  }
  display.setTextColor(WHITE);
  display.setTextSize(size);
  display.setCursor(x * 6, y * 8);
  display.println(text.c_str());
  display.display();
}

void Display::appendDisplayText(const char* text, int16_t x, int16_t y, float size)
{
  std::string str = text;
  appendDisplayText(str, x, y, size);
}

void Display::appendDisplayText(int text, int16_t x, int16_t y, float size)
{
  std::string str = std::to_string(text);
  appendDisplayText(str, x, y, size);
}

void Display::clearRow(int row)
{
  display.fillRect(0, row * 8, DISPLAY_WIDTH, 8, BLACK);
  display.display();
}

void Display::clearCol(int col)
{
  display.fillRect(col * 6, 0, 6, DISPLAY_HEIGHT, BLACK);
  display.display();
}

void Display::clearRowArea(int start_row, int end_row)
{
  if (start_row > end_row)
  {
    return;
  }
  for (int i = start_row; i <= end_row; i++)
  {
    clearRow(i);
  }
}

void Display::clearColArea(int start_col, int end_col)
{
  if (start_col > end_col)
  {
    return;
  }
  for (int i = start_col; i <= end_col; i++)
  {
    clearCol(i);
  }
}