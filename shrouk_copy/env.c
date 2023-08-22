#include "main.h"
#include <stdlib.h>
#include <stdio.h>
/**
 * print_environment - show the info of env
 */

void print_environment(char **env) 
{
    while (*env) 
    {
        printf("%s\n", *env);
        env++;
    }
}
