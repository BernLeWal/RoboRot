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

    void postOn();
    void postOff() { post=false; }

    void setFeedrate(int motor, int feedrate);
    void moveSteps(int motor, int steps);
};


#endif //ROBOROT_COMMANDPROCESSOR_H
