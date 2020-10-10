#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

int main (int argc, char *argv[]) {

	//Open the file for reading only
	int fd1 = open(argv[1], O_RDONLY);

	int fileSize = lseek(fd1, 0, SEEK_END); //Determine fileSize using lseek
	printf("The size of the file is: %d.\n", fileSize);

	//Close the file
	close(fd1);

}
