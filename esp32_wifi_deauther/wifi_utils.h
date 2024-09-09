// wifi_utils.h
#ifndef WIFI_UTILS_H
#define WIFI_UTILS_H

#include <WiFi.h>
#include <WiFiUdp.h>
#include <esp_wifi.h>
#include <string>
#include <vector>

struct wifiData {
  int num;
  std::vector<std::string> ssid;
  std::vector<std::string> bssid;
  std::vector<uint32_t> chanel;
  std::vector<float> signal;
};

class WiFi_Utils {
public:
  WiFi_Utils(bool random_mac);
  bool isInit = false;

  wifiData scanWifiList();
  bool init();
  bool connectToWifi(std::string SSID, std::string PASSWORD,
                     std::string HOSTNAME, const int MAX_ATTEMPTS,
                     const int TRIAL_DELAY);
  void sendDeauthPacket(const uint8_t *bssid, const uint8_t *sta);
  bool scanSinglePort(IPAddress ip, int port, int timeout_ms);
  std::vector<int> scanPortsInRange(IPAddress ip, int startPort, int endPort,
                                    int timeout_ms);

  std::string macAddress();
  wifiData wifi_list;

private:
  std::string mac_address;

  bool random_mac_enable = false;
  bool changeMACAddress();
};

#endif // WIFI_UTILS_H
