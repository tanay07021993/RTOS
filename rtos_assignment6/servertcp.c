
#include<unistd.h>
#include<arpa/inet.h>
#include<stdlib.h>
#include<math.h>
#include<stdio.h>
#include<string.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<error.h>
int main()
{
int soc, server_size, client_size,newsoc;
struct sockaddr_in client, server;
char  send[200],recv[200];

pid_t id_p;
   if ((soc = socket(AF_INET, SOCK_STREAM, 0)) < 0)
   {
       exit(1);
   }

   /*
    * Bind my name to this socket so that clients on the network can
    * send me messages. (This allows the operating system to demultiplex
    * messages and get them to the correct server)
    *
    * Set up the server name. The internet address is specified as the
    * wildcard INADDR_ANY so that the server can get messages from any
    * of the physical internet connections on this host. (Otherwise we
    * would limit the server to messages from only one network
    * interface.)
    */
   server.sin_family      = AF_INET;  /* Server is in Internet Domain */
   server.sin_port        = 0;         /* Use any available port      */
   server.sin_addr.s_addr = INADDR_ANY;/* Server's Internet Address   */
   
   if (bind(soc, (struct sockaddr *)&server, sizeof(server)) < 0)
   {
      
       exit(2);
   }
   /* Find out what port was really assigned and print it */
   server_size = sizeof(server);
   if (getsockname(soc, (struct sockaddr *) &server, &server_size) < 0)
   {  
       exit(3);
   }
   printf("Port assigned is %d\n", ntohs(server.sin_port));
   /*
    * Receive a message on socket s in buf  of maximum size 32
    * from a client. Because the last two paramters
    * are not null, the name of the client will be placed into the
    * client data structure and the size of the client address will
    * be placed into client_address_size.
    */
   if(listen(soc,0)<0)
   {
   perror("listen");
   exit(4);
   }
   client_size = sizeof(client);
   if((newsoc=accept(soc, (struct sockaddr *) &client,
            &client_size)) <0)
   {
       perror("recvfrom");
      exit(4);
   }
   /*
    * Print the message and the name of the client.
    * The domain should be the internet domain (AF_INET).
    * The port is received in network byte order, so we translate it to
    * host byte order before printing it.
    * The internet address is received as 32 bits in network byte order
    * so we use a utility that converts it to a string printed in
    * dotted decimal format for readability.
    */
   printf("Received message   from domain %s port %d internet\
 address %s\n",
       
       (client.sin_family == AF_INET?"AF_INET":"UNKNOWN"),
       ntohs(client.sin_port),

       inet_ntoa(client.sin_addr));
    printf("message is %s\n",recv);
       if((id_p=fork())==-1)
       {
        perror("fork");
        exit(5);  

       }
     
if(id_p==0)
{
    while(1)
  {
      printf("enter string\n");
      scanf("%s\n",send);  
if(sendto(newsoc,send,sizeof(send),0,(struct sockaddr *) &client,sizeof(client))<0)
{
exit(5);
}
  }
}
else
{
while(1)
{
if(recvfrom(newsoc, recv, sizeof(recv), 0, (struct sockaddr *) &client,
            &client_size) <0)
   {
       
      exit(4);
   }
printf("%s\n",recv);
}
}
return 0;
}







