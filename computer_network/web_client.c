#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
   int cSock;
   struct sockaddr_in srvAddr;
   char *srvIp = NULL;
   char buffer[BUFFER_SIZE];
   int sentSize, rcvSize;
   int ret;

    if (argc != 2) {
        printf("Usage: %s IP_addr Port\n", argv[0]);
        exit(0);
    }

    srvIp = argv[1];
    cSock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP); 
    
    if (cSock < 0) {
        printf("socket() failed\n");
        exit(0); 
    }

    memset(&srvAddr, 0, sizeof(srvAddr));
    srvAddr.sin_family = AF_INET;
    srvAddr.sin_addr.s_addr = inet_addr(srvIp);
    srvAddr.sin_port = htons(80);
    ret = connect(cSock, (struct sockaddr *)&srvAddr, sizeof(srvAddr)); 
    
    if (ret < 0) {
        printf("Client cannot connect to the Server.\n");
        exit(0); 
    }
    
    write(cSock,  "GET / HTTP/1.1\r\n", strlen("GET / HTTP/1.1\r\n"));
    write(cSock, "Host: me.go.kr\r\n", strlen("Host: me.go.kr\r\n"));
    write(cSock, "\r\n", strlen("Host: me.go.kr\r\n"));
    rcvSize = read(cSock, buffer, BUFFER_SIZE);
    printf("%s", buffer);
    close(cSock);
}
