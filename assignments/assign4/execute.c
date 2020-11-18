#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main (int argc, char *argv[]) {

	int count = argc - 1;
	
	if (count % 2 != 0) {
		count++;
	}

	//User inputs only one command 
 	if (count == 1) {

		if (fork() == 0) {
		
			printf("I am a child with pid %d and parent pid %d\n", getpid(), getppid());
			execlp(argv[1], argv[1], NULL, (char *)0);	
			printf("\n");

			exit(0);

		}

		wait(NULL);

	}	

	//More than one command is inputted or some commands with options 
	else {
	
		for (int x = 1; x < count; x++) {

			if (fork() == 0) {
		
				printf("I am a child with pid %d and parent pid %d\n", getpid(), getppid());
				
				if (x != count) {
					execlp(argv[x], argv[x], argv[x + 1], (char *)0);
					printf("\n");
				}

				else {
					execlp(argv[x], argv[x], NULL, (char *)0);
					printf("\n");
				}

				exit(0);

			}

			x++;

		}

		for (int y = 0; y < count; y++) {
			wait(NULL);
		}

	}

}
