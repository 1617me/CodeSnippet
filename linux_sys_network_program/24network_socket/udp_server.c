#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>

#define MAXLINE 80
#define SERVERPORT 8000


int main(int argc, char **argv){
    struct sockaddr_in serveraddr, clientaddr;
    socklen_t clientaddr_len;
    int sockfd;
    char buf[MAXLINE];
    char str[INET_ADDRSTRLEN];
    int i , n;

    sockfd = socket(AF_INET, SOCK_DGRAM, 0);

    bzero(&serveraddr, sizeof(serveraddr));
    serveraddr.sin_family = AF_INET;
    serveraddr.sin_port   = htons(SERVERPORT);
    serveraddr.sin_addr.s_addr = htonl(INADDR_ANY);

    bind(sockfd, (struct sockaddr*)&serveraddr, sizeof(serveraddr));

    while(1){
	clientaddr_len = sizeof(clientaddr);
	n = recvfrom(sockfd, buf, MAXLINE, 0, (struct sockaddr*)&clientaddr, &clientaddr_len);
	printf("recv from %s port %d\n",
		inet_ntop(AF_INET, &clientaddr.sin_addr.s_addr,str, sizeof(str)),
		ntohs(clientaddr.sin_port));


	// do sth
	for(i =0; i < n; i++){
	    buf[i] = toupper(buf[i]);
	}
	sendto(sockfd, buf, n, 0, (struct sockaddr*)&clientaddr, sizeof(clientaddr));

    }
    close(sockfd);
    return 0;
}
