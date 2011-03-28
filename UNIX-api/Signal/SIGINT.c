#include <stdio.h>
#include <signal.h>
#include <unistd.h>
int i = 0;

void snooze(int i)
{
	int j = 0;
	printf("Slept for %d of %d secs.\n", j, i);
	while(j < i)
	{
		sleep(1);
		j++;
		printf("Slept for %d of %d secs.\n", j, i);
	}
}

void handler(int sig)
{
	i = 0;

}

int  main()
{
	int j;
	
	signal(SIGINT, handler);
	
	for (j = 0; j < 10; j++)
	{
		i++;
		//sleep(1);
		
		snooze(1);
	}
	printf("i = %d\n", i);
	return 0;
	
}
