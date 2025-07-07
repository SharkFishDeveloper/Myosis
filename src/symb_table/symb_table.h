#ifndef SYMBOL_TABLE_H
#define SYMBOL_TABLE_H


#include <stdlib.h>
#include <string.h>
#include "ast/ast_dec/ast_dec.h"

#define HASH_SIZE 101

typedef struct AST_TREE_NODE AST_TREE_NODE;

typedef struct Symbol {
    char *name;
    AST_TREE_NODE *node;
    struct Symbol *next;  // for collision chaining
} Symbol;

typedef struct {
    Symbol *table[HASH_SIZE];
} SymbolTable;

AST_TREE_NODE *lookupSymbol(SymbolTable *symTable, const char *name);

#endif