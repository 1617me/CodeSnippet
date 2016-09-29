#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>

#define MAXLINE 1024
#define SERVERPORT 8887

int main(){
    int listenfd, clientfd;
    char ipstr[16];
    socklen_t addrlen;
    struct sockaddr_in serveraddr, clientaddr;

    listenfd = socket(AF_INET, SOCK_STREAM, 0);
    bzero(&serveraddr, sizeof(serveraddr));
    serveraddr.sin_family = AF_INET;
    serveraddr.sin_port   = htons(SERVERPORT);
    serveraddr.sin_addr.s_addr = htonl(INADDR_ANY);

    bind(listenfd, (struct sockaddr*)&serveraddr, sizeof(serveraddr));
    listen(listenfd, 128);

    while(1){
	bzero(&clientfd, sizeof(clientfd));
	accept(listenfd, (struct sockaddr*)&clientfd, &addrlen);
	printf("clientip:%s, port:%d, clientfd:%d\n",
		inet_ntop(AF_INET, &clientaddr.sin_addr.s_addr, ipstr, sizeof(ipstr)),
		ntohs(clientaddr.sin_port),
		clientfd);
	close(clientfd);
    }
    close(listenfd);
    return 0;
}
