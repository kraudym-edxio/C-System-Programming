#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

//Name: Edxio Kraudy Mora
//Date: November 9, 2020
//Lab Section: 51
//Student ID: 110006224

//p ------->c1------>c3
//     |----->c2------>c4


/* 
	Question 1) When we delete "else exit(11);
	p -------> c1 -------> c3
			 |---> (process which was not terminated by an exit()		

	     |---> c2 -------> c4
			 |---> (process which was not terminated by an exit()
*/

int main (int argc, char *argv[]) {

	pid_t pid, cpid;

	printf("I am the parent process, my pid = % d\n", getpid());

	for (int i = 0; i < 2; i++) {

		cpid=fork();

		if (cpid == 0) {	

			printf("!) I am a child process, parent pid = %d, my pid = %d\n", getppid(), getpid());
			//exit(10);

			pid_t ccpid;
			ccpid=fork();

			if (ccpid == 0) {
			     printf("#) I am a child process, my parent pid = %d, my pid = %d\n", getppid(), getpid());
			     exit(10);
			}

			else exit(11); //delete it?
		      
		}

		//else continue;

		/*
			Question 2) Adding wait
			Rather than "else continue", adding "else wait(NULL)"
			will make sure that the current child process is terminated
			before its parent. Parent will wait for child to terminate
			and then parent will continue.
		*/

		else wait(NULL);

	}

}
