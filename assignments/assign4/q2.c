#include <stdio.h>
#include <unistd.h>

int main() {  
	
	int i;

	printf("before fork, my pid is %d\n" , getpid());  

	for (i = 0; i < 3; i++) {

		if (fork() == 0)
			printf("Hi, I am child. My pid is %d\n", getpid());
	
	}
	
}

/*

Parent:

First Iteration (i = 0):
 
	--- fork() ---> (i = 1) --- fork() ---> (i = 2) --- fork() ---> [Hi...]
						[Hi...]                       

			(i = 2) --- fork() ---> [Hi...]  


			[Hi...] 			

Second Iteration (i = 1):

	--- fork() ---> (i = 2) --- fork() ---> [Hi...] 
			[Hi...]

Third Iteration (i = 2)

	--- fork() ---> [Hi...]

[Hi...]

*/
