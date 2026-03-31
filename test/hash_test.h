#ifndef _HASH_TEST_H_
#define _HASH_TEST_H_
#define INCLUDE_UTIL

#include "../hash.h"
#include <stdbool.h>

bool test_hash_all_functions();
bool test_init_hash();
bool test_destroy_hash();
bool test_values();
bool test_accumulate_array();
bool test_hashing();
bool test_init_node();
bool test_destroy_node();

#endif