#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define MEGSIZE 16


void main()
{
	int inbuf;
	int inbuf2[MEGSIZE];
	int Numbers[2];
	char Symbal[MEGSIZE];
	
	int p[2],pid,j,p1[2];
	srand((unsigned)time(NULL));
	
	if (pipe(p)<0) {
		perror("pipe call");
		exit(1);
	}
	
	if (pipe(p1)<0) {
		perror("pipe call");
		exit(1);
	}
	
	if ((pid = fork())<0) {
		perror("fork call");
		exit(2);
	}
	
	if (pid > 0) {
		char temp[1] = "*";
		printf("please input an symbal:\n");
		scanf("%s",temp);
		Numbers[0] = rand()%100;
		Numbers[1] = rand()%100;
		write(p[1],&Numbers,MEGSIZE);
		write(p[1],temp,MEGSIZE);
		printf("%d %s %d\n",Numbers[0],temp, Numbers[1]);
		
		read(p1[0],inbuf2,MEGSIZE);
		printf("Result is %d\n",inbuf2[0]);
		wait((int*)0);
	}
	
	if (pid == 0) {
		int  Numbersforchild[2];
		int result[2];
		char temps[2];
		read(p[0],Numbersforchild,MEGSIZE);
		read(p[0],Symbal,MEGSIZE);
		switch (Symbal[0]) {
			case '+':
				result[0] = Numbersforchild[0] + Numbersforchild[1];
				break;
			case '-':
				result[0] = Numbersforchild[0] - Numbersforchild[1];
				break;
			case '*':
				result[0] = Numbersforchild[0] * Numbersforchild[1];
				break;
			case '/':
				result[0] = Numbersforchild[0] / Numbersforchild[1];
				break;
			default:
				break;
		}
		//printf("%d",result[0]);
		write(p1[1],result,MEGSIZE);
		//printf("%d %s %d\n",Numbersforchild[0], Symbal, Numbersforchild[1]);
	}
	exit(0);

}