/*
 * Author Tarkan Dalay
 * mail: tarkandalay52@gmail.com
 * date: 28/11/2016
 * rev:0.01b
 * 
 * */

#include <stdio.h>
#include <stdlib.h>
#include "main.h"

void error(const char *msg)
{
    perror(msg);
    exit(0);
}

int __exit_status(char *buff, char *close_sock){
    int n=0;
    for(int i=0;i<strlen(close_sock);i++){
        if(close_sock[i]!=buff[i])
            return 0;
        else
            n=1;
    }
    return n;
}

int main (int argc, char *argv[]) {
int cnt=0;

while((socket_1.opt=getopt(argc,argv,"sc:p:b:n:"))!=-1){

    cnt++;
    switch (socket_1.opt) {
    case 'c':
        socket_1.socket_status='c';
        printf("%s\n",optarg);
        printf("client selected\n");
        break;
    case 's':
        socket_1.socket_status='s';
        printf("server selected\n");
        break;
    case 'b':
        socket_1.buff_size=atoi(optarg);
        printf("Buffer size=%d\n",socket_1.buff_size);
        break;
    case 'p':
        socket_1.portnum=atoi(optarg);
        printf("port numarası= %d\n",socket_1.portnum);
        break;
    case 'n':
        socket_1.ip=optarg;
        printf("ip numarası=%s\n",socket_1.ip);
        break;
    default:
        break;
    }

    }

    if(socket_1.socket_status=='c')
        client(socket_1);
    else if (socket_1.socket_status='s')
        server(socket_1);

return 0;
 }
