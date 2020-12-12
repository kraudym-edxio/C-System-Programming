#include<unistd.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<string.h>
#include<netdb.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>


int main(int argc, char *argv[]){

	char buffer[100] = "Hello, here is my message\n";  

	int sd, client;
	socklen_t len;

	struct sockaddr_in servAdd; //server socket address  
	struct sockaddr_in cliAdd; //client socket address

	sd = socket(AF_INET, SOCK_STREAM, 0);
  
	servAdd.sin_family = AF_INET;  
	servAdd.sin_addr.s_addr = inet_addr("137.207.82.51"); //Or use INADDR_ANY
	//INADDR_ANY allows your program to work without
	//knowing the IP address of the machine it was running on  

	servAdd.sin_port = 7777; // a port number

	//All steps above are for calling bind.
	bind(sd,(struct sockaddr*)&servAdd,sizeof(servAdd));  

	listen(sd, 5);

	while(1) {

		len = sizeof(cliAdd);

		client = accept(sd,(struct sockaddr*)&cliAdd, &len);  //accept (sd, NULL, NULL);

		write(client, buffer, strlen(buffer) + 1);  

		close(client);

		break;

	}

}
