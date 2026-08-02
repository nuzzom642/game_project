#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "system_utilities.h"

enum read_result read_line(char *buf, size_t size) {
    char *result = fgets(buf, size, stdin);
    if (result == NULL) {
        return READ_EOF;
    }
    size_t n = strcspn(buf, "\n");
    if (buf[n] == '\n') {buf[n] = '\0';}
    else{
        int c;
        while ((c = getchar()) != '\n' && c != EOF);
        return READ_TOO_LONG;
        }
    size_t start = 0;
    while (isspace((unsigned char)buf[start])) {start++;}
    size_t len = strlen(buf + start);
    while (len > 0 && isspace((unsigned char)buf[start + len - 1])) {len--;}
    memmove(buf, buf + start, len);
    buf[len] = '\0';
return buf[0] == '\0' ? READ_EMPTY : READ_OK;
}

enum read_result get_input_or_exit(char *buf, size_t size){
    enum read_result result = read_line(buf, size);
    if (result == READ_EOF) {
        printf("\nExiting the game.\n");
        exit(0);
    }
    return result;
}


enum read_idle read_idle(void) {
    printf("You enter a room.\n" 
        "What would you like to do?\n"
        "1. Advance\n"
        "2. Interact\n"
        "3. Rest\n");
    char input[10] = {0};
    enum read_result res = get_input_or_exit(input, sizeof(input));
    
    if (res != READ_OK) {
        printf("Invalid input. Please try again.\n");
        return IDLE_INVALID;
    }

    if (strcmp(input, "1") == 0) {
        return ADVANCE;
    } else if (strcmp(input, "2") == 0) {
        return INTERACT;
    } else if (strcmp(input, "3") == 0) {
        return REST;
    } else {
        printf("Invalid input. Please try again.\n");
        return IDLE_INVALID;
    }
}

