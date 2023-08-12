#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
    char *buf = NULL;
    size_t buf_size = 0;
    char *token;
    char **array;
    int status, j = 0, n_char;
    pid_t pid;

    while (1)
    {
        write(1, "$ ", 2);
        n_char = getline(&buf, &buf_size, stdin);

        if (n_char == -1) // Handle end of file (Ctrl+D)
        {
            printf("\nExiting shell.\n");
            break;
        }

        // Remove newline character at the end of the input
        buf[strlen(buf) - 1] = '\0';

        // Tokenize the input
        array = malloc(sizeof(char *) * 2);
        token = strtok(buf, " \t\n");
        if (token)
        {
            array[0] = token;
            token = strtok(NULL, " \t\n");
            if (token)
            {
                fprintf(stderr, "Error: Only one-word commands are allowed.\n");
                free(array);
                continue;
            }
            array[1] = NULL;

            pid = fork();
            if (pid == 0)
            {
                if (execvp(array[0], array) == -1)
                {
                    perror("execvp");
                    exit(EXIT_FAILURE);
                }
            }
            else
            {
                wait(&status);
            }
        }
        free(array);
    }

    free(buf);
    return 0;
}
