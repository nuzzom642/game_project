#ifndef COMBAT_SYSTEM_H
#define COMBAT_SYSTEM_H

#include <stdio.h>
#include <stdbool.h>
#include "entities.h"

void combat_loop(struct player *player1);

bool determine_first_combatant(struct player player1, struct entity enemy);

#endif //COMBAT_SYSTEM_H//