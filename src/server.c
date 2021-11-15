// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com
#include <arpa/inet.h>
#include <netdb.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <time.h>
#include <unistd.h>
#include <challenges.h>

#define PORT 8080
#define BACKLOG 10

static void startChallenges(int clientfd);

int main(void) {

  int yes = 1, socketfd, childfd;
  struct sockaddr_in addr;
  struct sockaddr_storage peer_addr;
  socklen_t addr_size;

  char buff[256];

  /* int socket(int domain, int type, int protocol)
  *  creates  an  endpoint  for communication and returns a file descriptor that
  refers to that endpoint. The file descriptor returned by a successful call
  will be the lowest-numbered file  descriptor  not  currently open for the
  process.
  *  DOMAIN:
     specifies a communication domain; this selects the protocol family which
  will be used for communication. (AF_UNIX recommended by agodio)
  *  TYPE: specifies the communication semantics. (SOCK_STREAM recomendación de
  agodio). The communications protocols which implement a SOCK_STREAM ensure
  that data is not lost or duplicated.
  *  PROTOCOL: specifies a particular protocol to be used with the socket.
  Normally only a single protocol  ex‐ ists  to support a particular socket type
  within a given protocol family, in which case protocol can be speci‐ fied as
  0.
  */
  socketfd = socket(AF_INET, SOCK_STREAM, 0);

  if (socketfd == -1) {
    perror("Error in socket creation");
    return -1;
  }

  if (setsockopt(socketfd, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(yes)) == -1) {
    perror("Error in socket setting");
    return 1;
  }

  memset(&addr, 0, sizeof(struct sockaddr_in)); // clear structure

  addr.sin_family = AF_INET;
  addr.sin_port = htons(PORT);
  addr.sin_addr.s_addr = inet_addr("0.0.0.0");

  if (bind(socketfd, (struct sockaddr *)&addr, sizeof(addr)) == -1) {
    perror("Error in socket creation");
    return -1;
  }

  if (listen(socketfd, BACKLOG) == -1) {
    perror("Error while listening");
    return -1;
  }

  addr_size = sizeof(peer_addr);

  childfd = accept(socketfd, (struct sockaddr *)&peer_addr, &addr_size);

  if (childfd < 0) {
    perror("Error while listening");
    return -1;
  }

  close(socketfd);

  startChallenges(childfd);

  /* Code to deal with incoming connection(s)... */
  /* while (fgets(buff, 256, clientfd) != NULL) {
    printf("%s", buff);
    sleep(2);
    system("clear");
  } */
  /* Game */

  close(childfd);
  return 0;
}

static void startChallenges(int clientfd){

    int answer = 0, level = 0;
    FILE *clientFile = fdopen(clientfd, "r");
    char *response = malloc(sizeof(char) * CAPACITY);

    if (response == NULL){
        fclose(clientFile);
        return;
    }

    while (level < MAX_CHALLENGES && answer != -1)
    {
        Challenge challenge = challenges[level];
                              
        if ((answer = challenge.issue(challenge.ans, challenge.investigation, response, clientFile)) == 1)
        {
            level++;
        }
        else
        {
            sleep(2);
            system("clear");
        }
    }

    free(response);
    fclose(clientFile);

    if (answer == -1){
        return;
    }

    printf("\033[1;1H\033[2J");

    printf("Felicitaciones, finalizaron el juego. Ahora deberán implementar el servidor que se comporte como el servidor provisto\n\n");
}