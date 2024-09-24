#include <Arduino.h>

#include "setup.h"


void setup() {
    // write your initialization code here
    Serial.begin(115200);
    Serial.print("RoboROT Firmware ");
    Serial.println(APP_VERSION);

    // initialize digital pin LED_BUILTIN as an output.
    pinMode(LED_BUILTIN, OUTPUT);

    // initialize the stepper driver
    pinMode(MOTOR1_DIR_PIN, OUTPUT);
    pinMode( MOTOR1_PUL_PIN, OUTPUT);
}


bool blink = false;

void loop() {
    // LED
    blink = !blink;
    Serial.print(blink ? "LED is on " : "LED is off");
    digitalWrite(LED_BUILTIN, blink ? HIGH : LOW);   // switch the LED on/off (HIGH is the voltage level)
    Serial.print(" - ");

    // Stepper Motor
    digitalWrite( MOTOR1_DIR_PIN, blink ? HIGH : LOW);
    for (int i=0; i<1600; i++) {
        digitalWrite(MOTOR1_PUL_PIN, HIGH);
        delayMicroseconds(1000);
        digitalWrite(MOTOR1_PUL_PIN, LOW);
        delayMicroseconds(1000);
    }

    Serial.println();
    delay(100);                       // wait for a second
}

