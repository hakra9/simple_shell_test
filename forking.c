#include "main.h"
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>

/**
*forking - a fanction that handel forking
* @array: an array of arrguments
* @pid: process id
*/
void forking(char **array, pid_t pid)
{
    int status;
    
    pid = fork();
        if (pid == 0)
        {
            if (execve(array[0], array, environ) == -1)
            {
                perror("");
                exit(EXIT_FAILURE);
            }
        }
        else
        {
            wait(&status);
        }
        return;
}
