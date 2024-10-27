//
// Contains the hardware and I/O-setup of the microcontroller board
// Created by wallisch on 24.09.2024.
//

#ifndef ROBOROT_SETUP_H
#define ROBOROT_SETUP_H

#define APP_VERSION "V0.2.0"

#define MOTOR_DEFAULT_MAX_SPEED 1000
#define MOTOR_DEFAULT_ACCELERATION 500
#define MOTOR_STEPS_PER_ROUND 200

// The bottommost motor
#define MOTOR1_TYPE 1
#define MOTOR1_DIR_PIN 22
#define MOTOR1_PUL_PIN 23

#define MOTOR2_TYPE 1
#define MOTOR2_DIR_PIN 24
#define MOTOR2_PUL_PIN 25

#define MOTOR3_TYPE 1
#define MOTOR3_DIR_PIN 26
#define MOTOR3_PUL_PIN 27

#define MOTOR4_TYPE 1
#define MOTOR4_DIR_PIN 28
#define MOTOR4_PUL_PIN 29

#define MOTOR5_TYPE 1
#define MOTOR5_DIR_PIN 30
#define MOTOR5_PUL_PIN 31

#define MOTOR6_TYPE 1
#define MOTOR6_DIR_PIN 32
#define MOTOR6_PUL_PIN 33

#endif //ROBOROT_SETUP_H
