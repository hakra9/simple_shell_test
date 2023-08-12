#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * display_prompt - Displays the shell prompt.
 */
void display_prompt(void)
{
    write(STDOUT_FILENO, "$ ", 2);
}

int main(void)
{
    char *buf = NULL;
    size_t buf_size = 0;
    char *token;
    char **array;
    int status, j = 0, n_char;
    pid_t pid;

    while (1)
    {
        display_prompt();
        n_char = getline(&buf, &buf_size, stdin);

        if (n_char == -1) // Handle end of file (Ctrl+D)
        {
            printf("\nExiting shell.\n");
            break;
        }

        // Remove newline character at the end of the input
        buf[strlen(buf) - 1] = '\0';

        // Tokenize the input
        array = malloc(sizeof(char *) * (buf_size / 2)); // Adjust size for arguments
        token = strtok(buf, " \t\n");
        while (token)
        {
            array[j] = token;
            token = strtok(NULL, " \t\n");
            j++;
        }
        array[j] = NULL;

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

        free(array);
        j = 0;
    }

    free(buf);
    return 0;
}
