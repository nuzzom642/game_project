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
    int current_room = ENTRY_HALL;
    while (true) {
    enum read_idle reading = read_idle(current_room);
    switch(reading) {
        case ADVANCE:
        read_advance(&current_room);
        break;
        case REST:
        read_rest();
        break;
        break;
        case IDLE_INVALID:
        break;
    }
}
    return 0;
}
