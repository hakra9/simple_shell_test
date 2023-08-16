#include "main.h"
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>


/**
*forking - a fanction that handel forking
* @array: an array of arrguments
* @pid: process id
*/
void forking(char **array, pid_t pid, char prog_name)
{
    int status;
    char msg_pgn[300];
    
    pid = fork();
        if (pid == 0)
        {
            if (execve(array[0], array, environ) == -1)
            {
            snprintf(msg_pgn, sizeof(msg_pgn), "%d: %s", prog_name, strerror(errno));
                exit(EXIT_FAILURE);
            }
        }
        else
        {
            wait(&status);
        }
        return;
}
