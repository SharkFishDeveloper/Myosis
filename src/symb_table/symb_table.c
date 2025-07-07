#include <stdlib.h>
#include <string.h>
#include "ast/ast_dec/ast_dec.h"



unsigned int hash(const char *s) {
    unsigned int hashval = 0;
    for (; *s != '\0'; s++)
        hashval = *s + 31 * hashval;
    return hashval % HASH_SIZE;
}

void insertSymbol(SymbolTable *symTable, const char *name, AST_TREE_NODE *node) {
    unsigned int idx = hash(name);
    Symbol *newSym = (Symbol *)malloc(sizeof(Symbol));
    newSym->name = strdup(name);
    newSym->node = node;
    newSym->next = symTable->table[idx];
    symTable->table[idx] = newSym;
}


AST_TREE_NODE *lookupSymbol(SymbolTable *symTable, const char *name) {
    unsigned int idx = hash(name);
    for (Symbol *sym = symTable->table[idx]; sym != NULL; sym = sym->next) {
        if (strcmp(sym->name, name) == 0) {
            return sym->node;
        }
    }
    return NULL;
}
