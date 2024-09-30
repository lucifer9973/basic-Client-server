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
    struct sockaddr_in server, client;
    int s= (sockfd = socket(AF_INET, SOCK_DGRAM, 0));
    if (s == -1) {
        printf("Socket creation failed\n");
    } else {
        printf("Socket creation successful\n");
    }
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(PORT);
    memset(&(server.sin_zero), '\0', 8);
    int b = bind(sockfd, (struct sockaddr *)&server, sizeof(server));
    if (b == -1) {
        printf("Bind creation error\n");
    } else {
        printf("Socket successfully bound to port %d\n", PORT);
    }
    int num1, num2;
    socklen_t client_len = sizeof(client);
    recvfrom(sockfd, &num1, sizeof(int), 0, (struct sockaddr *)&client, &client_len);
    recvfrom(sockfd, &num2, sizeof(int), 0, (struct sockaddr *)&client, &client_len);
    printf("First number received: %d\n", num1);
    printf("Second number received: %d\n", num2);
    close(sockfd);
    return 0;
}
