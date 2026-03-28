#include "data.h"

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

struct Data make_data(char *key, char *value)
{
    struct Data data;

    data.key_size = strlen(key);
    data.value_size = strlen(value);

    data.key = calloc(data.key_size + 1, sizeof(char));
    data.value = calloc(data.value_size + 1, sizeof(char));
    memcpy(data.key, key, data.key_size);
    memcpy(data.value, value, data.value_size);

    return data;
}

void destroy_data(struct Data data)
{
    free(data.key);
    free(data.value);
    data.key_size = 0;
    data.value_size = 0;
}