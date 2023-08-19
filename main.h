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
void forking(char **array, char *prog_name);
void exit_shell();
char **find_path(char *env, char **array);
char **srch_cmnd(char **array, char **directory);
void built_ins(char **array);
void print_environment(char **env)

#endif
