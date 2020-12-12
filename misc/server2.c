#include<unistd.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<string.h>
#include<netdb.h>
#include<stdlib.h>
#include<stdio.h>


void child(int sd);

int main(int argc, char *argv[]){ 
	char buffer[100];
	int sd, cd;  
	socklen_t len;
	
	struct sockaddr_in servAdd, cliAdd;

	sd = socket(AF_INET, SOCK_STREAM, 0);  

	servAdd.sin_family = AF_INET;  
	servAdd.sin_addr.s_addr = INADDR_ANY;  
	servAdd.sin_port = 7777;
	
	bind(sd,(struct sockaddr*)&servAdd,sizeof(servAdd));  

	listen(sd, 5);

	while(1){
		len = sizeof(cliAdd);
		cd = accept(sd, (struct sockaddr *) &cliAdd, &len);  
		if(fork()==0)
			child(cd);  
		close(cd);
	}
}


void child(int cd){  

	char line[255];

	while(1){
		fprintf(stderr, "Enter a line to send to client\n");  
		scanf("%s", line);
		write(cd, line, strlen(line)+1);  
		if(!read(cd, line, 255)){  
			close(cd);
			exit(0);
		}
		fprintf(stderr, "Client sent back: %s\n", line);
	}
}
