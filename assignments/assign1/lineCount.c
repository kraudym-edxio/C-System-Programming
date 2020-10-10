#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

int main (int argc, char *argv[]) {

	int fd;
	char c;
	int lineCount = 0;

	fd = open(argv[1], O_RDONLY, 0777);
	
	while((read(fd, &c, 1)) != 0) {
		
		if (c == '\n') {
			lineCount++;
		}
	}

	printf("The program contains %d lines.\n", lineCount);

}
