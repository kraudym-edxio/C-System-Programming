#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

int main (int argc, char *argv[]) {

	int fd1;
	void filecopy(int, int);

	if (argc == 1) {
		filecopy(0, 1);
	}

	else {

		while (--argc > 0) {
			
			if ((fd1 = open(*++argv, O_RDONLY)) == 0) {
				printf("cat: can not open %d\n", *argv);
				return 1;
			}

			else {
				filecopy(fd1, 1);
				close(fd1);
			}

		}

	}

	return 0;

}

void filecopy (int ifd, int ofd) {

	int c;

	while ((read(ifd, &c, 1)) != 0) {
		write(ofd, &c, 1);
	}

}
