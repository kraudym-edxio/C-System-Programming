#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>

int main (int argc, char *argv[]) {

	int fd1;		

	char str[] = "101   GM\tBuick\t2010\n102   Ford\tLincoln\t2005\n";

	fd1 = open("list1.txt", O_CREAT | O_WRONLY | O_TRUNC, 0777);
	
	write(fd1, str, sizeof(str));

	close(fd1);

}
