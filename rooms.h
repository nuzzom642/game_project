#ifndef ROOMS_H
#define ROOMS_H

struct room
{
    char name[64];
    char description[256];
    struct room *north;
    struct room *south;
    struct room *east;
    struct room *west;

};

#endif // ROOMS_H