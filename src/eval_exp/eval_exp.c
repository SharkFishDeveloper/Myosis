#include "eval_exp.h"
#include "tokenise/tokenise.h"
#include "tokens/token_type.h"
#include <stdio.h>

int parseExpression(Token *tokens, int *i, int end);
int parseTerm(Token *tokens, int *i, int end);
int parseFactor(Token *tokens, int *i, int end);


int parseExpression(Token *tokens, int *i, int end) {
    int result = parseTerm(tokens, i, end);
    while (*i < end && tokens[*i].type == TOKEN_BIN_OP &&
           (tokens[*i].int_val == BIN_PLUS || tokens[*i].int_val == BIN_MINUS)) {
        int op = tokens[*i].int_val;
        (*i)++;
        int rhs = parseTerm(tokens, i, end);
        if (op == BIN_PLUS) result += rhs;
        else result -= rhs;
    }
    return result;
}

int parseTerm(Token *tokens, int *i, int end) {
    int result = parseFactor(tokens, i, end);
    while (*i < end && tokens[*i].type == TOKEN_BIN_OP &&
           (tokens[*i].int_val == BIN_MULTIPLY ||
            tokens[*i].int_val == BIN_DIVIDE ||
            tokens[*i].int_val == BIN_MODULO)) {
        int op = tokens[*i].int_val;
        (*i)++;
        int rhs = parseFactor(tokens, i, end);
        if (op == BIN_MULTIPLY) result *= rhs;
        else if (op == BIN_DIVIDE) result /= rhs;
        else result %= rhs;
    }
    return result;
}

int parseFactor(Token *tokens, int *i, int end) {
    if (*i < end && tokens[*i].type == OPEN_PAR) {
        (*i)++;
        int val = parseExpression(tokens, i, end);
        if (*i < end && tokens[*i].type == CLOSE_PAR) {
            (*i)++;
        } else {
            fprintf(stderr, "Error: Expected ')' at token %d\n", *i);
        }
        return val;
    } else if (*i < end && tokens[*i].type == NUM_LITERAL) {
        int val = tokens[*i].int_val;
        (*i)++;
        return val;
    } else {
        fprintf(stderr, "Error: Invalid token in expression at token %d: '%s'\n",
                *i, tokens[*i].name);
        exit(1);  // or return an error code
    }
}

int evaluateExpression(Token *tokens, int start, int end) {
    int i = start;
    return parseExpression(tokens, &i, end);
}
