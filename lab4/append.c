/**
	Name: Edxio Kraudy Mora
	Date: October 19, 2020
	Student ID: 110006224
*/

#include <stdio.h>

int main (int argc, char *argv[]) {

	FILE *f1, *f2, *f3, *f4;
	char c;

	f1 = fopen(argv[1], "r");
	f2 = fopen(argv[2], "r");
	f3 = fopen(argv[3], "r");
	f4 = fopen(argv[4], "w");
	
	do {
		c = getc(f1);
		fputc(c, f4);

	} while (c != EOF);

	do {
		c = getc(f2);
		fputc(c, f4);

	} while (c != EOF);

	do {
		c = getc(f3);
		fputc(c, f4);

	} while (c != EOF);


	fclose(f1);
	fclose(f2);
	fclose(f3);
	fclose(f4);

}
