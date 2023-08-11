#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unisted.h>
#include <sys/wait.h>
 
int main ()
{
	char *buffer = NULL;
	size_t buffer_size = 0;
	char *token ;
	char **array ;
	int status ,i=0 ,n_char;
	pid_t pid;

	while(1)
	{ write(1 ,"$" ,2);
		n_char = getline ( &buffer , &buffer_size ,stdin);
		array= malloc(sizeof (char*)*1024);
		token = strtok (buffer ," \t\n");
		while(token)
		{array[i] = token ;
			token =strtok (NULL , " \t\n");
			i++;
		}
		array [i] = NULL;
		pid = fork();
		if (pid=0)
		{if ( execve( array[0] , array , NULL) = -1)
			perror ("execve");
		}
		else 
			wait (&status);
		i=0;
		free (array);
	}
}


