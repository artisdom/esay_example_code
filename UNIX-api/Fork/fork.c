#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main()
{
	pid_t pid;
	int x = 1;
	
	pid = fork();
	if (pid == 0) {
		printf("child : x=%d\n", ++x);
		exit(0);
	}
	
	/*parent*/
	printf("parent: x=%d\n", pid);
	exit (0);
}