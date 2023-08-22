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
    char *prog_name, *temp;
    int mode;
    char msg_pgn[300];

    prog_name = argv[0];
    //if (argc > 1)
        //mode = 0;
    //else{
        //mode = 1;
   // }   
    mode = (argc > 1 ? 0 : 1);
    if (mode == 1){
            display_prompt();
        }
    while (1)
    {
        n_char = getline(&buf, &buf_size, stdin);
        if (n_char == -1) 
        {
            write(STDOUT_FILENO, "\n", 1);
            break;
        }
        if (buf[strlen(buf) - 1] == '\n')
            buf[strlen(buf) - 1] = '\0';
        array = tokenize(buf, buf_size);
        if (strstr(array[0], "/") == NULL){
            if (built_ins(array, env) == 1)
                temp = find_path(env, array[0]);
            if (temp == NULL){
                printf("%s: 1: %s: not found", prog_name, array[0]);
                continue;
            }
            array[0] = find_path(env, array[0]);
        }
        forking(array, prog_name, env);
        free(array);
        display_prompt();
    }
    free(buf);
    return (0);
}
