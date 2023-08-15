#ifndef MAIN_H
#define MAIN_H

#define buf_size 1024
display_prompt();
char *tokenize(char *buf, size_t buf_size);
void forking(char **array, pid_t pid);

#endif
