#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define SERVERPORT 8000
#define MAXLINE 1024

int main(){
    struct sockaddr_in serveraddr, clientaddr;
    int sockfd, addrlen, confd, len, i;
    char ipstr[16];
    char buf[MAXLINE];

    //1. socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    bzero(&serveraddr, sizeof(serveraddr));
    serveraddr.sin_family = AF_INET;
    serveraddr.sin_port   = htons(SERVERPORT);
    serveraddr.sin_addr.s_addr = htonl(INADDR_ANY);

    bind(sockfd, (struct sockaddr*)&serveraddr, sizeof(serveraddr));
    listen(sockfd, 128);

    while(1){
	bzero(&clientaddr, sizeof(clientaddr));
	addrlen = sizeof(clientaddr);
	confd = accept(sockfd, (struct sockaddr*)&clientaddr, &addrlen);
	inet_ntop(AF_INET, &clientaddr.sin_addr.s_addr, ipstr, sizeof(ipstr));
	printf("clientip:%s, port:%d, clientfd:%d\n",
		ipstr, ntohs(clientaddr.sin_port), confd);
	// do sth
	len = read(confd, buf, sizeof(buf));
	printf("----- len: %d\n", len);
	i = 0;
	while(i < len){
	    buf[i] = toupper(buf[i]);
	    i++;
	}
	write(confd, buf, len);
	close(confd);
    }
    close(sockfd);
    return 0;
}
