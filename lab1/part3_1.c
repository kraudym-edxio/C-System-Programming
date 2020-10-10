#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

int main() {

/*
	I have discovered that if both O_CREAT and O_EXCL are used, open() will fail if the file already
	exists. If O_EXCL is used as a flag when opening a file that does not exist, open() will fail.
	If O_CREAT is used as a flag when opening a file that does not exist, the file will be created
	and open() will succeed. 

*/

	//Testing using O_CREAT
	int fd1 = open("myfile", O_CREAT | O_EXCL, 0700);
	
	if (fd1 < 0) {
		perror("Cannot open file");
		exit(1);
	}

	else {
		printf("The file \"myfile\" was created.\n");
	}

}
