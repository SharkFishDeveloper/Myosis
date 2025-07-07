#ifndef FUNCTION_CALL_H
#define FUNCTION_CALL_H

typedef struct {
    char *func_name;   // e.g., "print"
    char **args;       // list of arguments
    int arg_count;
} FUNCTION_CALL;

#endif