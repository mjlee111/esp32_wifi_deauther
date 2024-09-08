// mainwindow.cpp
#include "mainwindow.h"

Mainwindow::Mainwindow() {
  display_ = new Display(SCREEN_WIDTH, SCREEN_HEIGHT, OLED_RESET,
                         SCREEN_ADDRESS, SDA_PIN, SCL_PIN);
  w_utils_ = new WiFi_Utils(SET_RANDOM_MAC);
  buttons_ = new Buttons(BUTTON_SEL_PIN, BUTTON_BACK_PIN, BUTTON_UP_PIN,
                         BUTTON_DOWN_PIN);
}

Mainwindow::~Mainwindow() {
  delete display_;
  delete w_utils_;
  delete buttons_;
}

void Mainwindow::init() {
  while (!display_->startDisplay()) {
  }

  display_->setDisplayText("ESP32WifiDeautherV1.0", 0, 0, 1);
  display_->appendDisplayText("Starting ...", 0, 1, 1);
  if (SET_RANDOM_MAC) {
    display_->appendDisplayText("Changing MAC ...", 0, 2, 1);
  }
  w_utils_->init();
  if (w_utils_->isInit) {
    display_->appendDisplayText(w_utils_->macAddress(), 0, 3, 1);
    display_->appendDisplayText("Scanning ...", 0, 4, 1);
    w_utils_->scanWifiList();
  }
  buttons_->init();
  setMainPage();
}

void Mainwindow::loop() {
  int num = buttons_->readButtons();
  switch (num) {
  case 0:
    break;
  case 1:
    break;
  case 2:
    handleMainPageUp();
    break;
  case 3:
    handleMainPageDown();
    break;
  default:
    break;
  }
}

void Mainwindow::setMainPage() {
  display_->setDisplayText(" ESP32 Wifi Deauther ", 0, 0, 1);
  display_->appendDisplayText(" 1. Scan", 0, 2, 1);
  display_->appendDisplayText(" 2. Select", 0, 3, 1);
  display_->appendDisplayText(" 3. Attack", 0, 4, 1);
  display_->appendDisplayText(" 4. Info", 0, 5, 1);
  display_->appendDisplayText("*", 0, 2, 1);
}

void Mainwindow::handleMainPageUp() {
  if (cursor_index == 0) {
    cursor_index = 3;
  } else {
    cursor_index--;
  }
  display_->setDisplayText(" ESP32 Wifi Deauther ", 0, 0, 1);
  display_->appendDisplayText(" 1. Scan", 0, 2, 1);
  display_->appendDisplayText(" 2. Select", 0, 3, 1);
  display_->appendDisplayText(" 3. Attack", 0, 4, 1);
  display_->appendDisplayText(" 4. Info", 0, 5, 1);
  display_->appendDisplayText("*", 0, cursor_index + 2, 1);
}

void Mainwindow::handleMainPageDown() {
  if (cursor_index == 3) {
    cursor_index = 0;
  } else {
    cursor_index++;
  }
  display_->setDisplayText(" ESP32 Wifi Deauther ", 0, 0, 1);
  display_->appendDisplayText(" 1. Scan", 0, 2, 1);
  display_->appendDisplayText(" 2. Select", 0, 3, 1);
  display_->appendDisplayText(" 3. Attack", 0, 4, 1);
  display_->appendDisplayText(" 4. Info", 0, 5, 1);
  display_->appendDisplayText("*", 0, cursor_index + 2, 1);
}