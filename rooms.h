#ifndef ROOMS_H
#define ROOMS_H
#include <stdbool.h>

enum direction {NORTH, SOUTH, EAST, WEST, DIR_COUNT};

#define NO_EXIT (-1)

struct room
{
    char name[64];
    char description[256];
    bool explored;
    int exits[DIR_COUNT];

};

enum room_id {ENTRY_HALL, ROOM_1, ROOM_2, ROOM_3, ROOM_COUNT};

extern const char *const dir_names[DIR_COUNT];

extern struct room map[];

extern const char *const room_names[ROOM_COUNT];

#endif // ROOMS_H