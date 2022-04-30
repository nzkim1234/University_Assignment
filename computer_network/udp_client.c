#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) { 
    int sock;
    struct sockaddr_in srvAddr;
    char *srvIp = NULL;
    unsigned short srvPort; 
    char buffer[BUFFER_SIZE]; 
    int sentSize, rcvSize; 
    unsigned int srvAddrLen;

    if (argc != 3) {
        printf("Usage: %s IP_addr Port\n", argv[0]); 
        exit(0);
    }

    srvIp = argv[1]; // 서버 IP를 명령 실행줄에서 입력 받음 
    srvPort = atoi(argv[2]); // 서버 포트를 명령 실행줄에서 입력 받음

    // UDP 용 소켓 생성
    // 이후 이 소켓을 사용할 때에는 "sock" 소켓 디스크립터를 사용 
    sock = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
    
    if (sock < 0) {
        printf("socket() failed\n");
        exit(0); 
    }

    memset(&srvAddr, 0, sizeof(srvAddr));
    srvAddr.sin_family = AF_INET; 
    srvAddr.sin_addr.s_addr=inet_addr(srvIp);
    srvAddr.sin_port = htons(srvPort);
    
    printf("Client is running.\n");
    
    while (1) {
        fgets(buffer, BUFFER_SIZE, stdin);
        buffer[strlen(buffer)-1] = '\0';

        sentSize = sendto(sock, buffer, strlen(buffer)+1, 0, (struct sockaddr *)&srvAddr, sizeof(srvAddr));
        
        if (sentSize != strlen(buffer)+1) {
            printf("sendto() sent a different number of bytes than expected\n");
            exit(0);
        }
        
        if (!strcmp(buffer, "quit")) break;
        
        printf("%s\n", buffer);

        srvAddrLen = sizeof(srvAddr);
        rcvSize = recvfrom(sock, buffer, BUFFER_SIZE, 0, (struct sockaddr *) &srvAddr, &srvAddrLen);
        
        if (rcvSize < 0) {
            printf("Error in recvfrom()\n");
            exit(0); 
        }
        
        if (!strcmp(buffer, "quit")) break;

        printf("[Server/%s:%d] %s\n", inet_ntoa(srvAddr.sin_addr), ntohs(srvAddr.sin_port), buffer);
    }
    close(sock);
    printf("Chat Closed.\n");
}