#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define PORT 8888
#define MIN 50000
#define MAX 80000

int main() {
    int sockfd, newsockfd;
    socklen_t clilen;
    struct sockaddr_in serv_addr, clil_addr;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error opening socket");
        exit(1);
    }

    memset((char *)&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(PORT);

    if (bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("Error on binding");
        exit(1);
    }

    listen(sockfd, 5);
    clilen = sizeof(clil_addr);

    newsockfd = accept(sockfd, (struct sockaddr *)&clil_addr, &clilen);
    if (newsockfd < 0) {
        perror("Error on accept");
        exit(1);
    }

    srand(time(NULL));
    int random_num = MIN + rand() % (MAX - MIN + 1);

    char buffer[256];
    snprintf(buffer, sizeof(buffer), "%d", random_num);

    if (write(newsockfd, buffer, strlen(buffer)) < 0) {
        perror("Error writing to socket");
        exit(1);
    }

    close(newsockfd);
    close(sockfd);

    return 0;
}


