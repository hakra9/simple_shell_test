#include "main.h"
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv, char **env)
{
    char *buf = NULL;
    size_t buf_size = 0, length;
    char **array;
    int n_char;
    char *prog_name, *temp;
    int mode;

    prog_name = argv[0];
    if (isatty(fileno(stdin))) {
        mode = 1; 
    } else {
        mode = 0; 
    }
    while (1){
        if (mode == 1 && argc > 0)
            display_prompt();
        n_char = getline(&buf, &buf_size, stdin);
        if (n_char == -1) 
        {
            /*write(STDOUT_FILENO, "\n", 1);*/
            break;
        }
        length = strlen(buf);
        /**if (length > 0 && buf[length - 1] == '\n') {
            buf[length - 1] = '\0';
            length--;
        }*/
        while (length > 0 && (buf[length - 1] == ' ' || buf[length - 1] == '\t' || buf[length - 1] == '\n')) {
            buf[length - 1] = '\0';
            length--;
        }
        if (buf[0] == '\0')
            break;
        array = tokenize(buf, buf_size);
        if (strstr(array[0], "/") == NULL){
            if (built_ins(array, env) == 1)
                temp = find_path(env, array[0]);
            if (temp == NULL && mode == 0){
                printf("%s: 1: %s: not found\n", prog_name, array[0]);
                break;
            }
            if (temp != NULL)
                array[0] = find_path(env, array[0]);
        }
        forking(array, prog_name, env);
        free(array);
    }
    free(buf);
    return (0);
}
