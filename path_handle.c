#include <sys/stat.h>
#include "main.h"

char **find_path(char *env, char **array)
{
    char path[1024];
    char **directory = NULL;
    char *token;
    int j = 0, i = 0, k = 0, x = 0;
    char **path_;

    while (env[i])
    {
        if (strstr(env[i], "PATH=") != NULL)
        {
            strcpy(path, strstr(env[i], "PATH="));
            while (path[j] != "=")
            {
                j++;
            }
            path_ = malloc(sizeof(char) * (strlen(path) - j));
            for (k ; k < (strlen(path) - j); k++){
                path_[k] = path[j];
                j++;
            }
            path_[k + 1] = '\0';
            token = strtok(path_, ":");
            directory = malloc(sizeof(char) * strlen(token));
            while (token)
            {
            dircetory[x] = malloc(sizeof(char) * strlen(token) + 1);
            token = strtok(NULL, ":");
            x++;
            }
            directory[x] = NULL;
            if (srch_cmnd(array, dircetory))
                return (srch_cmnd(array, dircetory));
        }
        i++;
    }
    return (NULL);
}