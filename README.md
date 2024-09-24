# RoboRot

Firmware for a DIY robotic arm with 6 axis (degrees of freedom)
driven by a Arduino Due (or any other Arduino based board) 
using TB6600 Stepper Motor Drivers. 

## Pre-Requisites

- JetBrains CLion https://www.jetbrains.com/clion/ or another C/C++ IDE
  - install Plugin: PlatformIO
  - install Plugin: SerialMonitor
- PlatformIO https://platformio.org/install

## BOM

- Arduino Due https://store.arduino.cc/en-at/products/arduino-due
- TB6600 Stepper Motor Driver https://www.makerguides.com/tb6600-stepper-motor-driver-arduino-tutorial/


## Usage

- **Build** the firmware: ```pio run```  
  (or in CLION: Pio Plus Tasks --> Tasks/General/Build)
- **Upload** the firmware: ```pio run --target upload```  
  (or in CLION: Pio Plus Tasks --> Tasks/General/Upload)
- Run the **Unit Tests**: ```pio test```  
  (or in CLION: Pio Plus Tasks --> Tasks/Advanced/Test)