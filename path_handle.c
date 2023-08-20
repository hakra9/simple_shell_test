#include "main.h"

char *find_path(char **env, char *cmnd)
{
    char path[1024];
    char **directory = NULL;
    char *token;
    int j = 0, i = 0, k, x = 0;
    char *path_;

    while (env[i])
    {
        if (strstr(env[i], "PATH=") != NULL)
        {
            strcpy(path, strstr(env[i], "PATH="));
            while (path[j] != '=')
            {
                j++;
            }
            path_ = malloc(sizeof(char) * (strlen(path) - j));
            for (k = 0 ; k < (strlen(path) - j); k++){
                path_[k] = path[j];
                j++;
            }
            path_[k] = '\0';
            token = strtok(path_, ":");
            directory = malloc(sizeof(char *) * strlen(token));
            while (token)
            {
            directory[x] = malloc(sizeof(char) * strlen(token) + 1);
            strcpy(directory[x], token);
            token = strtok(NULL, ":");
            x++;
            }
            directory[x] = NULL;
            if (srch_cmnd(&cmnd, dircetory))
                return (srch_cmnd(&cmnd, dircetory));
        }
        i++;
    }
    return (NULL);
}