#include <stdio.h>
#include <unistd.h>

int main () 
{
	pid_t pid;
	pid = getpid();
	printf("my pid= %d ", pid);
	return 0;
}
