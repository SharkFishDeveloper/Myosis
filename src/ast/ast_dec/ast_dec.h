#ifndef DECLARATION_H
#define DECLARATION_H

#include "../function_call/function_call.h"
#include "../var_dec/var_dec.h"
#include "symb_table/symb_table.h"  // ✅ safe to include now

typedef enum {
    AST_VAR_DECLARATION,
    AST_FUNCTION_CALL
} AST_TYPE;

typedef struct AST_TREE_NODE {
    AST_TYPE type;
    union {
        FUNCTION_CALL funcCall;
        VAR_DECLARATION varDec;
    };
    struct AST_TREE_NODE *next;
} AST_TREE_NODE;

typedef struct {
    AST_TREE_NODE *head;
    SymbolTable symbolTable;
} AST_TREE;

#endif
