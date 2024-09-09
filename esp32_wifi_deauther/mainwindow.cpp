// mainwindow.cpp
#include "mainwindow.h"

Mainwindow::Mainwindow()
{
  display_ = new Display(SCREEN_WIDTH, SCREEN_HEIGHT, OLED_RESET, SCREEN_ADDRESS, SDA_PIN, SCL_PIN);
  w_utils_ = new WiFi_Utils(SET_RANDOM_MAC);
  buttons_ = new Buttons(BUTTON_SEL_PIN, BUTTON_BACK_PIN, BUTTON_UP_PIN, BUTTON_DOWN_PIN);
}

Mainwindow::~Mainwindow()
{
  delete display_;
  delete w_utils_;
  delete buttons_;
}

void Mainwindow::init()
{
  display_->startDisplay();
  display_->setDisplayText("ESP32WifiDeautherV1.0", 0, 0, 1);
  display_->appendDisplayText("mjlee111", 0, 6, 2);
  display_->appendDisplayText("Starting ...", 0, 1, 1);
  if (SET_RANDOM_MAC)
  {
    display_->appendDisplayText("Changing MAC ...", 0, 2, 1);
  }
  w_utils_->init();
  if (w_utils_->isInit)
  {
    display_->appendDisplayText(w_utils_->macAddress(), 0, 3, 1);
    display_->appendDisplayText("Scanning ...", 0, 4, 1);
    w_utils_->wifi_list = w_utils_->scanWifiList();
  }
  buttons_->init();
  setMainPage();
  display_->appendDisplayText("*", 0, 2, 1);
}

void Mainwindow::loop()
{
  int num = buttons_->readButtons();
  switch (page)
  {
    case 0:
      handleMainPage(num);
      break;
    case 1:
      handleScanPage(num);
      break;

    default:
      break;
  }
}

void Mainwindow::handleBack()
{
  if (page != 0)
  {
    setMainPage();
    cursor_index = 0;
    display_->appendDisplayText("*", 0, cursor_index + 2, 1);
  }
  page = 0;
  on_page = false;
  return;
}

void Mainwindow::handleMainPage(int button)
{
  switch (button)
  {
    case 0:
      handleMainPageSel();
      break;
    case 1:
      handleBack();
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

void Mainwindow::setMainPage()
{
  display_->setDisplayText(" ESP32 Wifi Deauther ", 0, 0, 1);
  display_->appendDisplayText(" 1. Scan", 0, 2, 1);
  display_->appendDisplayText(" 2. Select", 0, 3, 1);
  display_->appendDisplayText(" 3. Attack", 0, 4, 1);
  display_->appendDisplayText(" 4. Info", 0, 5, 1);
}

void Mainwindow::handleMainPageUp()
{
  if (cursor_index == 0)
  {
    cursor_index = 3;
  }
  else
  {
    cursor_index--;
  }
  setMainPage();
  display_->appendDisplayText("*", 0, cursor_index + 2, 1);
}

void Mainwindow::handleMainPageDown()
{
  if (cursor_index == 3)
  {
    cursor_index = 0;
  }
  else
  {
    cursor_index++;
  }
  setMainPage();
  display_->appendDisplayText("*", 0, cursor_index + 2, 1);
}

void Mainwindow::handleMainPageSel()
{
  switch (cursor_index)
  {
    case 0:
      break;
    case 1:
      cursor_index = 0;
      setScanPage();
      display_->appendDisplayText("*", 0, 1, 1);
      break;
    case 2:
      break;
    case 3:
      cursor_index = 0;
      setInfoPage();
      break;
    default:
      break;
  }
}

void Mainwindow::handleScanPage(int button)
{
  switch (button)
  {
    case 0:
      handleScanPageSel();
      break;
    case 1:
      handleBack();
      break;
    case 2:
      handleScanPageUp();
      break;
    case 3:
      handleScanPageDown();
      break;
    default:
      break;
  }
}

void Mainwindow::setScanPage()
{
  page = 1;
  display_->setDisplayText("Scan", 0, 0, 1);
  display_->appendDisplayText(w_utils_->wifi_list.num, 6, 0, 1);
  display_->appendDisplayText("Available", 9, 0, 1);

  if (w_utils_->wifi_list.num == 0)
  {
    return;
  }

  int list_num = 2;
  if (cursor_index == 0)
  {
    display_->appendDisplayText("RESCAN", 1, 1, 1);
  }
  else
  {
    list_num = 1;
  }
  for (size_t i = cursor_index; i < w_utils_->wifi_list.num && i < cursor_index + 6; ++i)
  {
    std::string num_string = std::to_string(i + 1) + ".";
    display_->appendDisplayText(num_string, 1, list_num, 1);
    display_->appendDisplayText(w_utils_->wifi_list.ssid[i], 3, list_num, 1);
    list_num++;
  }
}

void Mainwindow::handleScanPageUp()
{
  if (cursor_index == 0)
  {
    cursor_index = w_utils_->wifi_list.num - 1;
  }
  else
  {
    cursor_index--;
  }
  setScanPage();
  display_->appendDisplayText("*", 0, 1, 1);
}

void Mainwindow::handleScanPageDown()
{
  if (cursor_index == w_utils_->wifi_list.num - 1)
  {
    cursor_index = 0;
  }
  else
  {
    cursor_index++;
  }
  setScanPage();
  display_->appendDisplayText("*", 0, 1, 1);
}

void Mainwindow::handleScanPageSel()
{
  switch (cursor_index)
  {
    case 0:
      display_->setDisplayText("Scanning ...", 0, 0, 1);
      w_utils_->wifi_list = w_utils_->scanWifiList();
      cursor_index = 0;
      setScanPage();
      display_->appendDisplayText("*", 0, 1, 1);
      break;

    default:
      switch (on_wifi_scan_info)
      {
        case false:
          display_->clearColArea(2, 7);
          display_->appendDisplayText("Information", 5, 0, 1);
          display_->appendDisplayText("BSSID :", 1, 2, 1);
          display_->appendDisplayText(w_utils_->wifi_list.bssid[cursor_index], 0, 3, 1);
          display_->appendDisplayText("Channel :", 1, 4, 1);
          display_->appendDisplayText(w_utils_->wifi_list.channel[cursor_index], 0, 5, 1);
          display_->appendDisplayText("Channel :", 1, 6, 1);
          display_->appendDisplayText(w_utils_->wifi_list.channel[cursor_index], 0, 7, 1);
          on_wifi_scan_info = true;
          break;

        default:
          setScanPage();
          display_->appendDisplayText("*", 0, 1, 1);
          on_wifi_scan_info = false;
          break;
      }
      break;
  }
}

void Mainwindow::setSelectPage()
{
}

void Mainwindow::setAttackPage()
{
}

void Mainwindow::setInfoPage()
{
  cursor_index = 0;
  page = 4;
  display_->setDisplayText("ESP32WifiDeautherV1.0 ", 0, 0, 1);
  display_->appendDisplayText("github.com/mjlee111", 0, 1, 1);
  display_->appendDisplayText("MAC:", 0, 2, 1);
  display_->appendDisplayText(w_utils_->macAddress(), 4, 2, 1);
}