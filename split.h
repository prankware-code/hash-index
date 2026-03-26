#ifndef _SPLIT_H_
#define _SPLIT_H_

#include <string.h>

char **split(char *str, char delimether);
void free_splits(char **split_str);

#ifdef INCLUDE_UTIL
size_t str_words_count(char *str, char delimether);
#endif

#endif