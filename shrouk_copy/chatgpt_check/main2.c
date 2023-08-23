#include "main.h"
int main(int argc, char **argv, char **env)
 {
    char *buf = NULL;
    size_t buf_size = 0;
    char *prog_name;
    int mode;

    prog_name = argv[0];

    if (isatty(fileno(stdin))) {
        mode = 1;
    } else {
        mode = 0;
    }

    processInput(buf, buf_size, env, prog_name, mode);

    return 0;
}