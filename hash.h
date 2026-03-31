#ifndef _HASH_H_
#define _HASH_H_

#include <string.h>

#ifndef HASH_ARRAY_SIZE
#define HASH_ARRAY_SIZE 1048576
#endif

typedef struct Node
{
    void            *key;
    void            *data;
    size_t          data_length;
    struct Node     *next;
} Node;

Node** init_hash();
void destroy_hash(Node **hash);

void set_value(Node** hash, char* key, char *value);
char *get_value(Node** hash, char* key);

#ifdef INCLUDE_UTIL
size_t accumulate_array(char *arr);
size_t hashing(char *str);
Node* init_node();
void destroy_node(Node* node);
#endif

#endif