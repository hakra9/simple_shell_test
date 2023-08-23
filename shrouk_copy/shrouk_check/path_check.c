#include "main.h"
char *check_path(char **env, char *array, int mode)
{
    char *temp;
            if (strstr(array[0], "/") == NULL){
            if (built_ins(array, env) == 1)
                temp = find_path(env, array[0]);
            if (temp == NULL && mode == 0){
                fprintf(stderr,"%s: 1: %s: not found\n", prog_name, array[0]);
                exit(127);
            }
            if (temp != NULL)
                array[0] = find_path(env, array[0]);
        }
    return (array[0]);
}