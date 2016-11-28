/* pelikan
 * vatoz
 * vaşak
 * kronos
 *
 *
 *
 *
 *
 *
 *
 *
 *
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



int main (int argc, char *argv[]) {
int cnt=0;
//int opt,cnt=0;
//int portnumb = 0;
//char *ip = 0;
//int buff_size=0;
//char socket_status;
while((socket_1.opt=getopt(argc,argv,"sc:p:b:n:"))!=-1){
    //printf("%c",opt[cnt]);

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





//while ((opt = getopt(argc, argv, "i:o:")) != -1) {
//    switch(opt) {
//    case 'i':
//    in_fname = optarg;
//    printf("\nInput option value=%s", in_fname);
//    break;
//    case 'o':
//    out_fname = optarg;
//    printf("\nOutput option value=%s", out_fname);
//    break;
//    case '?':
//    /* Case when user enters the command as
//     * $ ./cmd_exe -i
//     */
//    if (optopt == 'i') {
//    printf("\nMissing mandatory input option");
//    /* Case when user enters the command as
//     * # ./cmd_exe -o
//     */
//  } else if (optopt == 'o') {
//     printf("\nMissing mandatory output option");
//  } else {
//     printf("\nInvalid option received");
//  }
//  break;
// }
// }
