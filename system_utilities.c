#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>
#include "system_utilities.h"
#include "rooms.h"

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


enum read_idle read_idle(int *current_room) {
    printf("%s.\n", map[*current_room].description);
    if (combat_necessary(current_room)) {printf("Defend yourself!\n");}
    printf("What would you like to do?\n"
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

void read_advance(int *current_room) {
    printf("You are in %s.\n", room_names[*current_room]);
    int i = 1;
    int direction[DIR_COUNT + 1];
    for (int d = 0; d < DIR_COUNT; d++) {
        if (map[*current_room].exits[d] != NO_EXIT){
            printf("%d, Go through the door to the %s.\n", i, dir_names[d]);
            direction[i] = d;
            i++;
        }
    }
    
    int count = i - 1;
    char input[10] = {0};
    enum read_result res;
    int user_choice;
    do 
    {
        res = get_input_or_exit(input, sizeof(input));
        user_choice = atoi(input);

        if (res != READ_OK || user_choice > count || user_choice <= 0) {
            printf("Invalid input. Please try again.\n");}
        else {
            printf("You advance through the door to the %s.\n", dir_names[direction[user_choice]]);
            *current_room = map[*current_room].exits[direction[user_choice]];
            }
    } while (res != READ_OK || user_choice > count || user_choice <= 0);
}

bool combat_necessary(int *current_room) {
    return map[*current_room].entities_present;
}