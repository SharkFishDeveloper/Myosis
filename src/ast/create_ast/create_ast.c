#include "tokenise/tokenise.h"
#include <stdio.h>
#include "create_ast.h"
#include <string.h>
#include "eval_exp/eval_exp.h"
#include "../ast_dec/ast_dec.h"

void createAst(Token *tokens,int tokenCount){
    AST_TREE_NODE astTree ;
    for(int i = 0; i < tokenCount;i++){
        if (tokens[i].type == NUM_KEYWORD || tokens[i].type == STRING_KEYWORD) {
            int varType = tokens[i].type;
            char *type = tokens[i].name;
            char *var_name = tokens[i + 1].name;
            i += 2;
            if(tokens[i].type == EQUALS) {
                i++;
                int start = i;
                while (i < tokenCount && tokens[i].type != SEMI_COLON) {
                    i++;
                }
                int end = i;
                if (end - start == 1) {
                    if(tokens[start].type == NUM_LITERAL && varType == NUM_KEYWORD){
                        printf("Declared %s %s = %d\n", type, var_name, tokens[start].int_val);
                    }
                    else if(tokens[start].type == STRING_LITERAL && varType == STRING_KEYWORD){
                        printf("Declared %s %s = %s\n", type, var_name, tokens[start].str_val);
                    }
                    else{
                        printf("Incorrect type declaration for %s",var_name);
                    }
                }
                else {
                    int i = start;
                    int value = parseExpression(tokens, &i, end);
                    printf("Declared %s %s = %d (evaluated)\n", type, var_name, value);
                }
            }
        }
    }
}