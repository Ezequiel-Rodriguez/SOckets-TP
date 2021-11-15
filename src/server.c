// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com
#include <arpa/inet.h>
#include <challenges.h>
#include <netdb.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <time.h>
#include <unistd.h>

#define PORT 8080
#define HOST "0.0.0.0"
#define BACKLOG 10

static void startChallenges(int clientfd);
const int new_sec __attribute__((section(".RUN_ME")));

int main(void) {

  int yes = 1, socketfd, childfd;
  struct sockaddr_in addr;
  struct sockaddr_storage peer_addr;
  socklen_t addr_size;

  char buff[256];

  socketfd = socket(AF_INET, SOCK_STREAM, 0);

  if (socketfd == -1) {
    perror("Error in socket creation");
    return -1;
  }

  if (setsockopt(socketfd, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(yes)) == -1) {
    perror("Error in socket setting");
    return 1;
  }

  addr.sin_family = AF_INET;
  addr.sin_port = htons(PORT);
  addr.sin_addr.s_addr = inet_addr(HOST);

  if (bind(socketfd, (struct sockaddr *)&addr, sizeof(addr)) == -1) {
    perror("bind");
    return -1;
  }

  if (listen(socketfd, BACKLOG) == -1) {
    perror("listen");
    return -1;
  }

  addr_size = sizeof(peer_addr);

  childfd = accept(socketfd, (struct sockaddr *)&peer_addr, &addr_size);

  if (childfd < 0) {
    perror("accept");
    return -1;
  }

  close(socketfd);

  startChallenges(childfd);

  close(childfd);
  return 0;
}

static void startChallenges(int clientfd) {

  int answer = 0, level = 0;
  FILE *clientFile = fdopen(clientfd, "r");

  system("clear");
  while (level < MAX_CHALLENGES && answer != -1) {
    if ((answer = challenges[level].issue(
             challenges[level].ans, challenges[level].investigation,
             challenges[level].message, clientFile)) == 1) {
      level++;
    } else if (answer == -1) {
      fclose(clientFile);
      return;
    } else {
      sleep(1);
    }
    system("clear");
  }

  fclose(clientFile);

  printf("\033[1;1H\033[2J");

  printf("Felicitaciones, finalizaron el juego. Ahora deberán implementar el "
         "servidor que se comporte como el servidor provisto\n\n");
  return;
}
