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
            if (execvp(array[0], array) == -1)
            {
                perror("error");
                exit(EXIT_FAILURE);
            }
        }
        else
        {
            wait(&status);
        }
        return;
}
