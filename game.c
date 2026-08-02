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
    read_idle();
    return 0;
}
