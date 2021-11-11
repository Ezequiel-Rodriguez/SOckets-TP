#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <string.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8080
#define BACKLOG 10



int main(void){

   int yes = 1, socketfd, childfd;
   struct sockaddr_in addr;
   struct sockaddr_storage peer_addr;
   socklen_t addr_size;

    /* int socket(int domain, int type, int protocol)
    *  creates  an  endpoint  for communication and returns a file descriptor that refers to that endpoint.
       The file descriptor returned by a successful call will be the lowest-numbered file  descriptor  not  currently
       open for the process.
    *  DOMAIN:
       specifies a communication domain; this selects the protocol family which will be used for
       communication. (AF_UNIX recommended by agodio)  
    *  TYPE: specifies the communication semantics. (SOCK_STREAM recomendación de agodio). The communications protocols 
       which implement a SOCK_STREAM ensure that data is not lost or duplicated.
    *  PROTOCOL: specifies a particular protocol to be used with the socket.  Normally only a single protocol  ex‐
       ists  to support a particular socket type within a given protocol family, in which case protocol can be speci‐
       fied as 0.
    */
   socketfd = socket(AF_INET, SOCK_STREAM, 0);
    
   if(socketfd == -1){
      printf("Error in socket creation");
      //perror("Error: socket creation")
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

   if (bind(socketfd, (struct sockaddr *) &addr, sizeof(addr)) == -1){
      perror("Error in socket creation");
      //perror("Error: socket creation")
      return -1;
   }

   if(listen(socketfd, BACKLOG) == -1){
      perror("Error while listening");
      return -1;
   }

   addr_size = sizeof(peer_addr);
   childfd = accept(socketfd, (struct sockaddr *) &peer_addr, &addr_size);

   if(childfd < 0){
      perror("Error while listening");
      return -1;
   }
   close(socketfd);

   /* Code to deal with incoming connection(s)... */

   /* Game */

   close(childfd);
}