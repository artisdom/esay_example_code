#include <sys/mman.h>
#include <sys/types.h>
#include <sys/sem.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <time.h>

int fullid;
int emptyid;
int mutxid;

int main()
{
	struct sembuf P,V;
	union semun arg;
	
	int * array;
	int * sum;
	int * set;
	int * get;
	
	array = (int *)mmap(NULL, sizeof(int)*5, PROT_READ|PROT_WRITE, MAP_SHARED,-1,0);
	
}