/*
	Name: Edxio Kraudy Mora
	Date: November 14, 2020
	Lab Section 51
*/


#include "smallsh.h"
#include <string.h>
#include <stdlib.h>

int gettok(char **outptr);
int runcommand(char **cline, int where);

void procline(void) {
	
	char *arg[MAXARG + 1]; 
	int toktype; 
	int narg; 
	int type; 

	narg = 0;

	for (;;) {
	   
		switch (toktype = gettok(&arg[narg])) {
		
			case ARG:
				printf("args[narg = %d] = %s\n", narg, arg[narg]);				
				if (narg < MAXARG)
					narg++;
				break;
		
			case EOL:
				printf("args[narg = %d] = %s\n", narg, arg[narg]);
			case SEMICOLON:
			case AMPERSAND:
				if (toktype == AMPERSAND)
					type = BACKGROUND;
				
				else
					type = FOREGROUND;
			
				if (narg != 0) {
					arg[narg] = NULL;
					runcommand(arg, type);
				}

				if (toktype == EOL)
					return;
			
				narg = 0;
				break;
	  	}
	  
		//Added for assignment 3
                //if (!strcmp(arg[narg-1],"exit"))
			//exit(5);

	}

}
