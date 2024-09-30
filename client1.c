#include <sys/socket.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#define PORT 7350
int main() {
    int sockfd;
    struct sockaddr_in server;
    if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
        printf("Socket creation failed\n");
    } else {
        printf("Socket creation successful\n");
    }
    server.sin_family = AF_INET;
    server.sin_port = htons(PORT);
    server.sin_addr.s_addr = INADDR_ANY;  //inet_addr("127.0.0.1");
    memset(&(server.sin_zero), '\0', 8);
    int num1, num2;
    printf("Enter first number: ");
    scanf("%d", &num1);
    printf("Enter second number: ");
    scanf("%d", &num2);
    sendto(sockfd, &num1, sizeof(int), 0, (struct sockaddr *)&server, sizeof(server));
    sendto(sockfd, &num2, sizeof(int), 0, (struct sockaddr *)&server, sizeof(server));
    printf("Numbers sent to server: %d, %d\n", num1, num2);
    close(sockfd);
    return 0;
}

