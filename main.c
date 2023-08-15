int main(void)
{
    char *buf = NULL;
    size_t buf_size = 0;
    char *token;
    char **array;
    int n_char;
    pid_t pid;

     while (1)
    {
        display_prompt();
        n_char = getline(&buf, &buf_size, stdin);
        if (n_char == -1) 
        {
            printf("\nExiting shell.\n");
            break;
        }
        if (buf[strlen(buf) - 1] = '\n')
            buf[strlen(buf) - 1] = '\0';
        array = char *tokenize(buf, buf_size);
        free(array);
    }
    free(buf);
    return (0);
}
