#include "tokenise.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int isNumber(const char *s) {
    for (int i = 0; s[i] != '\0'; i++) {
        if (!isdigit(s[i])) return 0;
    }
    return 1;
}

void tokenise(char *fileContent, Token **outList, int *outCount) {
    int capacity = 100;
    Token *tokenList = malloc(capacity * sizeof(Token));
    int tokenCount = 0;

    char buffer[256];
    int bufferIndex = 0;
    int i = 0;

    while (fileContent[i] != '\0') {
        if (fileContent[i] == '"') {
            i++;  // skip opening quote
            bufferIndex = 0;
            while (fileContent[i] != '"' && fileContent[i] != '\0') {
                buffer[bufferIndex++] = fileContent[i++];
            }
            buffer[bufferIndex] = '\0';
            Token token;
            token.type = STRING_LITERAL;
            token.str_val = strdup(buffer);
            token.name = strdup(buffer);
            tokenList[tokenCount++] = token;

            if (fileContent[i] == '"') i++;
            bufferIndex = 0;
        }
        else if (isalnum(fileContent[i])) {
            buffer[bufferIndex++] = fileContent[i];
            i++;
        }
        else if (fileContent[i] == ' ' || fileContent[i] == '\n' ||
                 fileContent[i] == ';' || fileContent[i] == '=' ||
                 fileContent[i] == '(' || fileContent[i] == ')' ||
                 fileContent[i] == '{' || fileContent[i] == '}') {

            if (bufferIndex > 0) {
                buffer[bufferIndex] = '\0';
                Token token;
                if (strcmp(buffer, "num") == 0) {
                    token.type = NUM_KEYWORD;
                    token.name = strdup("num");
                }
                else if (strcmp(buffer, "string") == 0) {
                    token.type = STRING_KEYWORD;
                    token.name = strdup("string");
                }
                else if (isNumber(buffer)) {
                    token.type = NUM_LITERAL;
                    token.int_val = atoi(buffer);
                    token.name = strdup(buffer);
                }
                else {
                    token.type = IDENTIFIER;
                    token.name = strdup(buffer);
                }
                tokenList[tokenCount++] = token;
                bufferIndex = 0;
            }

            if (fileContent[i] == ';') {
                Token token;
                token.type = SEMI_COLON;
                token.name = strdup(";");
                tokenList[tokenCount++] = token;
            }
            else if (fileContent[i] == '=') {
                Token token;
                token.type = EQUALS;
                token.name = strdup("=");
                tokenList[tokenCount++] = token;
            }
            else if (fileContent[i] == '(') {
                Token token;
                token.type = OPEN_PAR;
                token.name = strdup("(");
                tokenList[tokenCount++] = token;
            }
            else if (fileContent[i] == ')') {
                Token token;
                token.type = CLOSE_PAR;
                token.name = strdup(")");
                tokenList[tokenCount++] = token;
            }
            else if (fileContent[i] == '{') {
                Token token;
                token.type = OPEN_CURLY_PAR;
                token.name = strdup("{");
                tokenList[tokenCount++] = token;
            }
            else if (fileContent[i] == '}') {
                Token token;
                token.type = CLOSE_CURLY_PAR;
                token.name = strdup("}");
                tokenList[tokenCount++] = token;
            }
            i++;
        }
        else {
            i++;  // skip unknown characters
        }
    }

    // leftover buffer at EOF
    if (bufferIndex > 0) {
        buffer[bufferIndex] = '\0';
        Token token;
        if (strcmp(buffer, "num") == 0) {
            token.type = NUM_KEYWORD;
            token.name = strdup("num");
        }
        else if (strcmp(buffer, "string") == 0) {
            token.type = STRING_KEYWORD;
            token.name = strdup("string");
        }
        else if (isNumber(buffer)) {
            token.type = NUM_LITERAL;
            token.int_val = atoi(buffer);
            token.name = strdup(buffer);
        }
        else {
            token.type = IDENTIFIER;
            token.name = strdup(buffer);
        }
        tokenList[tokenCount++] = token;
    }

    *outList = tokenList;
    *outCount = tokenCount;
}