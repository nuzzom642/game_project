#ifndef SYSTEM_UTILITIES_H
#define SYSTEM_UTILITIES_H
#include <stddef.h>

enum read_result {READ_OK, READ_EMPTY, READ_TOO_LONG, READ_EOF};

enum read_result read_line(char *buf, size_t size);

enum read_result get_input_or_exit(char *buf, size_t size);

enum read_idle {ADVANCE, INTERACT, REST, IDLE_INVALID};

enum read_idle read_idle(int *current);

void read_advance(int *current);

#endif // SYSTEM_UTILITIES_H
