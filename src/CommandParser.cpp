//
// Created by wallisch on 27.10.2024.
//
#include "CommandParser.h"
#include "Tokenizer.h"




CommandParser::CommandParser(CommandProcessor &cmdProcessor)
: processor(cmdProcessor)
{
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

    // Tokenize the command
    Tokenizer tokenizer;
    Token tokens[MAX_TOKENS];
    int tokenCount = tokenizer.tokenize(cmd, tokens);
    //tokenizer.print(tokens, tokenCount);  // only for debugging

    // Parse the command:
    m_code = -1;
    g_code = -1;
    p_motor = -1;
    s_steps = 0;
    f_feedrate = 0;


    int currentPos = 0;
    while( currentPos < tokenCount ) {
        int backupPos = currentPos;

        tryParseM400( tokens, tokenCount, currentPos);
        tryParseM401( tokens, tokenCount, currentPos);

        tryParseG100( tokens, tokenCount, currentPos);
        tryParseP( tokens, tokenCount, currentPos);
        tryParseS( tokens, tokenCount, currentPos);
        tryParseF( tokens, tokenCount, currentPos);

        if ( backupPos == currentPos ) {
            Serial.print("Unknown character '");
            Serial.print(tokens[currentPos].value);
            Serial.print("' in command: ");
            Serial.println(cmd);
            currentPos++;   // nothing found, try next
        }
    }

    // Interpret the command
    if (m_code==400 ) {
        Serial.println("Executing command M400: Starting Power-On-Self-Test (POST)");
        processor.postOn();
    }
    if (m_code==401 ) {
        Serial.println("Executing command M401: Stop Power-On-Self-Test (POST)");
        processor.postOff();
    }
    if (g_code==100 && p_motor>=0 && s_steps!=0 ) {
        if ( f_feedrate!=0 )
            processor.setFeedrate(p_motor, f_feedrate);
        processor.moveSteps(p_motor, s_steps);
    }

}


bool CommandParser::tryParseM400(Token tokens[], int tokenCount, int &pos) {
    int myPos = pos;
    if ( tryReadToken(tokens, tokenCount, myPos, TokenType::CHAR, "M")<0 )
        return false;
    if ( tryReadToken(tokens, tokenCount, myPos, TokenType::NUMBER, "400") <0 )
        return false;

    m_code = 400;

    pos = myPos;
    return true;
}

bool CommandParser::tryParseM401(Token tokens[], int tokenCount, int &pos) {
    int myPos = pos;
    if ( tryReadToken(tokens, tokenCount, myPos, TokenType::CHAR, "M")<0 )
        return false;
    if ( tryReadToken(tokens, tokenCount, myPos, TokenType::NUMBER, "401") <0 )
        return false;

    m_code = 401;

    pos = myPos;
    return true;
}

bool CommandParser::tryParseG100(Token tokens[], int tokenCount, int &pos) {
    int myPos = pos;
    if ( tryReadToken(tokens, tokenCount, myPos, TokenType::CHAR, "G")<0 )
        return false;
    if ( tryReadToken(tokens, tokenCount, myPos, TokenType::NUMBER, "100") <0 )
        return false;

    g_code = 100;

    pos = myPos;
    return true;
}

bool CommandParser::tryParseP(Token tokens[], int tokenCount, int &pos) {
    int myPos = pos;
    if ( tryReadToken(tokens, tokenCount, myPos, TokenType::CHAR, "P")<0 )
        return false;
    int motorTokenNr = tryReadToken(tokens, tokenCount, myPos, TokenType::NUMBER);
    if ( motorTokenNr<0 )
        return false;
    int tryMotorNr = tokens[motorTokenNr].value.toInt();
    if ( tryMotorNr<0 || tryMotorNr>5 )
        return false;

    p_motor = tryMotorNr;

    pos = myPos;
    return true;
}

bool CommandParser::tryParseS(Token tokens[], int tokenCount, int &pos) {
    int myPos = pos;
    boolean signMinus = false;
    if ( tryReadToken(tokens, tokenCount, myPos, TokenType::CHAR, "S")<0 )
        return false;
    if ( tryReadToken(tokens, tokenCount, myPos, TokenType::SIGN, "-")>=0 )
        signMinus = true;
    if ( tryReadToken(tokens, tokenCount, myPos, TokenType::SIGN, "+")>=0 )
        signMinus = false;
    int stepsTokenNr = tryReadToken(tokens, tokenCount, myPos, TokenType::NUMBER);
    if ( stepsTokenNr<0 )
        return false;
    int trySteps = tokens[stepsTokenNr].value.toInt();
    if ( trySteps<-10000 || trySteps>10000 )
        return false;

    s_steps = signMinus ? -trySteps : trySteps;

    pos = myPos;
    return true;
}


bool CommandParser::tryParseF(Token tokens[], int tokenCount, int &pos) {
    int myPos = pos;
    if ( tryReadToken(tokens, tokenCount, myPos, TokenType::CHAR, "F")<0 )
        return false;
    int feedTokenNr = tryReadToken(tokens, tokenCount, myPos, TokenType::NUMBER);
    if ( feedTokenNr<0 )
        return false;
    int tryFeedrate = tokens[feedTokenNr].value.toInt();
    if ( tryFeedrate<-10000 || tryFeedrate>10000 )
        return false;

    f_feedrate = tryFeedrate;

    pos = myPos;
    return true;
}


int CommandParser::tryReadToken(Token tokens[], int tokenCount, int &pos, TokenType type) {
    if ( pos >= tokenCount )
        return -1;   // no tokens left
    if ( tokens[pos].type == type ) {
        return pos++;
    }
    return -1;
}

int CommandParser::tryReadToken(Token tokens[], int tokenCount, int &pos, TokenType type, String value) {
    if ( pos >= tokenCount )
        return -1;   // no tokens left
    if ( tokens[pos].type == type && tokens[pos].value == value) {
        return pos++;
    }
    return -1;
}