#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "unistd.h"
#include "sys/types.h"
#include "sys/socket.h"
#include "netinet/in.h"
#include <netdb.h>
#include "unistd.h"

int side_select,opt,cnt=0,buff_size;

int sockfd, newsockfd, portno;
socklen_t clilen;
char *__ip=NULL;
struct sockaddr_in serv_addr, cli_addr;
int status_wr=0;
struct hostent *server;


void error(const char *msg){
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[]){
    //detects arguments
    while((opt=getopt(argc,argv,"s:c:p:b:n:"))!=-1){
        switch (opt) {
        case 's':
            side_select='s';
            break;
        case 'c':
            side_select='c';
        case 'p':
            portno=*optarg;
            break;
        case 'b':
            buff_size=*optarg;
            break;
        case 'n':
            __ip=optarg;
            break;
        default:
            break;
        }

    }

    if(argc<4){
        printf("lost parameters\n Usage: %s s/c port_no buff_size hostname\n s for server c for client.\n -h for help\n",argv[0]);
        error("lost parameters");
        return -1;
    }
    //server side
    else if(side_select=='s'){
        printf("Working server side\n");
        char buffer[buff_size];

        sockfd=socket(AF_INET, SOCK_STREAM, 0);
        if(sockfd<0)
            error("Can not opening socket");
        bzero((char *) &serv_addr, sizeof(serv_addr));
        serv_addr.sin_family = AF_INET;
        serv_addr.sin_addr.s_addr = INADDR_ANY;
        serv_addr.sin_port = htons(portno);

        if(bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr))<0)
            error("Error on binding");
        listen(sockfd,5);
        clilen=sizeof(cli_addr);
        newsockfd =accept(sockfd,(struct sockaddr *) &cli_addr, &clilen);
        if(newsockfd<0)
            error("Error on accept");
        bzero(buffer,buff_size);
        status_wr=read(newsockfd,buffer,(buff_size-1));
        if(status_wr<0) error("Error reading from socket");
        printf("Message: %s\n",buffer);
        status_wr=write(newsockfd,"Test 1.. 2.. 3..",16);
        if(status_wr<0) error("Error: writing to socket");
        printf("Do you want to resume? y/n\n");
        char c;
        scanf("%c",&c);
        if(c=='n'){
            close(newsockfd);
            close(sockfd);
            return 0;
        }

    }
    //client side
    else if(side_select=='c'){

        printf("Working client side");
        char buffer[buff_size];
        sockfd=socket(AF_INET,SOCK_STREAM,0);
        if(sockfd<0) error("Error opening socket");
        server=gethostbyname(argv[4]);
        if(server==NULL) error("Host not found");
        bzero((char *) &serv_addr, sizeof(serv_addr));
        serv_addr.sin_family=AF_INET;
        bcopy((char *) &server->h_addr, (char *) &serv_addr.sin_addr.s_addr, server->h_length);

        serv_addr.sin_port=htons(portno);
        if(connect(sockfd,(struct sockaddr *) &serv_addr, sizeof(serv_addr))<0) error("Connection error");
        printf("Please enter the message: ");
        bzero(buffer,buff_size);
        fgets(buffer,(buff_size-1),stdin);
        status_wr=write(sockfd,buffer,strlen(buffer));
        if(status_wr<0) error("Error writing socket");
        bzero(buffer,buff_size);
        status_wr=read(sockfd,buffer,(buff_size-1));
        if(status_wr<0) error("Error reading from socket");
        printf("%s\n",buffer);
        printf("Do you want to resume? y/n\n");
        char c;
        scanf("%c",&c);
        if(c=='n'){
        close(sockfd);
        return 0;
        }
    }
    else
        printf("programdan çıkılıyor\n");
}


