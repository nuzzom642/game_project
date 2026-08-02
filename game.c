#include <stdio.h>
#include <stdbool.h>
#include "system_utilities.h"
#include "entities.h"


int main(void){
    printf("It was a dark and stormy night.\n");    
    int result;
    do {
    printf("What is your name?: ");
    result = read_line(player1.base.name, sizeof(player1.base.name));}
    while (result != READ_OK);
    while (true) {
    enum read_idle reading = read_idle();
    switch(reading) {
        case ADVANCE:
        printf("You are advancing.\n");
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
