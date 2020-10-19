#include <stdio.h>

int main (int argc, char *argv[]) {

	FILE *f1, *f2;

	int ch;
	int i = 0;
	int fileSize = -1;

	f1 = fopen(argv[1], "r");
	f2 = fopen(argv[2], "w");

	do {
		ch = getc(f1);
		fileSize++;

	} while (ch != EOF);

	while (++i <= fileSize) {
		fseek(f1, -i, SEEK_END);
		ch = fgetc(f1);
		fputc(ch, f2);
	}

	fclose(f1);
	fclose(f2);

}
