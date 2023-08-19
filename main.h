#ifndef MAIN_H
#define MAIN_H
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>

typedef  struct dirent 
{
    ino_t d_ino;
    off_t d_off;       /* Not an offset; see below */
    unsigned short d_reclen;    /* Length of this record */
    unsigned char  d_type;      /* Type of file; not supported by all filesystem types */
    char d_name[256]; /* Null-terminated filename */
};

extern char **environ;
void display_prompt();
char **tokenize(char *buf, size_t buf_size);
void forking(char **array, char *prog_name);
void exit_shell();
 
#endif
