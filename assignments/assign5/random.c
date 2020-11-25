#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <time.h>

int main (int args, char *argv[]) {

	pid_t pid;
	srand(time(NULL));

	int num = 0;
	int fd[2];

	//Creating a pipe
	if (pipe(fd) == -1) {
		exit(1);
	}

	if ((pid = fork()) == 0) { //Child block

		close(fd[0]);		

		//First child process generates five random numbers and writes to fd[1]
		for (int x = 0; x < 5; x++) {
			int num = rand() % 100;
			write(fd[1], &num, sizeof(num));
		}

		if (fork() == 0) {

			close(fd[0]);

			//Second child process generates five random numbers and writes to fd[1]
			for (int x = 0; x < 5; x++) {
				int num2 = rand() % 100;
				write(fd[1], &num2, sizeof(num2));
			}

		}

		wait(NULL);

	}

	else { //Parent block

		wait(NULL);
		close(fd[1]);		

		//Parent process prints all random numbers by reading fd[0]
		printf("Parent has received the following random numbers: ");
		for (int x = 0; x < 10; x++) {
			read(fd[0], &num, sizeof(num));
			printf("%d   ", num);
		}

		printf("\n");


	}

}
