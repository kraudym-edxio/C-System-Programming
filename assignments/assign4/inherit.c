#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include <fcntl.h>

int main (int argc, char *argv[]) {

	int fd = open("sample.txt", O_RDONLY);

	char str[100];
	int pid = fork();

	if (pid == 0) { //Child block
		close(fd); //Child process closes file descriptor
	}

	else { //Parent block
		wait(0); //Wait for the child process to terminate

		read(fd, &str, 100); //Attempting to read from fd that child closed
		printf("%s", str);
	}

	close(fd);

}

/*
	From this simple program we learn that if a child closes a
	file descriptor, it will remain open in the parent.
*/
