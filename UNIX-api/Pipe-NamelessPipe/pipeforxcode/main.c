#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define MEGSIZE 8


void main()
{
	int inbuf;
	char inbuf2;
	int Numbers[2];
	char Symbal;
	
	int p[2],pid,j;
	printf("OK!");
	srand((unsigned)time(NULL));
	
	printf("OK!");
	if (pipe(p)<0) {
		perror("pipe call");
		exit(1);
	}
	
	if ((pid = fork())<0) {
		perror("fork call");
		exit(2);
	}
	
	if (pid > 0) {
		char temp;
		//scanf("%c",temp);
		printf("what?");
		Numbers[0] = atoi("10");
		write(p[1],rand()%100,MEGSIZE);
		write(p[1],rand()%100,MEGSIZE);
		//write(p[1],temp,sizeof(char));
		wait((int*)0);
	}
	
	if (pid == 0) {
		read(p[0],Numbers[0],MEGSIZE);
		read(p[0],Numbers[1],MEGSIZE);
		//read(p[0],Symbal,sizeof(char));
		printf("%d  %d\n",Numbers[0], Numbers[1]);
		
	}
	exit(0);
	
}