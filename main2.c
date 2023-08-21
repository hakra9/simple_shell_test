#include "main.h"
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv, char **env)
{
    char *buf = NULL;
    size_t buf_size = 0;
    char *token;
    char **array;
    int n_char;
    char *prog_name;

    prog_name = argv[0];
    while (1) {
    display_prompt();
    while (1)
    {
        n_char = getline(&buf, &buf_size, stdin);
        if (n_char == -1) 
        {
            break;
        }
        if (buf[strlen(buf) - 1] == '\n')
            buf[strlen(buf) - 1] = '\0';
        array = tokenize(buf, buf_size);
        if (strstr(array[0], "/") == NULL){
            if (built_ins(array, env) == 1)
                array[0] = find_path(env, array [0]); 
        }
        forking(array, prog_name, env);
        free(array);
    }
    free(buf);
    return (0);
    }
}
