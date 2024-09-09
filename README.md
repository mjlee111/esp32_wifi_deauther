# ESP32 wifi deauther with mini display

<img src="https://github.com/mjlee111/esp32_wifi_deauther/blob/master/docs/logo.png" alt="logo" width="200" height="200">

`esp32_wifi_deauther` is a custom firmware for the `ESP32` board that enables WiFi scanning, deauthentication attacks, and includes support for a 0.96-inch OLED display. The firmware is designed to leverage the powerful capabilities of the ESP32, making it a versatile tool for network analysis and testing. Schematics & PCB data is provided for the test.

## Table of Contents
- [About This Project](#about-this-project)
- [Prerequisites & Setup](#prerequisites--setup)
- [Circuit Preview](#circuit-preview)
- [Contributing](#contributing)
- [License](#license)
- [Contact](#contact)

## About This Project
### Key Features

- **WiFi Scanning:** Scans for available WiFi networks in the surrounding area and displays network details, such as SSID, signal strength, and channel information.
- **Deauthentication Attacks:** Provides the ability to perform deauthentication attacks on selected networks or clients, useful for network testing and penetration testing purposes.
- **0.96-inch OLED Display Support:** Integrates a small OLED display for real-time data visualization, showing information about detected networks, attack status, and other metrics.
- **Circuit Design:** Features a simple circuit design that connects the ESP32 board to the OLED display, allowing for easy assembly and portability.

### Hardware Requirements

- **ESP32 Board:** A low-cost, low-power microcontroller with built-in WiFi and Bluetooth capabilities.
- **0.96-inch OLED Display:** A small, monochrome display module that provides visual output of network data and actions.
- **Additional Components:** Basic electronic components like resistors and wires for connecting the OLED display to the ESP32.

### Use Cases

- **Network Security Testing:** Test the robustness and security of your WiFi networks.
- **Educational Purposes:** Learn about WiFi networks, how they operate, and common vulnerabilities.
- **Network Analysis:** Quickly scan and display information about nearby WiFi networks for analysis or troubleshooting.

### Disclaimer

**This project is intended for educational and ethical purposes only. The use of deauthentication attacks may be illegal in your country or region. Please ensure that you have proper authorization before using this firmware to test any network.**

## Prerequisites & Setup
### Required Libraries
- Adafruit GFX Library - [Adafruit Github][gfx-link]
- Adafruit SSD 1306 Library - [Adafruit Github][oled-link]
- espressif arduino core for esp32 - [Espressif Github][espressif-link] 

### Required Library Setup
1. Open `Arduino IDE`
2. Install OLED libraries: `Tools` -> `Manage Libraries` -> search `Adafruit GFX` & `Adafruit SSD1306` -> install

<img src="https://github.com/mjlee111/esp32_wifi_deauther/blob/master/docs/installation/adafruit-library-installation.png" alt="fig1">

3. Add `esp32 additional board manager URL`: `Files` -> `Preferences` -> add `https://raw.githubusercontent.com/espressif/arduino-esp32/gh-pages/package_esp32_dev_index.json` to `Additional Boards Manager URLs`

<img src="https://github.com/mjlee111/esp32_wifi_deauther/blob/master/docs/installation/preferences.png" alt="fig2">

4. Install `esp32 board manager`: `Tools` -> `Board` -> `Boards Manager` -> search `esp32` -> install `esp32 by Espressif Systems`

<img src="https://github.com/mjlee111/esp32_wifi_deauther/blob/master/docs/installation/esp32-board-manager-installation.png" alt="fig3">


## Circuit Preview
### Schematic
<img src="https://github.com/mjlee111/esp32_wifi_deauther/blob/master/docs/schematic.png" alt="schematic">

## Contributing
Feel free to submit issues, feature requests, and pull requests to improve the package.

## License
This project is licensed under the MIT License - see the [LICENSE][LICENSE] file for details.

## Contact
For any questions or feedback, please contact [menggu1234@naver.com][email].


[gfx-link]: https://github.com/adafruit/Adafruit-GFX-Library.git
[oled-link]: https://github.com/adafruit/Adafruit_SSD1306.git
[espressif-link]: https://github.com/espressif/arduino-esp32.git
[LICENSE]: https://github.com/mjlee111/esp32_wifi_deauther/blob/master/LICENSE
[email]: mailto:menggu1234@naver.com