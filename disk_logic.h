#ifndef _DISK_LOGIC_H_
#define _DISK_LOGIC_H_

#include "data.h"
#include <stdbool.h>
#include <sys/types.h>

#ifndef MAX_FILE_SIZE
#define MAX_FILE_SIZE 4096
#endif

bool directory_exists(char *path);
bool file_exists(char *path);
bool is_full_file(char *path);

bool create_file(int *fd, char* path);
bool delete_file(int fd);
off_t write_to_file(int fd, struct Data data);
struct Data read_file(int fd, off_t offset);

#endif