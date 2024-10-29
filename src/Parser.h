//
// Created by wallisch on 27.10.2024.
//

#ifndef ROBOROT_PARSER_H
#define ROBOROT_PARSER_H

#include <Arduino.h>
#include "Tokenizer.h"
#include "CommandProcessor.h"

class Parser {
private:
    CommandProcessor& processor;

    int m_code;
    int g_code;
    int p_motor;
    int s_steps;
    int f_feedrate;

    // M-Codes:
    bool tryParseM(Token tokens[], int tokenCount, int& pos, String code);

    // G-Codes:
    bool tryParseG(Token tokens[], int tokenCount, int& pos, String code);

    // G-Code Parameters:
    bool tryParseP(Token tokens[], int tokenCount, int& pos);
    bool tryParseS(Token tokens[], int tokenCount, int& pos);
    bool tryParseF(Token tokens[], int tokenCount, int& pos);

    int tryReadToken(Token tokens[], int tokenCount, int& pos, TokenType type);
    int tryReadToken(Token tokens[], int tokenCount, int& pos, TokenType type, String value);

public:
    // Constructor
    Parser(CommandProcessor& processor);

    // Method to process commands
    void parseCommand(String cmd);
};

#endif //ROBOROT_PARSER_H
