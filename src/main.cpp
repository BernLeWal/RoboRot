#include <Arduino.h>
#include <AccelStepper.h>

#include "setup.h"

AccelStepper stepper1 = AccelStepper(MOTOR1_TYPE, MOTOR1_PUL_PIN, MOTOR1_DIR_PIN );

void setup() {
    // write your initialization code here
    Serial.begin(115200);
    Serial.print("RoboROT Firmware ");
    Serial.println(APP_VERSION);

    // initialize digital pin LED_BUILTIN as an output.
    pinMode(LED_BUILTIN, OUTPUT);

    // initialize the stepper driver
    stepper1.setMaxSpeed(MOTOR_DEFAULT_MAX_SPEED);
    stepper1.setAcceleration( MOTOR_DEFAULT_ACCELERATION);
    stepper1.moveTo(MOTOR_STEPS_PER_ROUND);
}


bool blink = false;
ulong display_time = 0;

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
        Serial.print("Stepper1 currentPos=");
        Serial.print(stepper1.currentPosition());
        Serial.print(", distanceToGo=");
        Serial.print(stepper1.distanceToGo());

        Serial.println();
    }

    // run the stepper motors
    if ( stepper1.distanceToGo() == 0)
        stepper1.moveTo(-stepper1.currentPosition());
    stepper1.run();
}

