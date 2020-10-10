#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>

int main (int argc, char *argv[]) {

	char c;
	char x;
	char str[100];
	
	int fd1 = open(argv[1], O_RDWR | O_APPEND, 0777);
	
	//Display file contents
	while((read(fd1, &c, 1)) != 0) {
		write(1, &c, 1);
	}

	//Asking for user input
	printf("\nWhat information would you like to append?: ");
	scanf("%s", str);

	//Appending
	write(fd1, str, sizeof(str));

	//Display file content after append
	while((read(fd1, &x, 1)) != 0) {
		write(1, &x, 1);
	}
	
	close(fd1);

}
