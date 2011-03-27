#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SHMKEY 75
int shmid;
main()
{
	int i, * pint;
	char * addr2;
	int max = 0,min = 100;
	shmid = shmget(SHMKEY,640,0777);
	addr2 = shmat(shmid,0,0);
	pint = (int*)addr2;
	while(*pint == 0);
	for(i=0; i<256; i++)
	{
		if(*pint > max)
			max = * pint;
		if(*pint < min)
			min = * pint;
		printf("index%d\tvalue%d\n",i,*pint++);
	}
	printf("max is %d, min is %d.\n",max, min);
}