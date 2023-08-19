#include <sys/stat.h>
#include "main.h"

char **find_path(char *env,char var_name, char **array)
{
    char path[1024];
    char **directory = NULL;
    char *token;
    int j = 0, i = 0;
    char **file_name;

    while (env[i])
    {
        if (strstr(env[i], "PATH=") != NULL)
        {
            strcpy(path, strstr(env[i], "PATH="));
            while (path[j] != "=")
            {
                j++;
            }
            path = path[j + 1];
            token = strtok(path, ":");
            directory = malloc(sizeof (char *) * strlen(token));
            while (token)
            {
            dircetory[i] = malloc(sizeof (char *) * strlen(token) + 1);
            token = strtok(NULL, ":");
            i++;
            }
            directory[i] = NULL;
            if (srch_cmnd(array, dircetory))
                return (srch_cmnd(array, dircetory));
        }
        i++;
        if (!env)
            break;
    }
    return (NULL);
}