#include <stdlib.h>
#include <stdio.h>
#include "src/tokens/token_type.h"
#include "src/tokenise/tokenise.h"

int main() {
    FILE *mainFile = NULL;
    errno_t err = fopen_s(&mainFile, "../main.my", "r");
    if (err != 0 || mainFile == NULL) {
        printf("Could not open main.my file\n");
        return 1;
    }

    fseek(mainFile,0,SEEK_END);
    long fileSize = ftell(mainFile);
    rewind(mainFile);

    char *fileContent = malloc(fileSize + 1);

    if(fileContent == NULL)printf("File is empty");
    size_t bytesRead = fread(fileContent, 1, fileSize, mainFile);
    fileContent[bytesRead] = '\0';

    Token *tokens;
    int tokenCount = 0;
    tokenise(fileContent, &tokens, &tokenCount);
    for (int i = 0; i < tokenCount; i++) {
    printf("Token[%d]: ", i);
    switch (tokens[i].type) {
        case NUM_KEYWORD:
            printf("NUM_KEYWORD, name=%s\n", tokens[i].name);
            break;
        case STRING_KEYWORD:
            printf("STRING_KEYWORD, name=%s\n", tokens[i].name);
            break;
        case IDENTIFIER:
            printf("IDENTIFIER, name=%s\n", tokens[i].name);
            break;
        case NUM_LITERAL:
            printf("NUM_LITERAL, value=%d\n", tokens[i].int_val);
            break;
        case STRING_LITERAL:
            printf("STRING_LITERAL, value=%s\n", tokens[i].str_val);
            break;
        case EQUALS:
            printf("EQUALS (=)\n");
            break;
        case SEMI_COLON:
            printf("SEMI_COLON (;)\n");
            break;
        case OPEN_PAR:
            printf("OPEN_PAR\n");
            break;
        case CLOSE_PAR:
            printf("CLOSE_PAR\n");
            break;
        case OPEN_CURLY_PAR:
            printf("OPEN_CURLY_PAR\n");
            break;
        case CLOSE_CURLY_PAR:
            printf("CLOSE_CURLY_PAR\n");
            break;
        case TOKEN_BIN_OP:
            switch (tokens[i].int_val) {
                case BIN_PLUS:
                    printf("BIN_OP: +\n");
                    break;
                case BIN_MINUS:
                    printf("BIN_OP: -\n");
                    break;
                case BIN_MULTIPLY:
                    printf("BIN_OP: *\n");
                    break;
                case BIN_DIVIDE:
                    printf("BIN_OP: /\n");
                    break;
                case BIN_MODULO:
                    printf("BIN_OP: %%\n");
                    break;
                default:
                    printf("BIN_OP: unknown\n");
            }
            break;
        default:
            printf("UNKNOWN\n");
    }
}
    return 0;
}
