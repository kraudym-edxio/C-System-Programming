#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include <fcntl.h>

int main (int argc, char *argv[]) {

	pid_t pid;

	//Creating a pipe
	int fd[2];
	pipe(fd);

	if ((pid = fork()) == 0) { //Child block

		close(fd[0]);
		dup2(fd[1], 1); //Redirect stdout to the pipe, writing end
		close(fd[1]);

		//Execute the commands given in command line
		execlp(argv[1], argv[1], argv[2], (char*) NULL);

	}

	else { //Parent block

		close(fd[1]); //Close writing end of the pipe 

		//Create and open the file result.txt to then write to
		int fd1 = open("result.txt", O_CREAT | O_RDWR | O_TRUNC, 0777);
	
		int counter = 0; //represents the fileSize
		char c;		

		//Read and then write to result.txt
		while ((read(fd[0], &c, 1)) != 0) {
			write(fd1, &c, 1);
			counter++;
		}

		wait(NULL); //Wait for child process to terminate

		printf("The result of %s is written into result.txt with total %d bytes.\n", argv[1], counter);
		
		close(fd1);
		close(fd[0]); 

	}

}
