#include "split_test.h"
#include "data_test.h"
#include "hash_test.h"
#include <stdio.h>
#include <stddef.h>

int mock_alloc_limit = -1; // -1 значит "не ограничивать"
int alloc_counter = 0;

extern void* __real_calloc(size_t nmemb, size_t size);

void* __wrap_calloc(size_t nmemb, size_t size) {
    alloc_counter++;

    if (mock_alloc_limit >= 0 && alloc_counter > mock_alloc_limit) {
        return NULL;
    }

    if (mock_alloc_limit < 0)
    {
        alloc_counter = 0;
    }

    return __real_calloc(nmemb, size);
}

extern void* __real_malloc(size_t size);

void *__wrap_malloc(size_t size)
{
    alloc_counter++;

    if (mock_alloc_limit >= 0 && alloc_counter > mock_alloc_limit) {
        return NULL;
    }

    if (mock_alloc_limit < 0)
    {
        alloc_counter = 0;
    }

    return __real_malloc(size);
}

int main()
{
    if (test_split_all_functions())
    {
        printf("PASS: test_split_all_functions\n");
    }
    else
    {
        printf("FAIL: test_split_all_functions\n");
    }

    if (test_data_all_functions())
    {
        printf("PASS: test_data_all_functions\n");
    }
    else
    {
        printf("FAIL: test_data_all_functions\n");
    }

    if (test_hash_all_functions())
    {
        printf("PASS: test_hash_all_functions\n");
    }
    else
    {
        printf("FAIL: test_hash_all_functions\n");
    }

    return 0;
}