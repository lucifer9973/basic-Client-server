// client.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>
#define PORT 12345
#define MAXLINE 1024
int main() {
    int sockfd;
    struct sockaddr_in servaddr;
    char buffer[MAXLINE];
    int numbers[] = {1, 2, 3, 4, 5, 6, 7, 8, 9}; 
    int num_count = sizeof(numbers) / sizeof(numbers[0]);
    if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
        perror("socket creation failed");
        exit(EXIT_FAILURE);
    }
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = inet_addr("198.0.0.1"); 
    servaddr.sin_port = htons(PORT);
    sendto(sockfd, numbers, sizeof(numbers), 0, (const struct sockaddr *) &servaddr, sizeof(servaddr));
    int len = sizeof(servaddr);
    int n = recvfrom(sockfd, buffer, sizeof(buffer) - 1, 0, (struct sockaddr *) &servaddr, &len);
    if (n < 0) {
        perror("recvfrom failed");
        close(sockfd);
        exit(EXIT_FAILURE);
    }
    buffer[n] = '\0'; 
    printf("Server reply: %s\n", buffer);

    close(sockfd);
    return 0;
}
