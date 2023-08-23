#include "main.h"
void ch_p(char **env, int mode, char *prog_name, size_t buf_size, char *buf)
{
    char *temp;
    char **array;

    array = tokenize(buf, buf_size);
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
        forking(array, prog_name, env);
        free(array);
}