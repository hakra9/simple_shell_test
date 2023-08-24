#include "main.h"
/**
 * main - Entry point of the shell program.
 * @argc: The number of command-line arguments.
 * @argv: An array of command-line argument strings.
 * @env: An array of environment variable strings.
 * Return: Always returns 0.
 */
int main(int argc, char **argv, char **env)
{
	char *buf = NULL, **array, *prog_name, *temp;
	size_t buf_size = 0, length;
	int n_char, mode;

	prog_name = argv[0];
	mode = determine_mode();
	while (1)
	{
		if (mode == 1 && argc > 0)
			display_prompt();
		n_char = getline(&buf, &buf_size, stdin);
		if (n_char == -1)
			break;
		length = strlen(buf);
		while (length > 0 && (buf[length - 1] == ' ' ||
				 buf[length - 1] == '\t' || buf[length - 1] == '\n'))
		{
			buf[length - 1] = '\0';
			length--;
		}
		if (buf[0] == '\0')
			break;
		array = tokenize(buf, buf_size);
		if (strstr(array[0], "/") == NULL)
		{
			if (built_ins(array, env) == 1)
				temp = find_path(env, array[0]);
			if (temp == NULL && mode == 0)
				handle_command_not_found_error(prog_name, array[0]);
			if (temp != NULL)
				array[0] = find_path(env, array[0]);
		}
		forking(array, prog_name, env);
		free(array);
	}
	free(buf);
	return (0);
}
