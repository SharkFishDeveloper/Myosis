
#ifndef EVAL_EXP_H
#define EVAL_EXP_H

#include "tokenise/tokenise.h"
#include "tokens/token_type.h"

int parseExpression(Token *tokens, int *i, int end);
int parseTerm(Token *tokens, int *i, int end);
int parseFactor(Token *tokens, int *i, int end);

#endif

