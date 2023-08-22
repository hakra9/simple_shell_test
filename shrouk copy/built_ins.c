#include "main.h"
int built_ins(char **array, char **env)
{
    if (strcmp(array[0], "exit") == 0) 
    {
        exit_shell(); // Call the exit built-in function
    }
    if (strcmp(array[0], "env") == 0) {
        print_environment(env); // Call the print_environment function
    }
    return (1);
}