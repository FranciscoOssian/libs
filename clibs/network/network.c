#include "network.h"

#include<stdio.h>
#include<sys/socket.h> 
#include<arpa/inet.h>
#include<string.h> //strcpy
#include <stdlib.h>
#include<netdb.h>	//hostent
#include<unistd.h>

void getHostByDomainName(char *domain, char * ip){
  struct hostent *he;
	struct in_addr **addr_list;
	int i;
  if ( (he = gethostbyname( domain ) ) == NULL){
		printf("error gethostbyname");
		return;
	}

  addr_list = (struct in_addr **) he->h_addr_list;

  for(i = 0; addr_list[i] != NULL; i++) {
		//Return the first one;
		strcpy(ip , inet_ntoa(*addr_list[i]) );
	}

}


void fetch(char * domain, long int r_size, char * server_reply){
  FILE *cache;
  fopen("./","w");
  char ip[20];
  getHostByDomainName(domain, ip);
  int socket_desc;
  struct sockaddr_in server;
	char *message = "GET /users/defunkt HTTP/1.1\r\n\r\n";

  //Create socket
	socket_desc = socket(AF_INET , SOCK_STREAM , 0);
  if (socket_desc == -1) printf("Could not create socket");

  server.sin_addr.s_addr = inet_addr(ip);
  server.sin_family = AF_INET;
  server.sin_port = htons( 80 );

  if (connect(socket_desc , (struct sockaddr *)&server , sizeof(server)) < 0){
		puts("connect error");
    return;
	}

	if( send(socket_desc , message , 37 , 0) < 0){
		puts("Send failed");
    return;
	}

	if( recv(socket_desc, server_reply , r_size , 0) < 0){
		puts("recv failed");
    return;
	}

  close(socket_desc);

  return;
}