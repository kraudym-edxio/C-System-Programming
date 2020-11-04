/*
	System Programming: Assignment 3
	By: Edxio Kraudy Mora (110006224)
	Date: Tuesday November 3, 2020
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>

//Global variables
int status;

//Implementation of childFunction
int childFunction (char *line) {

	int int1, int2; //Numbers
	char char1; //Operator

	write(1, "I am a child working for my parent\n", 36);
	sscanf(line, "%d %c %d", &int1, &char1, &int2);

	//Wrong statement detected
	if ((sscanf(line, "%d %c %d", &int1, &char1, &int2)) != 3) {
		exit(50);
	}

	//Division by zero detected
	if (char1 == '/' && int2 == 0) {
		exit(100);
	}

	switch (char1) {

		case '+': //Addition
			sprintf(line, "%d %c %d = %d\n", int1, char1, int2, int1 + int2);
			write(1, line, strlen(line));
			break;

		case '*': //Multiplication
			sprintf(line, "%d %c %d = %d\n", int1, char1, int2, int1 * int2);
			write(1, line, strlen(line));
			break;

		case '-': //Subtraction
			sprintf(line, "%d %c %d = %d\n", int1, char1, int2, int1 - int2);
			write(1, line, strlen(line));
			break;

		case '/': //Division
			sprintf(line, "%d %c %d = %d\n", int1, char1, int2, int1 / int2);
			write(1, line, strlen(line));
			break;

		default: //Wrong operator detected
			exit(200);
			break;

	}

	exit(0);

}

int main (int argc, char *argv[]) {

	write(1, "This program makes simple arithmetics\n", 39);

	while (1) { //Infinite loop condition
	
		char str[50] = {0};
		write(1, "Enter an arithmetic statement: ", 31);
		read(0, str, sizeof(str));

		int pid = fork();

		//Checking if fork() successful
		if (pid < 0) {
			perror("Cannot fork\n");
			exit(0);
		}

		else if (pid == 0) { //Child
			childFunction(str);
		}

		else { //Parent

			write(1, "Created a child to make your operation, waiting\n", 49);
			wait(&status);

			if (WEXITSTATUS(status) == 50) {
				write(1, "Wrong Statement\n", 17);
			}

			else if (WEXITSTATUS(status) == 100) {
				write(1, "Division by zero\n", 18);
			}

			else {
			
				if (WEXITSTATUS(status) == 200) {
					write(1, "Wrong operator\n", 16);
				}
			
			}

		}

	}

	return 0;

}
