#define INCLUDE_UTIL
#include "../split.h"
#include <string.h>
#include <stdio.h>

void check_equals(size_t a, size_t b)
{
    if (a != b)
    {
        printf("ERROR: %lu != %lu\n", a, b);
    }
}

void check_words(const char **a, const char **b)
{
    for (;a && (*a) && b && (*b); a++, b++)
    {
        for (;(**a) && (**b); (*a)++, (*b)++)
        {
            if (**a != **b)
            {
                printf("ERROR: %s != %s\n", *a, *b);
            }
        }
    }

    if ((a && !b) || (b && !a) || ((*a && !(*b)) || (!*a && *b)))
    {
        printf("ERROR: len(a) != len(b)\n");
    }
}

int main()
{
    printf("BEGIN TESTS\n");

    check_equals(str_words_count("123 456 789", ' '), 3);
    check_equals(str_words_count("123  456  789    q", ' '), 4);
    check_equals(str_words_count("123            456             789   q         1", ' '), 5);
    check_equals(str_words_count("       123 456        ", ' '), 2);

    check_words(split("123 456 789", ' '), (const char *[]){"123", "456", "789", NULL});
    check_words(split("123  456  789    q", ' '), (const char *[]){"123", "456", "789", "q", NULL});
    check_words(split("123            456             789   q         1", ' '), (const char *[]){"123", "456", "789", "q", "1", NULL});
    check_words(split("       123 456        ", ' '), (const char *[]){"123", "456", NULL});

    printf("END TESTS\n");
}