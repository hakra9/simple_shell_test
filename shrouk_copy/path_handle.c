#include "main.h"

char *find_path(char **env, char *cmnd)
{
    char path[1024];
    char **directory = NULL;
    char *token;
    size_t k;
    int j = 0, i = 0, x = 0;
    char *path_, *result;

    while (env[i])
    {
        if (strstr(env[i], "PATH=") != NULL)
        {
            strcpy(path, strstr(env[i], "PATH="));
            path_ = malloc(sizeof(char) * (strlen(path) - 4));
            for (k = 0 ; k < (strlen(path) - 5); k++){
                path_[k] = path[j + 5];
                j++;
            }
            path_[k] = '\0';
            token = strtok(path_, ":");
            directory = malloc(sizeof(char *) * strlen(token) + 1);
            while (token)
            {
            directory[x] = malloc(sizeof(char) * strlen(token) + 1);
            strcpy(directory[x], token);
            token = strtok(NULL, ":");
            x++;
            }
            directory[x] = '\0';
            result = srch_cmnd(cmnd, directory);
            if (result)
                return result;
            }
        i++;
    }
    return (NULL);
}