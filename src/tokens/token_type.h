#ifndef TOKEN_TYPE
#define TOKEN_TYPE

typedef enum {
    NUM_LITERAL,
    STRING_LITERAL,
    NUM_KEYWORD,
    STRING_KEYWORD,
    EQUALS,
    OPEN_PAR,
    CLOSE_PAR,
    OPEN_CURLY_PAR,
    CLOSE_CURLY_PAR,
    IDENTIFIER,
    TOKEN_BIN_OP,
    SEMI_COLON
} TOKEN_TYPE_ENUM;

typedef enum {
    BIN_PLUS,
    BIN_MINUS,
    BIN_DIVIDE,
    BIN_MULTIPLY,
    BIN_MODULO
} BIN_OPS;

const char* tokenTypeToString(TOKEN_TYPE_ENUM type);

#endif