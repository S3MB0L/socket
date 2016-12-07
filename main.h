#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

struct socket_data{
    int opt;
    int portnum;
    char *ip;
    int buff_size;
    char socket_status;
}socket_1;

struct commands{
    char *close;
    char *status;
    char *set;
} command;

void error(const char *msg);
int client(struct socket_data socket_1);
int server(struct socket_data socket_1);
int check_command(char *buff, struct commands *x);
#endif // MAIN_H
