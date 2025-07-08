#include "ast_dec.h"

typedef struct {
    char *name;
    char **params; // or a list of parameter structs
    int param_count;
    AST_TREE_NODE *body; // list of AST statements inside the function
} FUNCTION_DECLARATION;