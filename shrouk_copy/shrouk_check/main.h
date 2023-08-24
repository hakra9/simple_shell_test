#ifndef MAIN_H
#define MAIN_H
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <errno.h>



extern char **environ;
void display_prompt(void);
char **tokenize(char *buf, size_t buf_size);
void forking(char **array, char *prog_name, char **env);
void exit_shell(void);
char *find_path(char **env, char *cmnd);
char *srch_cmnd(char *array, char **directory);
int built_ins(char **array, char **env);
void print_environment(char **env);
int determine_mode(void);
void handle_command_not_found_error(char *prog_name, char *command);


#endif
