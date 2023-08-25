#include "main.h"
/**
 * built_ins - Execute built-in shell commands.
 * @array: Array of command tokens.
 * @env: Array of environment variables.
 * Return: If a built-in command is executed, returns 1. Otherwise, returns 0.
 */

int built_ins(char **array, char **env)
{
	if (strcmp(array[0], "exit") == 0)
	{
		exit(0);
	}
	if (strcmp(array[0], "env") == 0)
	{
		while (*env)
		{
		printf("%s\n", *env);
		env++;
		}
		return (0);
	}
	return (1);
}