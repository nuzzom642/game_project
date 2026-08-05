#include "entities.h"

struct player player1 =
{
    .base = {
        .max_health = 100, 
        .max_energy = 50, 
        .current_health = 100, 
        .current_energy = 50,
        .dexterity = 10,
        .level = 1},
        .experience = 0
};

struct entity goblin = {
    .max_health = 100,
    .max_energy = 25,
    .current_health = 100,
    .current_energy = 25,
    .dexterity = 10,
    .level = 1,
};