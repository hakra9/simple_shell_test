#ifndef MAIN_H
#define MAIN_H
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>

extern char **environ;
void display_prompt();
char **tokenize(char *buf, size_t buf_size);
void forking(char **array, pid_t pid, char prog_name);

#endif
