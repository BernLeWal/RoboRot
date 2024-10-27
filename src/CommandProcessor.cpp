//
// Created by wallisch on 27.10.2024.
//

#include "CommandProcessor.h"

AccelStepper stepper1 = AccelStepper(MOTOR1_TYPE, MOTOR1_PUL_PIN, MOTOR1_DIR_PIN );

CommandProcessor::CommandProcessor() : post(false) {
}

void CommandProcessor::setup() {
    // initialize the stepper driver
    stepper1.setMaxSpeed(MOTOR_DEFAULT_MAX_SPEED);
    stepper1.setAcceleration( MOTOR_DEFAULT_ACCELERATION);
    stepper1.moveTo(MOTOR_STEPS_PER_ROUND);
}

void CommandProcessor::printStatus() {
    if ( post )
        Serial.print("POST is running");
    Serial.print("Stepper1 currentPos=");
    Serial.print(stepper1.currentPosition());
    Serial.print(", distanceToGo=");
    Serial.print(stepper1.distanceToGo());
    Serial.println();
}

void CommandProcessor::processCommands() {
    if ( post ) {
        // run the stepper motors
        if (stepper1.distanceToGo() == 0)
            stepper1.moveTo(-stepper1.currentPosition());
    }

    stepper1.run();
}