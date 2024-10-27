//
// Created by wallisch on 27.10.2024.
//

#ifndef ROBOROT_COMMANDPARSER_H
#define ROBOROT_COMMANDPARSER_H

#include <Arduino.h>
#include "CommandProcessor.h"

class CommandParser {
private:
    CommandProcessor& processor;

public:
    // Constructor
    CommandParser(CommandProcessor& processor);

    // Method to process commands
    void parseCommand(String cmd);
};

#endif //ROBOROT_COMMANDPARSER_H
