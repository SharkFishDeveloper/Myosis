#include "token_type.h"

const char* tokenTypeToString(TOKEN_TYPE_ENUM type) {
    switch(type) {
        case NUM_KEYWORD: return "NUM";
        case STRING_LITERAL: return "STRING";
        case EQUALS: return "EQUALS";
        case OPEN_PAR: return "OPEN_PAR";
        case CLOSE_PAR: return "CLOSE_PAR";
        case IDENTIFIER: return "IDENTIFIER";
        case SEMI_COLON: return "SEMI_COLON";
        default: return "UNKNOWN";
    }
}


