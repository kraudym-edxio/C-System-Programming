#include<stdio.h>
#include <unistd.h>

int main() {
	
 	printf("before fork, my pid is %d\n" , getpid());
  
	fork(); //L1 one child process is created
	fork(); //L2 two child processes will be created
	fork(); //L3 four child processes will be created

	printf("done, my pid is %d\n", getpid());

}

/*
Total of 8 processes (original parent + new children)

		L1
	       /  \
	     L2    L2
            /  \  /  \
          L3  L3  L3  L3
*/
