#ifndef DECLARATION_H
#define DECLARATION_H
#include "../function_call/function_call.h" 
#include "../var_dec/var_dec.h"

typedef enum {
    AST_VAR_DECLARATION,
    AST_FUNCTION_CALL
} AST_TYPE;

typedef struct AST_TREE_NODE
{
    AST_TYPE type;
    union {
        FUNCTION_CALL funcCall;
        VAR_DECLARATION varDec;
    };
    struct AST_TREE_NODE *next;  // to chain many of them
} AST_TREE_NODE;


typedef struct {
    AST_TREE_NODE *head;
} AST_TREE;

#endif