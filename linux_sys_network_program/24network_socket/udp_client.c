#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define SERVERPORT 8000
#define MAXLEN 1024

int main(int argc, char **argv){
    struct sockaddr_in serveraddr;
    int sockfd, n;
    char buf[MAXLEN];
    char ipstr[INET_ADDRSTRLEN];
    socklen_t serveraddr_len;
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);

    bzero(&serveraddr, sizeof(serveraddr));
    serveraddr.sin_family = AF_INET;
    inet_pton(AF_INET, "127.0.0.1", &serveraddr.sin_addr.s_addr);
    serveraddr.sin_port = htons(SERVERPORT);

    while(fgets(buf, MAXLEN, stdin) != NULL){
	n = sendto(sockfd, buf, strlen(buf), 0, (struct sockaddr*)&serveraddr, sizeof(serveraddr));
	recvfrom(sockfd, buf, MAXLEN, 0, NULL, 0);
	write(STDOUT_FILENO, buf, n);
    }
    close(sockfd);
    return 0;
}
