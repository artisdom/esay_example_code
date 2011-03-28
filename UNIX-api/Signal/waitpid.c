#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>

char buf[20] = {0};

int main(int argc, char * argv[])
{
	pid_t pid;
	int fd1, fd2, fd3 = open("file_2.txt", O_RDONLY);
	
	printf("fd3 = %d \n",fd3);
	read(fd3, buf, 1);
	fd1 = dup(fd3);
	//printf("%d = dup ( %d )\n", fd1, fd2);

	if ((pid = fork()) > 0){
		waitpid(pid, NULL, 0);
		printf("fd1 = %d \n",fd1);
		read(fd1, &buf[1], 2);
	}
	else {
		fd2 = open("file_2.txt", O_RDONLY);
		printf("fd1 = %d \n",fd1);
		printf("fd2 = %d \n",fd2);
		read(fd1, &buf[1], 1);
		read(fd2, &buf[2], 2);
	}
	
	printf("%s\n", buf);
	
	return 0;
}