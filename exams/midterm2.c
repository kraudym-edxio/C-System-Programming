#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main (int argc, char *argv[]) {

	int pid = fork(); // P creates c1

	//Testing if fork was successful
	if (pid == -1) {
		perror("Fork not possible");
		exit(30);
	}

	if (pid == 0) { //Children block

		printf("I am a child process, parent pid = %d, my pid = %d\n", getppid(), getpid());
		pid = fork(); // c1 creates c2

		if (pid == 0) {
			
			printf("I am a child process, parent pid = %d, my pid = %d\n", getppid(), getpid());
			pid = fork(); //c2 creates c3
			
			if (pid == 0) {

				printf("I am a child process, parent pid = %d, my pid = %d\n", getppid(), getpid());
				pid = fork(); //c3 creates c4

				if (pid == 0) {
					printf("I am a child process, parent pid = %d, my pid = %d\n", getppid(), getpid());
				}				

			}

		}

	}

	else { //Parent block
		printf("I am the parent process, my pid = %d\n", getpid());
		sleep(2);
	}

	return 0;

}
