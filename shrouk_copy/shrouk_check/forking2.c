#include "main.h"
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>


/**
*forking - a fanction that handel forking
* @array: an array of arrguments
* @prog_name: name of programme
* @env: Array of environment variables.
*/
void forking(char **array, char *prog_name, char **env)
{
	int status;
	char msg_pgn[300];
	pid_t pid;

	if (array)
	{
		pid = fork();
		if (pid == 0)
		{
			if (execve(array[0], array, env) == -1)
			{
				snprintf(msg_pgn, sizeof(msg_pgn), "%s", prog_name);
				perror(msg_pgn);
				exit(2);
			}
		}
		else
		{
			wait(&status);
		}
	}
}
