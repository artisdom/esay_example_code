#include <sys/signal.h>


void handler(int sig)
{
	printf("Caught SIGINT\n");
}
int main()
{
	signal(SIGINT, handler);
	pause();
	return 0;
}