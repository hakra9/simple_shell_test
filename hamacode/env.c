#include "main.h"
#include <stdlib.h>
#include <stdio.h>
/**
 * print_environment - show the info of env
 */

void print_environment() 
{
    char **env_var = environ;
    while (*env_var) {
        printf("%s\n", *env_var);
        env_var++;
    }
}
