//
// Created by wallisch on 27.10.2024.
//

#ifndef ROBOROT_COMMANDPARSER_H
#define ROBOROT_COMMANDPARSER_H

#include <Arduino.h>
#include "Tokenizer.h"
#include "CommandProcessor.h"

class CommandParser {
private:
    CommandProcessor& processor;

    int m_code;
    int g_code;
    int p_motor;
    int s_steps;
    int f_feedrate;

    bool tryParseM400(Token tokens[], int tokenCount, int& pos);
    bool tryParseM401(Token tokens[], int tokenCount, int& pos);

    bool tryParseG100(Token tokens[], int tokenCount, int& pos);
    bool tryParseP(Token tokens[], int tokenCount, int& pos);
    bool tryParseS(Token tokens[], int tokenCount, int& pos);
    bool tryParseF(Token tokens[], int tokenCount, int& pos);

    int tryReadToken(Token tokens[], int tokenCount, int& pos, TokenType type);
    int tryReadToken(Token tokens[], int tokenCount, int& pos, TokenType type, String value);

public:
    // Constructor
    CommandParser(CommandProcessor& processor);

    // Method to process commands
    void parseCommand(String cmd);
};

#endif //ROBOROT_COMMANDPARSER_H
