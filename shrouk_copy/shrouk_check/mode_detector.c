#include <stdio.h>
#include <unistd.h>

/**
 * determine_mode - Determine if the shell is running in interactive mode.
 *
 * Return: 1 if running in interactive mode, 0 if not.
 */

int determine_mode(void)
{
if (isatty(fileno(stdin)))
	return (1);
else
	return (0);
}
