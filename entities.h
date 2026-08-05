#ifndef ENTITIES_H
#define ENTITIES_H

struct entity 
{
	char name[64];
	int max_health;
	int max_energy;
	int current_health;
	int current_energy;
	int dexterity;
    int level;
};

struct player
{
    struct entity base;
    int experience;
};

extern struct player player1;

extern struct entity goblin;
#endif // ENTITIES_H