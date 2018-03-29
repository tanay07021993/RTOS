#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>
#include <ctype.h>
#include <fcntl.h>
 
#define SERVER 1L
 struct my_msgbuf {
    long    message_type;
    int    message_txt[200];
} buf;
int main()
{
key_t key;
int msgqid;
printf(" Press 1 to perform addition ,Press 2 to perform subtraction,Press 3 to perform multiplication,Press 4 to perform division\n");  
scanf("%d\n",&buf.message_txt[0]); 
printf("enter two numbers \n");                                     //numbers for operation
scanf("%d\n%d\n",&buf.message_txt[1],&buf.message_txt[2]);  
 
if((key=ftok("/home/venkatesh/RTOS/RTOSIIITB/pipe.c",'1'))==-1)                
{
    perror("ftok");
    exit(1);
}
buf.message_type=1;                                               
msgqid = msgget(key, 0666 | IPC_CREAT );                      
 if(msgsnd(msgqid, &buf, sizeof(buf.message_txt)+1, IPC_NOWAIT)==-1)   
 {
        perror("msgsnd");                                                         
        exit(-1);                                          
 }                                                           
 if(msgrcv(msgqid, &buf, sizeof(buf.message_txt)+1, SERVER, 0)<0) 
 {
        perror("msgrcv");
        exit(-1);
 }
 if(buf.message_txt[1]==0)
{
  printf("result = \n");
    printf("%d\n", buf.message_txt[0]);
}
else if(buf.message_txt[1]==1)
printf("invalid input");
}
