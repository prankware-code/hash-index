#ifndef _DATA_H_
#define _DATA_H_

#include <sys/types.h>

enum State
{
    UNDEFINED = -1,
    SET,
    REMOVE
};

struct Data
{
    size_t key_size;
    size_t value_size;
    void *key;
    void *value;
    enum State state;
};

struct Data make_data(const char *key, const char *value, enum State state);
void destroy_data(struct Data *data);

#endif