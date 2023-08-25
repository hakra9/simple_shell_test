#include "main.h"
/**
 * handle_command_not_found_error - Handles and displays a cmnd
 * @prog_name: Name of the program (typically argv[0])
 * @command: Command that was not found
 * returne: error
 */

void handle_command_not_found_error(char *prog_name, char *command)
{
	fprintf(stderr, "%s: 1: %s: not found\n", prog_name, command);
		exit(127);
}
