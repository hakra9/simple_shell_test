#include "main.h"
int built_ins(char **array, char **env)
{
    if (strcmp(array[0], "exit") == 0) 
    {
        exit_shell(); 
    }
    if (strcmp(array[0], "env") == 0) {
        print_environment(env); 
    }
    return (1);
}