#include "token_to_string.h"
#include "../src/tokenise/tokenise.h"

const char *tokenTypeToStringVerbose(Token token) {
    switch (token.type) {
        case NUM_KEYWORD:
            return "NUM_KEYWORD";
        case STRING_KEYWORD:
            return "STRING_KEYWORD";
        case IDENTIFIER:
            return "IDENTIFIER";
        case NUM_LITERAL:
            return "NUM_LITERAL";
        case STRING_LITERAL:
            return "STRING_LITERAL";
        case EQUALS:
            return "EQUALS";
        case SEMI_COLON:
            return "SEMI_COLON";
        case OPEN_PAR:
            return "OPEN_PAR";
        case CLOSE_PAR:
            return "CLOSE_PAR";
        case OPEN_CURLY_PAR:
            return "OPEN_CURLY_PAR";
        case CLOSE_CURLY_PAR:
            return "CLOSE_CURLY_PAR";
        case TOKEN_BIN_OP:
            switch (token.int_val) {
                case BIN_PLUS:
                    return "OP_PLUS";
                case BIN_MINUS:
                    return "OP_MINUS";
                case BIN_MULTIPLY:
                    return "OP_MULTIPLY";
                case BIN_DIVIDE:
                    return "OP_DIVIDE";
                case BIN_MODULO:
                    return "OP_MODULO";
                default:
                    return "OP_UNKNOWN";
            }
        default:
            return "UNKNOWN";
    }
}
