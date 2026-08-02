#include "entities.h"

struct player player1 =
{
    .base = {.max_health = 100, .max_energy = 50, .current_health = 100, .current_energy = 50, .level = 1},
    .experience = 0
};
