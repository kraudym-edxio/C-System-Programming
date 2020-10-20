#include <stdio.h>

int main (int argc, char *argv[]) {  

	/**
	The other potential problem with this program is initializing fileSize to -1. 
	This doesn't make sense in context because a file cannot be of a negative size.
	Indexing starts at postion zero, thus it makes more sense to initially consider a
	file to be size zero before characters are counted.  
	*/

	FILE *fd;
	
	int ch;

	//int fileSize = -1;
	int fileSize = 0;

	fd = fopen(argv[1], "r+");      

/*	do{

		ch=getc(fd);  
		//printf("ch=%c ", ch);
		fileSize++;
		//printf("fileSize=%d\n", fileSize);

	} while( ch != EOF);
*/
	while ((ch = getc(fd)) != EOF) {
		fileSize++;
	}
	
	printf("Size of %s is %d\n", argv[1], fileSize);

}
