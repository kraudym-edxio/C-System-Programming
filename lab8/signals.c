#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

int main (int argc, char *argv[]) {

	pid_t pid;
	int counter = 0; 

	//A) Fork a child process
	if ((pid = fork()) == 0) { //Child block

		//B) Infinite loop within child process
		while (1) {
			printf("Current value of counter: %d\n", counter++);
			sleep(2);	
		}

	}

	else { //Parent block

		//C) Sleep and send SIGSTOP to child
		sleep(5);
		kill(pid, SIGSTOP);
		
		//D) Sleep and send SIGCONT to child
		sleep(5);
		kill(pid, SIGCONT);	
		
		//E) Sleep and send SIGTERM to child
		sleep(5);
		kill(pid, SIGTERM);

	}

}
