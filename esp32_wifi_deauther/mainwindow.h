// mainwindow.h
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1
#define SCREEN_ADDRESS 0x3C
#define SDA_PIN 6
#define SCL_PIN 7

#define SET_RANDOM_MAC 1

#define BUTTON_SEL_PIN 1
#define BUTTON_BACK_PIN 2
#define BUTTON_UP_PIN 3
#define BUTTON_DOWN_PIN 4

#define SK6812_PIN 5

#include "buttons.h"
#include "display.h"
#include "wifi_utils.h"
#include <string>

class Mainwindow {
public:
  Mainwindow();
  ~Mainwindow();

  void init();
  void loop();

  void setMainPage();
  void handleMainPageUp();
  void handleMainPageDown();

private:
  Display *display_;
  WiFi_Utils *w_utils_;
  Buttons *buttons_;

  int cursor_index = 0;
  int page = 0; // 0 : Main, 1 : Scan, 2 : Select, 3 : Attack, 4 : Info
};

#endif
