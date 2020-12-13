#include<unistd.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<string.h>
#include<netdb.h>
#include<netinet/in.h>
#include <arpa/inet.h>

#include<stdio.h>
#include<stdlib.h>
#include<signal.h>

int main (int argc, char *argv[]){  

	char buffer[100];
	int csd;  

	socklen_t len;
	struct sockaddr_in servAdd; //Server socket address

	csd = socket(AF_INET, SOCK_STREAM, 0);

	servAdd.sin_family = AF_INET;  
	servAdd.sin_addr.s_addr = inet_addr(argv[1]);

	servAdd.sin_port = 50000;  

	connect(csd, (struct sockaddr *) &servAdd,  sizeof(servAdd));

	read(csd, buffer, 100);

	fprintf(stderr, "%s\n", buffer);

}
