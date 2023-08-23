#include "main.h"

void processInput(char *buf, size_t buf_size, char **env, char *prog_name, int mode) {
    char **array;
    int n_char;
    char *temp;
    size_t length;

    while (1) {
        if (mode == 1) 
            display_prompt();
        n_char = getline(&buf, &buf_size, stdin);
        if (n_char == -1) 
            break;
        length = strlen(buf);
        while (length > 0) {
            if (buf[length - 1] == ' ' || buf[length - 1] == '\t')
                buf[length - 1] = '\0';
            if (buf[length - 1] == '\n') 
                buf[length - 1] = '\0';
            length--;
        }
        if (buf[0] == '\0') 
            break;
        array = tokenize(buf, buf_size);
        if (strstr(array[0], "/") == NULL) {
            if (built_ins(array, env) == 1) 
                temp = find_path(env, array[0]);
            if (temp == NULL && mode == 0) {
                fprintf(stderr, "%s: 1: %s: not found\n", prog_name, array[0]);
                exit(127);
            }
            if (temp != NULL) 
                array[0] = find_path(env, array[0]);
        }
        forking(array, prog_name, env);
        free(array);
    }
    free(buf);
}