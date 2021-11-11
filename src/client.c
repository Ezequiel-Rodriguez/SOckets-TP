#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <string.h>
#include <netdb.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_BUFF_LENGTH 256

int main(int argc, char * argv[]){

    int socketfd, port;
    struct sockaddr_in addr;

    char buff[MAX_BUFF_LENGTH];

    if(argc != 3){
        fprintf(stderr, "usage %s host port", argv[0]);
        return -1;
    }

    socketfd = socket(AF_INET, SOCK_STREAM, 0);

    if(socketfd < 0){
        perror("Error in socket creation");
        return -1;
    }

    port = atoi(argv[2]);

    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);

    if (inet_pton(AF_INET, argv[1], &addr.sin_addr) <= 0)
    {
        printf("Error while assigning adress");
        return -1;
    }


    if(connect(socketfd, (struct sockaddr *)&addr, sizeof(addr)) == -1){
        perror("Error while connecting to socket");
        return -1;
    }

    while(fgets(buff, MAX_BUFF_LENGTH, stdin) != NULL){

        if(write(socketfd, buff, strlen(buff)) < 0){ //que flags uso en send?
            perror("Error while writing through socket");
            return -1;
        }
    }

    close(socketfd);

}