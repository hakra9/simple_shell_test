#include "main.h"
/**
*main - entrance
*@argc: number of arguments
*@argv: arrguments
*@env: environment
*Return: (0) on sucess
*/
int main(int argc, char **argv, char **env)
{
    char *buf = NULL, *prog_name;
    size_t buf_size = 0, length;
    int n_char , mode;

    prog_name = argv[0];
    mode = (isatty(fileno(stdin)) ? 1 : 0);
    while (1)
    {
        if (mode == 1 && argc > 0)
            display_prompt();
        n_char = getline(&buf, &buf_size, stdin);
        if (n_char == -1) 
            break;
        length = strlen(buf);
        while (length > 0)
        {
            if (buf[length - 1] == ' ' || buf[length - 1] == '\t' )
                buf[length - 1] = '\0';
            if (buf[length - 1] == '\n')
                buf[length - 1] = '\0';
            length--;
        }
        if (buf[0] == '\0')
            break;
        ch_p(env, mode, prog_name, buf_size, buf);
    }
    free(buf);
    return (0);
}
