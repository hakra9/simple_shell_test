#include "main.h"
#include <sys/types.h>
#include <dirent.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>

char *srch_cmnd(char *array, char **directory)
{
    DIR *dirp;
    int i = 0;
    struct dirent *info;
    char *address;

    while (directory[i]) {
        dirp = opendir(directory[i]);
        if (dirp == NULL) {
            i++;
            break;
        }
        info = readdir(dirp);
        while (info) {
            if (info->d_type == DT_REG) {
                if (strcmp(info->d_name, array) == 0) {
                    address = malloc(strlen(directory[i]) + strlen("/") + strlen(array) + 1);
                    strcpy(address, directory[i]);
                    strcat(address, "/");
                    strcat(address, array);
                    if (access(address, X_OK) == 0) {
                        closedir(dirp);
                        return address;
                    }
                    free(address);
                }
            }
            info = readdir(dirp);
        }
        closedir(dirp);
        i++;
    }
    return NULL;
}