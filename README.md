# RoboRot

Firmware for a DIY robotic arm with 6 axis (degrees of freedom)
driven by a Arduino Due (or any other Arduino based board) 
using TB6600 Stepper Motor Drivers. 

Build and flash it on the microcontroller. It communicates via (USB) serial 
port and will accept G-Code commands sent by the terminal.

## Pre-Requisites

- JetBrains CLion https://www.jetbrains.com/clion/ or another C/C++ IDE
  - install Plugin: PlatformIO
  - install Plugin: SerialMonitor
- PlatformIO https://platformio.org/install
- AccelStepper Library: https://www.airspayce.com/mikem/arduino/AccelStepper/  
  (is linked via [platform.ini](platformio.ini))

## BOM

- Arduino Due https://store.arduino.cc/en-at/products/arduino-due
- TB6600 Stepper Motor Driver https://www.makerguides.com/tb6600-stepper-motor-driver-arduino-tutorial/


## Usage

### Firmware run on the hardware for the robotic arm
- **Build** the firmware: ```pio run```  
  (or in CLION: Pio Plus Tasks --> Tasks/General/Build)
- **Upload** the firmware: ```pio run --target upload```  
  (or in CLION: Pio Plus Tasks --> Tasks/General/Upload)


### Automated Tasks/Tests (CI/CD)
- Run the **Unit Tests**: ```pio test```  
  (or in CLION: Pio Plus Tasks --> Tasks/Advanced/Test)