#include "main.h"
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>

void print_environment() {
    char **env_var = environ;
    while (*env_var) {
        printf("%s\n", *env_var);
        env_var++;
    }
}

int main(int argc, char **argv, char **env)
{
    char *buf = NULL;
    size_t buf_size = 0;
    char *token;
    char **array;
    int n_char;
    pid_t pid;
    char *prog_name ;

    prog_name = argv[0] ;
     while (1)
    {
        display_prompt();
        n_char = getline(&buf, &buf_size, stdin);
        if (n_char == -1) 
        {
            printf("\nExiting shell.\n");
            break;
        }
        if (buf[strlen(buf) - 1] == '\n')
            buf[strlen(buf) - 1] = '\0';
        array = tokenize(buf, buf_size);

        if (strcmp(array[0], "exit") == 0) {
            exit_shell(); // Call the exit built-in function
            break; // Exit the loop
        }
	else if (strcmp(array[0], "env") == 0) {
            print_environment(); // Call the print_environment function
        }

        forking(array, pid, prog_name );
        free(array);
    }
    free(buf);
    return (0);
}
