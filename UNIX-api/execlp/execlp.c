/*
 *  CreateNewProcess.c
 *  
 *
 *  Created by wang yi on 10-3-24.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int	main(int argc, char *argv[])
{
	pid_t pid;
	pid = fork();
	if (pid < 0) {
		fprintf(stderr,"Fork Failed");
		exit(-1);
	}
	else if(pid == 0){
		execlp("/bin/date","date",NULL);
	}
	else {
		wait(NULL);
		printf("child complete\n");
		exit(0);
	}

}
