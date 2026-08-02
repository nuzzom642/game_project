#ifndef SYSTEM_UTILITIES_H
#define SYSTEM_UTILITIES_H
#include <stddef.h>

enum read_result {READ_OK, READ_EMPTY, READ_TOO_LONG, READ_EOF};

enum read_result read_line(char *buf, size_t size);

enum read_result get_input_or_exit(char *buf, size_t size);

enum read_idle {ADVANCE, INTERACT, REST, IDLE_INVALID};

enum read_idle read_idle(void);

enum advance_result {NORTH, SOUTH, EAST, WEST, ADV_INVALID};

enum advance_result read_advance(void);

#endif // SYSTEM_UTILITIES_H
