#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>

#define SERVERPORT 8000
#define MAXLINE 1024

int main(int argc, char **argv){
    struct sockaddr_in serveraddr;
    int confd, len;
    char ipstr[] = "192.168.64.180";
    char buf[MAXLINE];
    if (argc < 2){
	printf("./client str\n");
	exit(1);
    }
    
    confd = socket(AF_INET, SOCK_STREAM, 0);
    bzero(&serveraddr, sizeof(serveraddr));
    serveraddr.sin_family = AF_INET;
    serveraddr.sin_port   = htons(SERVERPORT);
    inet_pton(AF_INET, ipstr, &serveraddr.sin_addr.s_addr);

    connect(confd, (struct sockaddr*)&serveraddr, sizeof(serveraddr));
    write(confd, argv[1], strlen(argv[1]));
    len = read(confd, buf, sizeof(buf));
    write(STDOUT_FILENO, buf, len);
    putchar(10);
    close(confd);
    return 0;
}
