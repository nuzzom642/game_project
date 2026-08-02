#include <stdio.h>
#include <stdbool.h>
#include "rooms.h"
#include "system_utilities.h"
#include "entities.h"

int main(void){
    printf("It was a dark and stormy night.\n");    
    int result;
    do {
    printf("What is your name?: ");
    result = read_line(player1.base.name, sizeof(player1.base.name));}
    while (result != READ_OK);
    int current = ENTRY_HALL;
    while (true) {
    enum read_idle reading = read_idle();
    switch(reading) {
        case ADVANCE:
        read_advance(current);
        break;
        case REST:
        printf("You are resting.\n");
        break;
        case INTERACT:
        printf("You are interacting.\n");
        break;
        case IDLE_INVALID:
        break;
    }
}
    return 0;
}
