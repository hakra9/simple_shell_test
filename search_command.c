#include "main.h"
#include <sys/types.h>
#include <dirent.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>

char **srch_cmnd(char **array, char **directory)
{
    DIR *dirp;
    int i = 0;
    struct dirent *info;

    while (directory[i])
    {
    dirp = opendir (directory[i]);
        if (dirp == NULL)
            {
                i++,
                break;
            }
    info = readdir(dirp);
    while (info) {
    if (info->d_type == DT_REG)
    {
        if (strcmp(info->d_name == array[0]) == 0)
        {
            if (access(array[0], X_OK) == 0)
            {
                return (array);
            }
        }
    }
    }
    closedir(dirp);
    i++;
    }
    return (NULL);
}