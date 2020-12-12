#include<string.h>
#include<netdb.h>
#include<netinet/in.h>
#include <arpa/inet.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>



int main(int argc, char *argv[]){  
	char buffer[100];
	int csd;  socklen_t len;
	
	struct sockaddr_in servAdd; //server socket address

	csd = socket(AF_INET, SOCK_STREAM, 0);

	servAdd.sin_family = AF_INET;  
	servAdd.sin_addr.s_addr = inet_addr(argv[1]);  
	servAdd.sin_port = 7777;

	connect(csd, (struct sockaddr *) &servAdd,  sizeof(servAdd));

	while(1){
		read(csd, buffer, 255);
		fprintf(stderr, "Serverâ€™s message: %s\n", buffer);  
		fprintf(stderr, "Enter a line to send server\n");  
		scanf("%s", buffer);
		if(buffer[0]=='$'){ 
                        close(csd);  
			exit(0);
		}
		write(csd, buffer, strlen(buffer)+1);
	}
}	


