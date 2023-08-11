#include <stdio.h>
#include <unistd.h>

int main () 
{
	pid_t pid ,ppid;
	ppid = getppid();
	pid = getpid();
	printf("my pid= %d \n myppid = %d \n ", pid,ppid);
	return 0;
}
