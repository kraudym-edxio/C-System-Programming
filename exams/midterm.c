#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main (int argc, char *argv[]) {

	FILE *fd;
	int ch;
	int lineCount = 0;
	int fileSize = 0;
	int wordCount = 0;
	
	fd = fopen(argv[1], "r+"); //Open file for reading

	//Determining the number of lines
	while ((ch = getc(fd)) != EOF) {
	
		if (ch == '\n') {
			lineCount++;
		}

		if (ch == ' ' || ch == '\n') {
			wordCount++;
		}

		fileSize++;		

	}

	printf("%d\t %d\t %d\n", lineCount, wordCount, fileSize); 

	//Create counting.bin using system I/O
	int fd2 = open("counting.bin", O_CREAT | O_WRONLY | O_TRUNC , 0777);	

	char str[3];
	str[1] = lineCount;
	str[2] = wordCount;
	str[3] = fileSize;

	write(fd2, str, sizeof(str));
	
	//Writing to terminal window
	char x;

	while ((read(fd2, &x, 1)) != 0) {
		write(1, &x, 1);
	}

	close(fd2); //Close fd2 using system I/O
	fclose(fd); //Close fd using standard I/O

}
