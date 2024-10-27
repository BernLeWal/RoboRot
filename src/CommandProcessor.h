//
// Created by wallisch on 27.10.2024.
//

#ifndef ROBOROT_COMMANDPROCESSOR_H
#define ROBOROT_COMMANDPROCESSOR_H

#include <AccelStepper.h>

#include "setup.h"


class CommandProcessor {
private:
    bool post;

public:
    CommandProcessor();

    void setup();
    void printStatus();
    void processCommands();

    void stopAll();

    void setFeedrate(int motor, int feedrate);
    void moveRelative(int motor, int steps);
    void moveAbsolute(int motor, int steps);
    void moveToHome(int motor);
    void setCurrentPos(int motor, int steps);

    void postOn();
    void postOff() { post=false; }
};


#endif //ROBOROT_COMMANDPROCESSOR_H
