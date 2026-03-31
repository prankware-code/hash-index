#include "hash.h"

#include <errno.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>


Node* init_node()
{
    Node *node = (Node *)malloc(sizeof(Node));

    if (!node)
        return NULL;

    node->key = NULL;
    node->data = NULL;
    node->data_length = 0;
    node->next = NULL;

    return node;
}

void destroy_node(Node* node)
{
    if (!node)
        return;
    if (node->data)
        free(node->data);
    if (node->key)
        free(node->key);
    free(node);
}

size_t accumulate_array(char *arr)
{
    size_t result = 0;

    if (arr == NULL)
    {
        return 0;
    }

    for (size_t i = 0; arr[i] != '\0'; ++i)
    {
        result += (int)arr[i];
    }

    return result;
}

size_t hashing(char *str)
{
    if (str == NULL || HASH_ARRAY_SIZE == 0)
        return 0;
    return (strlen(str) + accumulate_array(str)) % HASH_ARRAY_SIZE;
}

Node** init_hash()
{
    Node **hash = (Node **)calloc(HASH_ARRAY_SIZE, sizeof(Node *));

    return hash;
}

void destroy_hash(Node **hash)
{
    if (!hash)
        return;

    for (size_t i = 0; i < HASH_ARRAY_SIZE; ++i)
    {
        while (hash[i])
        {
            Node *next = hash[i]->next;
            destroy_node(hash[i]);
            hash[i] = next;
        }
    }

    free(hash);
}

void set_value(Node** hash, char* key, char *value)
{
    Node *node, *next;
    size_t idx = hashing(key);

    if (hash == NULL || key == NULL)
    {
        return;
    }

    node = init_node();
    node->key = strdup(key);

    if (value)
    {
        node->data = strdup(value);
        node->data_length = strlen(node->data);
    }

    if (hash[idx] == NULL)
    {
        hash[idx] = node;
        return;
    }

    next = hash[idx];

    while(next->next)
    {
        if (strcmp(next->key, node->key) == 0)
            break;
        next = next->next;
    }

    if (strcmp(next->key, node->key) == 0)
    {
        free(next->data);
        next->data = NULL;
        if (node->data)
            next->data = strdup(node->data);
        next->data_length = node->data_length;
        destroy_node(node);
        return;
    }

    next->next = node;
}

char *get_value(Node** hash, char* key)
{
    size_t idx = hashing(key);
    Node *node;

    if (hash == NULL || key == NULL)
    {
        return NULL;
    }

    node = hash[idx];
    while(node)
    {
        if (strcmp(node->key, key) == 0)
        {
            return (char *)(node->data);
        }
        node = node->next;
    }

    return NULL;
}
