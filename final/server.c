#include<unistd.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<string.h>
#include<netdb.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>


int main (int argc, char *argv[]){

	char buffer[100] = "Hello, here is my message\n";  

	int sd, client;
	socklen_t len;

	struct sockaddr_in servAdd; //server socket address  
	struct sockaddr_in cliAdd; //client socket address

	sd = socket(AF_INET, SOCK_STREAM, 0);
  
	servAdd.sin_family = AF_INET;  
	servAdd.sin_addr.s_addr = inet_addr("137.207.82.53"); // or use INADDR_ANY;

	servAdd.sin_port = 50000; // a port number

	bind(sd,(struct sockaddr*)&servAdd,sizeof(servAdd));  

	listen(sd, 5);

	while(1){

		len = sizeof(cliAdd);

		client=accept(sd,(struct sockaddr*)&cliAdd, &len);  //accept (sd, NULL, NULL);

		write(client, buffer, strlen(buffer) + 1);  

		close(client);
		break;
	}
}


