#include "../../tokenise/tokenise.h"
#include <stdio.h>
#include "create_ast.h"
#include "../../tokenise/tokenise.h"
#include "../util/token_to_string/token_to_string.h"


void createAst(Token *tokens,int tokenCount){
    for(int i = 0; i < tokenCount;i++){
        printf("%s -> %s\n", tokenTypeToStringVerbose(tokens[i]),tokens[i].name);
    }
}