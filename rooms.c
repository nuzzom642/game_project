#include <stdbool.h>
#include "rooms.h"

struct room map[ROOM_COUNT]= {
    [ENTRY_HALL] = {
    .name = "Entry Hall",
    .description = "You stand in a grand hall, warm orange light from braziers casting a soft glow upon the wooden walls. Doors lie to you north, south, east and west. \n",
    .explored = true,
    .exits = {[NORTH] = ROOM_1, [SOUTH] = NO_EXIT, [EAST] = ROOM_2, [WEST] = ROOM_3},
    },

    [ROOM_1] = {
        .name = "Room 1",
        .description = "This is room 1.",
        .explored = false,
        .exits = {[NORTH] = NO_EXIT, [SOUTH] = ENTRY_HALL, [EAST] = NO_EXIT, [WEST] = NO_EXIT},
    },

    [ROOM_2] = {
        .name = "Room 2",
        .description = "Room 2",
        .explored = false,
        .exits = {[NORTH] = NO_EXIT, [SOUTH] = NO_EXIT, [EAST] = NO_EXIT, [WEST] = ENTRY_HALL},
    },

    [ROOM_3] = {
        .name = "Room 3",
        .description = "Room 3",
        .explored = false,
        .exits = {[NORTH] = NO_EXIT, [SOUTH] = NO_EXIT, [EAST] = ENTRY_HALL, [WEST] = NO_EXIT},

    }

};