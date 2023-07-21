#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(void) {
	int fd;

	fd = open("test_open", O_RDONLY | O_CREAT);
	if (fd < 0)
		perror("Open Error");
	printf("Fd = %d\n", fd);
	close(fd);
	return 0;
}
