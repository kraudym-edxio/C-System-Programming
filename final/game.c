/*
	Final Exam Question 1
	By: Edxio Kraudy Mora (110006224)
	Date: December 12, 2020
*/

#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
#include <signal.h>
#include <time.h>

void player(char *s, int *fd1, int *fd2);

//User defined signal handler to incorporate coordination of second player
void switchingHandler(int dummy) {
	sleep(1);
	printf("Switching...");
}

int main (int argc, char *argv[]) { 

	//Need to create a fifo to incorporate third player
	unlink("../myserver");
	if (mkfifo("../myserver", 0777) != 0) {
		exit(1);
	}

	//Open the fifo for writing only 
	//int myfifo = open("../myserver", O_WRONLY, 0777);

	//Creating int arrays for fd's to use for pipe parameter
        int fd1[2], fd2[2], fd3[2], fd4[2];  

	char turn = 'T';
	pid_t pid;
	char ch;

	printf("This is a 3-player game with a referee\n");  

	pipe(fd1);
	pipe(fd2);  

	if ((pid = fork()) == 0)  //One child process for player TOTO
		player("TOTO", fd1, fd2);

		//printf("Player one is running\n");
		//kill(pid, SIGUSR1);
		//signal(SIGUSR1, switchingHandler);
		//pause();

	close(fd1[0]); // parent not read from fd1,( parent only write to pipe 1 )
	close(fd2[1]);   // parent not write to fd2, ( parent only reads from pipe 2). 
	
	pipe(fd3);  
	pipe(fd4);  

	if ((pid = fork()) == 0) { //One child process for player TITI

		player("TITI", fd3, fd4);

		//Using signals instead of pipes for second player coordination
		signal(SIGUSR1, switchingHandler);
		pause();
		printf("Player two is running\n");
		kill(getppid(), SIGUSR1);

	}

	close(fd3[0]); // parent only write to pipe 3  
	close(fd4[1]);   // parent only reads from pipe 4

	while(1) {
		
		int points = 0;
		int dice;
		long int ss = 0;

		printf("\nReferee: TOTO plays\n\n");  
				
		write(fd1[1], &turn, 1);  //parent write to pipe 1, fd1	
		read(fd2[0],  &turn, 1);

		printf("\nReferee: TITI plays\n\n");  
		
		write(fd3[1], &turn, 1);
		read(fd4[0],  &turn, 1);
   
		printf("\nReferee: 3rd player plays\n\n");
		int fd = open("../myserver", O_WRONLY);		

		printf("3rd player: rolling my dice\n");  
		
		dice = (int)time(&ss) % 10 + 1;
		write(fd, &dice, sizeof(dice)); //Write roll number to fifo
	
    	        points += dice;
		write(fd, &points, sizeof(points)); //Write points to fifo

		printf("3rd player: Total so far %d\n\n", points);  

	}

}

void player(char *s, int *fd1, int *fd2) {  

	int points = 0;
	int dice;
	long int ss = 0;  
	
	char turn;  
	close(fd1[1]);
	close(fd2[0]);  
	
	while (1) {

		read(fd1[0], &turn, 1);   //Child read from pipe1 ,ie fd1

		printf("%s: playing my dice\n", s);  
		dice = (int)time(&ss) % 10 + 1;  
		printf("%s: got %d points\n", s, dice); 
    	        points += dice;
		printf("%s: Total so far %d\n\n", s, points);  

		if (points >= 45){
			printf("%s: game over I won\n", s); 
              		kill(0, SIGTERM);
		}

		sleep(2); //Slow down the execution  
		write(fd2[1], &turn, 1); //Child write to pipe 2, ie fd2

	}

}
