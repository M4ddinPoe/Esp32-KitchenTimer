# ESP 32 Kitchen Timer

Simple Timer to work with a ESP32 Microcontroller.  

The timer consists of a time display and a timer. Press the Mode button to switch between modes.

The time can be set by pressing and holding the Mode button in clock mode. First, set the hour using the Up/Down buttons. Press the Mode button to set the hour, then set the minutes using the Up/Down buttons. Press the Mode button again to set the time.

In timer mode, the timer is set and started directly by pressing the up button. When the timer has expired, an alarm is sounded via the piezo buzzer. The alarm is stopped by pressing any button.

Thanks to https://esp32io.com for Tutorials and help.

A case for printing with a 3D printer is still being created.

## Prerequisites
- **Hardware**: 
  - ESP32 board (e.g., ESP32 DevKit or ESP32S2).
  - Active Piezo Buzzer
  - TM1637 Display
  - 3 KY-004 Buttons
- **Software**:
    - For PlatformIO: [PlatformIO Core](https://platformio.org/) installed in your preferred IDE (e.g., CLion, VSCode).
    - For Arduino IDE: [Arduino IDE](https://www.arduino.cc/en/software) with ESP32 board support installed.

- **Default ESP32 Pin assignment**
  - Mode Button: 18
  - Down Buttons: 17
  - Up Button: 16
  - Buzzer: 21
  - Display Clk: 4
  - Display Dio: 5

## Getting Started with PlatformIO

### 1. Clone the Repository
```bash
git clone https://github.com/M4ddinPoe/Esp32-KitchenTimer
cd esp32-kitchen-timer
```

### 2. Open the Project
- Open the project folder in your IDE with PlatformIO support (e.g., CLion, VSCode).
- PlatformIO will automatically detect the project and install the required dependencies.

### 3. Configure the Project
- Ensure the platformio.ini file is correctly configured for your ESP32 board. Example:
```ini
[env\:esp32dev]
platform = espressif32
board = esp32dev
framework = arduino
``` 
### 4. Build and Upload
- Click the Build button in PlatformIO to compile the project.
- Connect your ESP32 board via USB.
- Click the Upload button to flash the firmware to your ESP32.

### 5. Monitor the Output
- Open the Serial Monitor in PlatformIO to view debug messages and interact with the timer.

## Getting Started with Arduino IDE

### 1. Clone the Repository
```bash
git clone https://github.com/M4ddinPoe/Esp32-KitchenTimer
cd esp32-kitchen-timer
```

### 2. Create a New Arduino Sketch
- Open the Arduino IDE.
- Create a new sketch (File > New).
- Save the sketch in a new folder (e.g., esp32_kitchen_timer_arduino).

### 3. Copy the Source Files
- Copy the contents of src/main.cpp from the PlatformIO project into the newly created .ino file in the Arduino IDE.
- Copy all other Header (*.h) and C++ files (*.cpp) from the src/ folder into the same folder as the .ino file.

### 4. Install ESP32 Board Support
- If you haven't already, add ESP32 board support to the Arduino IDE:
  - Open File > Preferences and add the following URL to the Additional Boards Manager URLs:
    ```bash
    https://raw.githubusercontent.com/espressif/arduino-esp32/gh-pages/package_esp32_index.json
    ```
  - Open Tools > Board > Boards Manager, search for esp32, and install the ESP32 platform

### 5. Select Your Board
- Go to Tools > Board and select your ESP32 board (e.g., ESP32 Dev Module).

### 6. Install Required Libraries
- Got to Sketch > Include Library > Manage Libraries.
- Add the TM1637 Library by vishay
- Add the ezButton Library by ArduinoGetStartet.com

### 7. Upload the Code
- Connect your ESP32 board via USB.
- Click the Upload button to compile and flash the firmware to your ESP32.

### 8. Monitor the Output
- Open the Serial Monitor (Tools > Serial Monitor) to view debug messages and interact with the timer.
