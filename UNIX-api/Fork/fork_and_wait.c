#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>
//#include <sys/types.h>
int main()
{
	if (fork() == 0) {
		if(fork() == 0) {
			printf("%d - 9\n", getpid());
			//exit(1);
			return 0;
		}
		else {
			int i;
			for (i  = 0; i < 100000; i++);
			printf("%d - 5\n", getpid());
		}
	}
	else {
		pid_t pid;
		if ((pid = wait(NULL)) > 0) {
			printf("%d returned!\n", pid);
			printf("%d - 3\n", getpid());
			
		}
	}
	printf("%d - 0\n", getpid());
	return 0;
}