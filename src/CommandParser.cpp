//
// Created by wallisch on 27.10.2024.
//
#include "CommandParser.h"


CommandParser::CommandParser(CommandProcessor &cmdProcessor) : processor(cmdProcessor) {
}

void CommandParser::parseCommand(String cmd) {
    // Prepare the command:
    // - Remove comments (starting with ';' until the end of the line
    int semicolonPos = cmd.indexOf(';');  // Find the position of the semicolon
    if (semicolonPos != -1) {
        // If a semicolon is found, remove everything after it
        cmd = cmd.substring(0, semicolonPos);
    }

    // Whitespace at the begin and end is ignored
    cmd.trim();
    // All G-Code/M-Code commands ignore the case, so continue with uppercase
    cmd.toUpperCase();

    // Interpret the commands:
    // Command "M400" - Example action
    if (cmd == "M400") {
        Serial.println("Executing command M400: Starting Power-On-Self-Test (POST)");
        processor.postOn();
    }
        // Command "M401" - Example action
    else if (cmd == "M401") {
        Serial.println("Executing command M401: Stop Power-On-Self-Test (POST)");
        processor.postOff();
    }
        // Unknown command
    else {
        Serial.println("Unknown command: " + cmd);
    }
}

