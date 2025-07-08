#include "tokenise/tokenise.h"
#include <stdio.h>
#include "create_ast.h"
#include <string.h>
#include "eval_exp/eval_exp.h"
#include "../ast_dec/ast_dec.h"

void createAst(Token *tokens,int tokenCount){
    AST_TREE_NODE *head = NULL, *tail = NULL;
    for(int i = 0; i < tokenCount;i++){
        if (tokens[i].type == NUM_KEYWORD || tokens[i].type == STRING_KEYWORD) {
            int varType = tokens[i].type;
            char *type = tokens[i].name;
            char *var_name = tokens[i + 1].name;
            i += 2;
            if(tokens[i].type == EQUALS) {
                i++;
                VAR_DECLARATION varDec;
                varDec.type = strdup(type);   // like num a = 10; -> num
                varDec.var_name = strdup(var_name);   // like num a = 10; -> a
                
                int start = i;
                while (i < tokenCount && tokens[i].type != SEMI_COLON) {
                    i++;
                }
                int end = i;
                if (end - start == 1) {
                    if(tokens[start].type == NUM_LITERAL && varType == NUM_KEYWORD){
                        printf("Declared %s %s = %d\n", type, var_name, tokens[start].int_val);
                        varDec.valType = INT_VALUE;
                        varDec.int_val = tokens[start].int_val;
                    }
                    else if(tokens[start].type == STRING_LITERAL && varType == STRING_KEYWORD){
                        printf("Declared %s %s = %s\n", type, var_name, tokens[start].str_val);
                        varDec.valType = STRING_VALUE;
                        printf("%d",varDec.valType);
                        varDec.str_val = strdup(tokens[start].str_val);
                    }
                    else{
                        printf("Incorrect type declaration for %s",var_name);
                    }
                }
                else {
                    int i = start;
                    int value = parseExpression(tokens, &i, end);
                    printf("Declared %s %s = %d (evaluated)\n", type, var_name, value);
                    varDec.valType = INT_VALUE;
                    varDec.int_val = value;
                }
                AST_TREE_NODE *node = malloc(sizeof(AST_TREE_NODE));
                node->type = AST_VAR_DECLARATION;
                node->varDec = varDec;
                node->next = NULL;

                // ✅ Add to linked list
                if (!head) {
                    head = tail = node;
                } else {
                    tail->next = node;
                    tail = node;
                }
            }
        }
    }
    printf("\nFinal AST:\n");
    AST_TREE_NODE *curr = head;
    while (curr) {
        if (curr->type == AST_VAR_DECLARATION) {
            printf("AST_NODE: %s %s = ", curr->varDec.type, curr->varDec.var_name);
            if (curr->varDec.valType == INT_VALUE) {
                    printf("  %d\n", curr->varDec.int_val);
            }
            else if (curr->varDec.valType == STRING_VALUE) {
                printf("\"%s\"\n", curr->varDec.str_val);
            }
            // else{
            //     printf("%d",curr->varDec.valType == INT_VALUE);
            // }
        }
        curr = curr->next;
    }
}