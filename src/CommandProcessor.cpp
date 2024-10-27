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
    stepper1.moveTo(0);
    //stepper1.moveTo(MOTOR_STEPS_PER_ROUND);
}

void CommandProcessor::printStatus() {
    if ( post )
        Serial.print("POST is running");

    Serial.print("Stepper1(P0): pos=");
    Serial.print(stepper1.currentPosition());
    Serial.print(", 2go=");
    Serial.print(stepper1.distanceToGo());
    Serial.println();
}

void CommandProcessor::stopAll() {
    Serial.println("EMERGENCY HALT");
    stepper1.stop();
}

void CommandProcessor::moveRelative(int motor, int steps) {
    Serial.print("Move Motor ");
    Serial.print(motor);
    Serial.print(" relative ");
    Serial.print(steps);
    Serial.println(" steps.");
    stepper1.moveTo(stepper1.currentPosition() + steps);
}

void CommandProcessor::moveAbsolute(int motor, int steps) {
    Serial.print("Move Motor ");
    Serial.print(motor);
    Serial.print(" to step ");
    Serial.print(steps);
    Serial.println(" .");
    stepper1.moveTo(stepper1.currentPosition() + steps);
}

void CommandProcessor::moveToHome(int motor) {
    Serial.print("Move Motor ");
    Serial.print(motor);
    Serial.print(" to home.");
    stepper1.moveTo(0);
}

void CommandProcessor::setCurrentPos(int motor, int steps) {
    Serial.print("Set Motor ");
    Serial.print(motor);
    Serial.print(" current position to step ");
    Serial.print(steps);
    Serial.println(" .");
    stepper1.setCurrentPosition(steps);
}

void CommandProcessor::setFeedrate(int motor, int feedrate) {
    stepper1.setMaxSpeed(feedrate);
}


void CommandProcessor::postOn() {
    post=true;
    if( stepper1.currentPosition() < MOTOR_STEPS_PER_ROUND )
        stepper1.moveTo( MOTOR_STEPS_PER_ROUND );
}


void CommandProcessor::processCommands() {
    if ( post ) {
        // run the stepper motors
        if (stepper1.distanceToGo() == 0)
            stepper1.moveTo(-stepper1.currentPosition());
    }

    stepper1.run();
}

