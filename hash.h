#ifndef _HASH_H_
#define _HASH_H_

#include <string.h>

typedef struct Node
{
    void            *key;
    void            *data;
    size_t          data_length;
    struct Node     *next;
} Node;

Node** create_hash();
void delete_hash(Node **hash);

void set_value(Node** hash, char* key, char *value);
char *get_value(Node** hash, char* key);

#ifdef INCLUDE_UTIL
size_t accumulate_array(char *arr);
size_t hashing(char *str);
#endif

#endif