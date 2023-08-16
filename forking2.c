#include "main.h"
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

extern char **environ;
/**
*forking - a fanction that handel forking
* @array: an array of arrguments
* @pid: process id
*/
void forking(char **array, char *prog_name)
{
    int status;
    char msg_pgn[300];
    pid_t pid;

    pid = fork();
        if (pid == 0)
        {
            if (execve(array[0], array, environ) == -1)
            {
            snprintf(msg_pgn, sizeof(msg_pgn), "%s", prog_name);
            perror(msg_pgn);
                exit(EXIT_FAILURE);
            }
        }
        else
        {
            wait(&status);
        }
        return;
}
