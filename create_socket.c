#include<stdio.h>
#include<sys/socket.h>
#include<arpa/inet.h> //inet_addr

int main(){
	int socket_desc;
	struct sockaddr_in server;
	socket_desc = socket(AF_INET, SOCK_STREAM, 0); 
	char *message;
	//AF_INET is IPV4, SOCK_STREAM is TCP
	//SOCK_DGRAM is for UDP
	

	if(socket_desc == -1){
		printf("Could not create the  socket");
}
	server.sin_addr.s_addr = inet_addr("127.0.0.1");
	server.sin_family = AF_INET;
	server.sin_port = htons( 80 );
	//htons is for BigEndian Little Endian Matching anology
	

	//connect to remote  server; webserver port in which the server listens by default is 80
	if(connect(socket_desc, (struct sockaddr *)&server, sizeof(server)) < 0){
		puts("connection error :/");	
		return 1;
	}	
	puts("Connected! :)");

	//send message 
	message = "GET / HTTP/1.1\r\n\n";
	if(send(socket_desc, message, strlen(message), 0) < 0){
		puts("Send Failed!");
		return  1;
}
	puts("Data Sent!\n");
	return 0;

}

