#include "hash_test.h"

extern int mock_alloc_limit;
extern int alloc_counter;

bool test_hash_all_functions()
{
    bool result = true;

    result = result && test_init_hash();
    result = result && test_destroy_hash();
    result = result && test_values();
    result = result && test_accumulate_array();
    result = result && test_hashing();
    result = result && test_init_node();
    result = result && test_destroy_node();

    return result;
}

bool test_init_hash()
{
    bool result = true;
    Node** hash;

    hash = init_hash();
    result = result && (hash != NULL);
    destroy_hash(hash);

    mock_alloc_limit = 0;
    alloc_counter = 0;
    hash = init_hash();
    result = result && (hash == NULL);

    mock_alloc_limit = -1;

    return result;
}

bool test_destroy_hash()
{
    Node** hash;

    hash = init_hash();
    destroy_hash(hash);

    hash = init_hash();
    hash[0] = init_node();
    hash[HASH_ARRAY_SIZE - 1] = init_node();
    destroy_hash(hash);

    destroy_hash(NULL);

    return true;
}

bool test_values()
{
    bool result = true;

    Node** hash;

    hash = init_hash();
    set_value(hash, "key", "value");
    result = result && (strcmp(get_value(hash, "key"), "value") == 0);

    set_value(hash, NULL, "value");
    result = result && (get_value(hash, NULL) == NULL);

    set_value(hash, "key", NULL);
    result = result && (get_value(hash, "key") == NULL);

    set_value(hash, NULL, NULL);
    result = result && (get_value(hash, NULL) == NULL);

    set_value(hash, "", "value");
    result = result && (strcmp(get_value(hash, ""), "value") == 0);

    set_value(hash, "key", "");
    result = result && (strcmp(get_value(hash, "key"), "") == 0);

    set_value(hash, "", "");
    result = result && (strcmp(get_value(hash, ""), "") == 0);

    destroy_hash(hash);

    mock_alloc_limit = 0;
    alloc_counter = 0;
    hash = init_hash();
    set_value(hash, "key", "value");
    result = result && (get_value(hash, "key") == NULL);

    set_value(hash, NULL, "value");
    result = result && (get_value(hash, NULL) == NULL);

    set_value(hash, "key", NULL);
    result = result && (get_value(hash, "key") == NULL);

    set_value(hash, NULL, NULL);
    result = result && (get_value(hash, NULL) == NULL);

    set_value(hash, "", "value");
    result = result && (get_value(hash, "") == NULL);

    set_value(hash, "key", "");
    result = result && (get_value(hash, "key") == NULL);

    set_value(hash, "", "");
    result = result && (get_value(hash, "") == NULL);

    mock_alloc_limit = -1;

    return result;
}

bool test_accumulate_array()
{
    bool result = true;

    result = result && (accumulate_array("11") == (2 * (int)'1'));
    result = result && (accumulate_array("") == 0);
    result = result && (accumulate_array("123") == (int)'1' + (int)'2' + (int)'3');
    result = result && (accumulate_array("0") == (int)'0');

    result = result && (accumulate_array("aa") == (2 * (int)'a'));
    result = result && (accumulate_array("azx") == (int)'a' + (int)'z' + (int)'x');
    result = result && (accumulate_array("y") == (int)'y');

    return result;
}

bool test_hashing()
{
    bool result = true;
    result = result && (hashing("11") == 2 + (2 * (int)'1'));
    result = result && (hashing("") == 0);
    result = result && (hashing(NULL) == 0);
    result = result && (hashing("123") == 3 + (int)'1' + (int)'2' + (int)'3');
    result = result && (hashing("0") == 1 + (int)'0');

    result = result && (hashing("aa") == 2 + (2 * (int)'a'));
    result = result && (hashing("azx") == 3 + (int)'a' + (int)'z' + (int)'x');
    result = result && (hashing("y") == 1 + (int)'y');

    return result;
}

bool test_init_node()
{
    bool result = true;
    Node *node;

    node = init_node();
    result = result && (node->key == NULL);
    result = result && (node->data == NULL);
    result = result && (node->next == NULL);
    result = result && (node->data_length == 0);
    destroy_node(node);

    mock_alloc_limit = 0;
    alloc_counter = 0;
    node = init_node();
    result = result && (node == NULL);

    mock_alloc_limit = -1;

    return result;
}

bool test_destroy_node()
{
    Node *node;

    destroy_node(NULL);
    node = init_node();
    node->key = strdup("");
    destroy_node(node);

    node = init_node();
    node->data = strdup("test");
    destroy_node(node);

    node = init_node();
    node->next = init_node();
    destroy_node(node->next);
    destroy_node(node);

    return true;
}