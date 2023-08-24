#include "main.h"
#include <stdlib.h>
#include <stdio.h>
/**
 * print_environment - show the info of env
 * @env: Array of environment variables.
 * Return: This function does not return a value.
 */

void print_environment(char **env)
{
	while (*env)
	{
		printf("%s\n", *env);
		env++;
	}
}
