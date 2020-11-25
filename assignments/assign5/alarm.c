#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include <signal.h>

void alarmHandler(int dummy) {
	printf("Ding!\n");
	wait(NULL);
}

int main (int argc, char *argv[]) {

	int seconds;
	pid_t pid;

	printf("Alarm application starting...\n");
	sscanf(argv[1], "%d", &seconds);

	signal(SIGALRM, alarmHandler);

	if ((pid = fork()) == 0) { //Child block
		printf("Waiting for alarm to go off\n");
		printf("<%d second pause>\n", seconds);

		sleep(seconds);

		kill(getppid(), SIGALRM);
		exit(0);
	}

	else { //Parent block
		wait(NULL); //Wait for child to terminate
		printf("Done\n");
	}

}
