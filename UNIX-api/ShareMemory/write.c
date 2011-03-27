#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <time.h>
#include <stdlib.h>

#define SHMKEY 75
int shmid;
void main()
{
	int i, *pint;
	char * addr1;
	srand((unsigned)time(NULL));
	extern cleanup();
	for(i=0; i<20; i++)
	{
		signal(i,cleanup);
	}
	shmid = shmget(SHMKEY,1280,0777|IPC_CREAT);
	addr1 = shmat(shmid,0,0);
	printf("addr1 0x%x\n",addr1);
	pint = (int *)addr1;
	for(i=0; i<256; i++)
		*pint ++ = rand()%256;
	pint = (int *)addr1;
	*pint = 256;
	pause();
}

cleanup()
{
	shmctl(shmid, IPC_RMID, 0);
	exit(1);
}