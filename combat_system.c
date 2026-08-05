#include "combat_system.h"

void combat_loop(struct player *player1) {
    //Populate combat//
    bool player_turn = determine_first_combatant(*player1, goblin);
    printf("%d.\n", player_turn);
    /* Enemies:
        Track enemy HP
        Implement enemy turn*/
    /* Player:
        Track player HP
        Player turn controls*/
}

bool determine_first_combatant(struct player player1, struct entity enemy) 
{
    if (player1.base.dexterity > enemy.dexterity) {
        return true;
    }else {return false;}
}