#include<string.h>
#include<netdb.h>
#include<netinet/in.h>
#include <arpa/inet.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main (int argc, char *argv[]) {  
	
	char buffer[100];
	int csd;  socklen_t len;
	
	struct sockaddr_in servAdd; //server socket address

	csd = socket(AF_INET, SOCK_STREAM, 0);

	servAdd.sin_family = AF_INET;  
	servAdd.sin_addr.s_addr = inet_addr(argv[1]);  
	servAdd.sin_port = 50000;

	connect(csd, (struct sockaddr *) &servAdd,  sizeof(servAdd));

	//Prompt user to enter a command (lscpu)
	fprintf(stderr, "Please help me execute this command: ");
	scanf("%s", buffer);	

	write(csd, buffer, strlen(buffer) + 1);

	//Display output and termination message	
	fprintf(stderr, "The output of this command is: \n");
	execlp("lscpu", "lscpu", (char *)NULL);
	fprintf(stderr, "Thank you. Client terminated.\n");

}	
