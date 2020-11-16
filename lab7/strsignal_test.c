#include <stdio.h>
#include <signal.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

/*
	Name: Edxio Kraudy Mora (110006224)
	Date: November 16, 2020
	Lab Section 51
*/


/*
	After inspecting the man page for strsignal, I have
	discovered that it returns a string describing a signal.
	The for loop will not exceed past signal number 64. This is
	so because signals after this number are unknown signals.
	I have discovered 64 signals. 
*/

int main (int argc, char *argv[]) {

	//For loop will display the name of the signal
	for (int x = 1; x < 65; x++) {
		printf("Signal name: %s\n", strsignal(x));
	}

	return 0;

}
