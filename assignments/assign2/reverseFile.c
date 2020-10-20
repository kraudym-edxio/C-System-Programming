#include <stdio.h>

int main (int argc, char *argv[]) {

	FILE *fd1, *fd2;

	long arr[100];	
	char buffer[100];
	int x = 1;

	fd1 = fopen(argv[1], "r");
	fd2 = fopen(argv[2], "w");

	arr[0] = 0;

	while (!feof(fd1)) {

		fgets(buffer, 100, fd1);
		
		if (feof(fd1)) {
			break;	
		}
		
		arr[x] = ftell(fd1);
		x++;		

	}

	for (int y = x - 2; y >= 0; y--) {
	
		fseek(fd1, arr[y], 0);
		fgets(buffer, 100, fd1);
		fputs(buffer, fd2);		

	}

	fclose(fd1);
	fclose(fd2);

}
