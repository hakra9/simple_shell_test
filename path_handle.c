#include <sys/stat.h>
#include "main.h"
int find_path(char *env,char var_name)
{
    char path[1024];
    char **dirctory;
    char *token;
    int j = 0, i = 0;

    while (env)
    {
        if (strstr(env[i], "PATH=") != NULL)
        {
            path = strstr(env[i], "PATH=");
            while (path[j] != "=")
            {
                j++;
            }
            path = path[j + 1];
            token = strtok(path, ":");
            while (token)
            {
            dirctory[i] = token;
            token = strtok(NULL, ":");
            i++;
            }
            search_dir;
            break;
        }
        i++;
        if (EOF)
            return ("NOT FOUND");
    }
}