//
// Created by wallisch on 27.10.2024.
//

#ifndef ROBOROT_TOKENIZER_H
#define ROBOROT_TOKENIZER_H


#include <Arduino.h>

#define MAX_TOKENS 50

enum TokenType {
    WHITESPACE,
    CHAR,
    NUMBER,
    SIGN,
    COMMA
};

struct Token {
    TokenType type;
    String value;
};

class Tokenizer {
public:
    Tokenizer() {}

    int tokenize(String cmd, Token tokens[]);
    void print(Token tokens[], int tokenCount);

private:
    bool isWhitespace(char c) {
        return c == ' ' || c == '\t' || c == '\n';
    }

    bool isChar(char c) {
        return isAlphaNumeric(c) && !isDigit(c);
    }

    bool isNumber(char c) {
        return isDigit(c);
    }

    bool isSign(char c) {
        return c == '+' || c == '-';
    }

    bool isComma(char c) {
        return c == '.' || c == ',';
    }

    void addToken(Token tokens[MAX_TOKENS], int &tokenCount, String &currentToken, TokenType &type) {
        if (currentToken.length()>0 && type!=TokenType::WHITESPACE && tokenCount < MAX_TOKENS) {
            tokens[tokenCount].value = currentToken;
            tokens[tokenCount].type = type;
            tokenCount++;
        }
    }
};


#endif //ROBOROT_TOKENIZER_H
