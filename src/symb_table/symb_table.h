#ifndef SYMBOL_TABLE_H
#define SYMBOL_TABLE_H

#include <stdlib.h>
#include <string.h>

struct AST_TREE_NODE;  // ✅ forward declaration to break circular include

#define HASH_SIZE 101

typedef struct Symbol {
    char *name;
    struct AST_TREE_NODE *node;
    struct Symbol *next;
} Symbol;

typedef struct {
    Symbol *table[HASH_SIZE];
} SymbolTable;

struct AST_TREE_NODE *lookupSymbol(SymbolTable *symTable, const char *name);

#endif
