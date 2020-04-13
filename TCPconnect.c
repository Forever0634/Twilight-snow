
#include<netinet/in.h>

#include<arpa/inet.h>

#include<unistd.h>

#include<stdio.h>

#include<string.h>

#include<stdlib.h>
#include <time.h>

#define MAXLINE 4098

 

int main(int argc, char **argv)

{

  int sockfd, n;

  struct sockaddr_in servaddr;

 

  //input the IP address and port(from argv[2] to argv[3])

  if (argc != 4) {

    printf("usage: illegal the cmd\n");

    return -1;

  }

 

  int i,j=atoi(argv[3])-atoi(argv[2])+1;

  //atoi():char* to int
   srand((int)time(NULL)); 

 while(j--) {
  //sleep(30);  
    
     i=(rand()/(atoi(argv[3])))+atoi(argv[2]);
   if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {

      printf("socket error\n");

      return -1;

    }
  
 

    //include in string.h

    bzero(&servaddr, sizeof(servaddr));

    servaddr.sin_family = AF_INET;

    servaddr.sin_port = htons(i);

    //inet_pton include in <arpa/inet.h>

    if (inet_pton(AF_INET, argv[1], &servaddr.sin_addr) <= 0) {

      printf("inet_pton error\n");

    }

 

    if (connect(sockfd, (struct sockaddr*) &servaddr, sizeof(servaddr)) < 0) {

     //printf("unopened port: %d\n", i);

      close(sockfd);

      continue;

    }

    else {

      printf("opend port: %d\n", i);

      close(sockfd);

      continue;

    }


  }

 

  exit(0);

}

