#include <unistd.h>
#include<arpa/inet.h>
#include<sys/socket.h>
#include<stdlib.h>
#include<math.h>
#include <stdio.h>
#include<string.h>
#include <sys/types.h>
#include <netinet/in.h>
#include<error.h>
 void  main(argc, argv)

int argc;
char **argv;
{
int server_address_size;
int soc,n;
int i;
unsigned short port;
pid_t id_p;
struct sockaddr_in server;
char send[200],recv[200];
   /* argv[1] is internet address of server argv[2] is port of server.
    * Convert the port from ascii to integer and then from host byte
    * order to network byte order.
    */
   if(argc != 3)
   {
      printf("Usage: %s <host address> <port> \n",argv[0]);
      exit(1);
   }
   port = htons(atoi(argv[2]));
   if ((fd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
   {
       perror("socket");
       exit(2);
   }

   /* Set up the server name */
   server.sin_family      = AF_INET;            /* Internet Domain    */
   server.sin_port        = port;               /* Server Port        */
   server.sin_addr.s_addr = inet_addr(argv[1]); /* Server's Address   */
 if(connect(soc, (struct sockaddr *)&server, sizeof(server)) < 0)
    {
        printf(" non `Connect()");
        exit(3);
    }
 if((id_p=fork())==-1)
 {
perror("fork");
exit(4);
 } 
 if(id_p==0)
 { 
 while(1) 
 {   
 printf("enter string\n");
 scanf("%s",send);
if(send(soc,sendbuf,sizeof(sendbuf),0)<0)
{
perror("send");
exit(5);
} 
 }
 }
 else
 {
     while(1)
 {    
 if(recv(soc,recvbuf,sizeof(recv),0)<0)
{
     exit(6);
}  
printf("%s",recv);
 }
 }
}
