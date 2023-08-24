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
		exit_shell();
	}
	if (strcmp(array[0], "env") == 0)
	{
		print_environment(env);
	}
	return (1);
}
