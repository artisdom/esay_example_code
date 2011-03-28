#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

int main (int argc, char const *argv[])
{
	int fd;
	char szErrorBuffer[256] = "hello!";
	fd = open("./HelloWorld.txt", O_WRONLY  | O_APPEND);
	printf("%d\n", fd);
	printf("%d\n", sizeof(szErrorBuffer));
	printf("%d\n", strlen(szErrorBuffer));	
	if (fd == -1)
	{
		memset(szErrorBuffer, 0x00, sizeof(szErrorBuffer));
		sprintf(szErrorBuffer, "creat:%s\n", (char*)strerror(errno));
		write(STDERR_FILENO, szErrorBuffer, strlen(szErrorBuffer));
		return 0;
	}
	write(fd, "Hello Wangyi!\n", 14);
	close(fd);
	return 0;
}
