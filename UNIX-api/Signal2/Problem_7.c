#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <sys/signal.h>

int child = 0;
int goodChild = 0;
void GoodHanlde(int sig)
{
	if (sig == SIGTSTP) printf("Hello\n");
	if (sig == SIGINT) exit(0);
}

void BadHandle(int sig)
{
	if (sig == SIGTSTP) printf("Leave me alone\n");
	if (sig == SIGINT) exit(0);
}

void mainHandle(int sig)
{
	if (sig == SIGTSTP) printf("Main\n");
	if (sig == SIGINT) {
		while(1)
		{
		    if(pid == wait(0) && pid % 2 == 0)
				child++;
		         if(child == goodChild)
						exit(0);
		}
	}
}

void GoodProcess()
{
	//printf("Good process Caught SIGHUP");
	if (signal(SIGTSTP, GoodHanlde) == SIG_ERR)
	{
		printf("signal error");
	}
	if (signal(SIGINT, GoodHanlde) == SIG_ERR)
	{
		printf("signal error");
	}
	while(1)
		pause();
}

void BadProcess()
{
	//printf("Bad process Caught SIGHUP");
	if (signal(SIGTSTP, BadHandle) == SIG_ERR)
	{
		printf("signal error");
	}
	if (signal(SIGINT, BadHandle) == SIG_ERR)
	{
		printf("signal error");
	}
	while(1)
		pause();
}


int main()
{
	int i = 0;
	pid_t pid;	
	if (signal(SIGTSTP, mainHandle) == SIG_ERR)
	{
		printf("signal error");
	}
	if (signal(SIGINT, mainHandle) == SIG_ERR)
	{
		printf("signal error");
	}
	//for ( i = 0; i < 1000; i++)
	
	for(i=0; i < 20; i++)
	{
		if((pid = fork()) == 0)
		{
			if (getpid() % 2 == 0) {
				//printf("This is a good process! -%3d\n", i);
				goodChild++;
				GoodProcess();
				return 0;
			}
			else {
				//printf("This is a bad process!  -%3d\n",i);
				BadProcess();
				return 0;
			}
		}
	}
	
	while(1) pause();
	return 0;
}
