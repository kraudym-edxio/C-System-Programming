#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>

void childHandler(int dummy) {
	
	pid_t pid;
	int status;

	pid = wait(&status);
	int exit_status = WEXITSTATUS(status);
	printf("Child %d has been terminated, with exit status %d.\n", pid, exit_status);	

}

int main (int argc, char *argv[]) {

	pid_t pid;

	while (1) {
		
		signal(SIGCHLD, childHandler);
		
		if ((pid = fork()) == 0) {
			sleep(5);
			exit(4);
		}

		printf("Created a child, pid = %d\n", pid);
		sleep(2);

	}

}
