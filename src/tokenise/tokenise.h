#ifndef TOKENISE_H
#define TOKENISE_H

#include "../tokens/token_type.h"
#include <stdlib.h>

// typedef enum {
    //     SEMI_COLON 
    //     NUM_KEYWORD,
    //     STRING_KEYWORD,
    //     EQUALS,
    //     OPEN_PAR,
    //     CLOSE_PAR,
    //     OPEN_CURLY_PAR,
    //     CLOSE_CURLY_PAR,
//     NUM_LITERAL,
//     STRING_LITERAL,
//     IDENTIFIER,
//     TOKEN_BIN_OP,
// } TOKEN_TYPE_ENUM;

// typedef enum {
//     BIN_PLUS,
//     BIN_MINUS,
//     BIN_DIVIDE,
//     BIN_MULTIPLY,
//     BIN_MODULO
// } BIN_OPS;


typedef struct {
    TOKEN_TYPE_ENUM type;
    char *name;
    union {
        char *str_val;
        int int_val;
    };
} Token;

void tokenise(char *fileContent, Token **outList,int *tokenCount);

#endif