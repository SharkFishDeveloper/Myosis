#ifndef VAR_DEC_H
#define VAR_DEC_H
#include "../function_call/function_call.h"

typedef enum {
    VALUE_LITERAL,
    VALUE_FUNCTION_CALL
} VAR_VALUE_TYPE;

typedef struct{
    char *type; // String or num
    char *var_name; // a 
    VAR_VALUE_TYPE value_type;
    union{
        char *val; // = 10 or "hello"
        FUNCTION_CALL function_val; // or add(2,5)
    };
    
} VAR_DECLARATION;

#endif