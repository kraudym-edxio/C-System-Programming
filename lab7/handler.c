#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void ctrlC_handler(int);

void ctrlC_handler(int dummy) {
	printf("CTRL-C has been pressed!\n");
}

int main (int argc, char *argv[]) {

	signal(2, ctrlC_handler); //Install handler for CTRL-C
	signal(SIGTSTP, SIG_IGN); //Ignore CTRL-Z

	pid_t pid;

	if ((pid = fork()) > 0) { //Parent block

		for (int i = 1; i <= 15; i++) {
			printf("I am in parent process.\n");
			kill(pid, 2);
			sleep(1);
		}

	}	
	
	else { //Child block
		printf("I am the child\n");
		//signal(2, SIG_IGN); 
		//pause();
		execlp("./donothing", "donothing", NULL);
	}

}
