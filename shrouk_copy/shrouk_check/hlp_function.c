#include "main.h"
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>

/**
*display_prompt - a function that prints the prompt
*/
void display_prompt(void)
{
	write(STDOUT_FILENO, "$ ", 2);
}
/**
*tokenize - a function tha seperat the command line into args
*@buf: a pointer to the buffer holds the command line
*@buf_size: buffr size
* Return: a pointer of an array of args
*/
char **tokenize(char *buf, size_t buf_size)
{
	char *token;
	char **array;
	int j = 0;

	array = malloc(sizeof(char *) * (buf_size + 1));
	token = strtok(buf, " \t\n");
	while (token)
	{
		array[j] = token;
		token = strtok(NULL, " \t\n");
		j++;
	}
	array[j] = NULL;
	return (array);
}
