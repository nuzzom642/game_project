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
int read_menu_choice(int max){
    char input[10];
    enum read_result result;
    int user_choice;
    bool valid_choice;

    do{
        result = get_input_or_exit(input, sizeof(input));
        user_choice = atoi(input);
        if (result != READ_OK || user_choice > max || user_choice <= 0){
            valid_choice = false;
            printf("Invalid choice. Please try again.\n");}
        else {valid_choice = true;}
        }while (valid_choice == false);
   return user_choice;
}

enum read_idle read_idle(int current_room) {
    printf("%s", map[current_room].description);
    if (combat_necessary(current_room)) {printf("Defend yourself!\n");}
    printf("What would you like to do?\n"
        "1. Advance\n"
        "2. Interact\n"
        "3. Rest\n");
    
    int user_choice = read_menu_choice(3);

    switch (user_choice) {
        case 1:
        return ADVANCE;
        case 2:
        return INTERACT;
        case 3:
        return REST;
        default:
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
    int user_choice = read_menu_choice(count);
    
    printf("You advance through the door to the %s.\n", dir_names[direction[user_choice]]);
    *current_room = map[*current_room].exits[direction[user_choice]];
}

bool combat_necessary(int current_room) {
    return map[current_room].entities_present;
}

void read_rest(void) {
    printf("What would you like to do?\n");
    printf("1. Take a nap.\n");
    printf("2. View stats. \n");
    printf("3. Level Up!.\n");

    int user_choice = read_menu_choice(3);
    switch (user_choice){
        case 1:
        printf("You decide to take a nap. Restore health to max!\n");
        break;
        case 2:
        printf("Going to stats menu.\n");
        break;
        case 3:
        printf("Do you have enough experience?\n");
        break;
    }
    
}