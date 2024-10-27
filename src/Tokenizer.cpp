//
// Created by wallisch on 27.10.2024.
//

#include "Tokenizer.h"

int Tokenizer::tokenize(String cmd, Token tokens[MAX_TOKENS]) {
    int tokenCount = 0;
    String currentToken = "";
    TokenType currentType;

    for (unsigned int i = 0; i < cmd.length(); i++) {
        char c = cmd.charAt(i);

        if (isWhitespace(c)) {
            addToken(tokens, tokenCount, currentToken, currentType);
            currentToken = String(c);
            currentType = WHITESPACE;
        } else if (isChar(c)) {
            if (currentToken.length()>0 && currentType != CHAR) {
                addToken(tokens, tokenCount, currentToken, currentType);
                currentToken = "";
            }
            currentToken += c;
            currentType = CHAR;
        } else if (isNumber(c)) {
            if (currentToken.length()>0 && currentType != NUMBER) {
                addToken(tokens, tokenCount, currentToken, currentType);
                currentToken = "";
            }
            currentToken += c;
            currentType = NUMBER;
        } else if (isSign(c)) {
            addToken(tokens, tokenCount, currentToken, currentType);
            currentToken = String(c);
            currentType = SIGN;
        } else if (isComma(c)) {
            addToken(tokens, tokenCount, currentToken, currentType);
            currentToken = String(c);
            currentType = COMMA;
        } else {
            // Unrecognized characters are treated as individual CHAR tokens
            addToken(tokens, tokenCount, currentToken, currentType);
            currentToken = String(c);
            currentType = CHAR;
        }

        if (tokenCount >= MAX_TOKENS) {
            // Stop processing if the maximum number of tokens is reached
            break;
        }
    }

    // Add the last token if there's any left
    addToken(tokens, tokenCount, currentToken, currentType);

    return tokenCount;
}

void Tokenizer::print(Token tokens[], int tokenCount) {
    for (int i = 0; i < tokenCount; i++) {
        Serial.print("Token: ");
        Serial.print(tokens[i].value);
        Serial.print(" (Type: ");
        switch (tokens[i].type) {
            case WHITESPACE: Serial.println("WHITESPACE)"); break;
            case CHAR: Serial.println("CHAR)"); break;
            case NUMBER: Serial.println("NUMBER)"); break;
            case SIGN: Serial.println("SIGN)"); break;
            case COMMA: Serial.println("COMMA"); break;
        }
    }
}