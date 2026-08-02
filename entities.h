#ifndef ENTITIES_H
#define ENTITIES_H

struct entity 
{
	char name[64];
	int max_health;
	int max_energy;
	int current_health;
	int current_energy;
    int level;
};

struct player
{
    struct entity base;
    int experience;
};

extern struct player player1;

#endif // ENTITIES_H