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
    char **array, **cmnd;
    int n_char;
    char *prog_name;

    prog_name = argv[0];
     while (1)
    {
        display_prompt();
        n_char = getline(&buf, &buf_size, stdin);
        if (n_char == -1) 
        {
            printf("\nExiting shell.\n");
            break;
        }
        if (buf[strlen(buf) - 1] = '\n')
            buf[strlen(buf) - 1] = '\0';
        array = tokenize(buf, buf_size);
        if (strstr(array[0], "/") == NULL){
            if (strcmp(array[0], "exit") == 0) 
            {
                exit_shell(); // Call the exit built-in function
                break; // Exit the loop
            }
            if (strcmp(array[0], "env") == 0) {
                print_environment(*env); // Call the print_environment function
            }
        }
        cmnd = 
        forking(array, prog_name);
        free(array);
    }
    free(buf);
    return (0);
}
