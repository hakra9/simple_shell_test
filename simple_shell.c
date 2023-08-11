#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h> 
int main ()
{
	char *buf = NULL;
	size_t buf_size = 0;
	char *token ;
	char **array ;
	int status ,j=0 ,n_char;
	pid_t pid;

	while(1)
	{ write(1, "$", 2);
		n_char = getline (&buf , &buf_size ,stdin);
		array = malloc(sizeof (char * ) * 1024);
		token = strtok(buf ," \t\n");
		while(token)
		{
			array[i] = token ;
			token = strtok (NULL , " \t\n");
			j++;
		}
		array [j] = NULL;
		pid = fork();
		if (pid == 0)
		{if (execve(array[0] , array , NULL) == -1)
			perror ("execve");
		}
		else 
			wait(&status);
		j=0;
		free (array);
	}
}
