#include <Arduino.h>

#include "CommandParser.h"
#include "CommandProcessor.h"


CommandProcessor processor;
CommandParser parser(processor);


void setup() {
    // write your initialization code here
    Serial.begin(115200);
    Serial.print("RoboROT Firmware ");
    Serial.println(APP_VERSION);

    // initialize digital pin LED_BUILTIN as an output.
    pinMode(LED_BUILTIN, OUTPUT);

    processor.setup();
}


bool blink = false;
ulong display_time = 0;

String command = "";

void loop() {
    // display update every second
    if ( millis() > (display_time + 1000) ) {
        display_time = millis();

        // LED
        blink = !blink;
        Serial.print(blink ? "LED is on " : "LED is off");
        digitalWrite(LED_BUILTIN, blink ? HIGH : LOW);   // switch the LED on/off (HIGH is the voltage level)
        Serial.print(" - ");

        // Stepper Motor
        processor.printStatus();
    }

    // Command input from the serial interface
    while (Serial.available() > 0) {
        char incomingChar = Serial.read();

        if (incomingChar == '\n') {
            Serial.print("Received command: ");
            Serial.println(command);

            // Process the commands
            parser.parseCommand(command);

            command = "";
        } else {
            command += incomingChar;
        }
    }


    // Execute the robotic arm control
    processor.processCommands();
}

