#include <stdio.h>
#include "split.h"
#include "hash.h"

int main()
{
    Node** hash = create_hash();
    char line[1024];

    while (scanf(" %[^\n]s", line) != EOF)
    {
        char** argv = split(line, ' ');
        size_t argc = 0;

        while(argv && argv[argc])
        {
            argc++;
        }

        if (argc < 2)
        {
            printf("ERROR: Too few arguments '%s'\n", line);
            free_splits(argv);
            continue;
        }

        if (strcmp(argv[0], "s") != 0 && strcmp(argv[0], "g") != 0)
        {
            printf("ERROR: Command %s not found\n", argv[0]);
            free_splits(argv);
            continue;
        }

        char command = argv[0][0];
        char *key = argv[1];

        switch (command)
        {
        case 's':
        {
            if (argc < 3)
            {
                printf("ERROR: Too few arguments '%s'\n", line);
                free_splits(argv);
                continue;
            }
            char* value = argv[2];
            set_value(hash, key, value);
            printf("set\n");
            break;
        }
        case 'g':
        {
            char* value = get_value(hash, key);
            printf("value = %s\n", value == NULL ? "" : value);
            printf("get\n");
            break;
        }
        default:
            printf("ERROR: Command not found");
            break;
        }
        free_splits(argv);
        line[0] = '\0';
    }
    delete_hash(hash);
    return 0;
}