#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>
#include <ctype.h>
#include <fcntl.h>
# define SERVER 1L
static int a=0; 
int mathematical_engine(int buf[])
{
int var1,var2;
int operation;
var1=buf[1];                              
var2=buf[2];
operation=buf[0];                            
if(operation==1)
{
return var1+var2;
}
if(operation==2)
{
return var1-var2;
}                     
if(operation==3)
{
return var1*var2;
}                    
if((operation==4)&(var2!=0))
{
return var1/var2;
}
printf("Invalid operation");
a=1;
return  0; 
}
typedef struct  
{
	long message_type;
	int message_txt[200];      
}MESSAGE;
int main()
{
	int msqid;
	MESSAGE  buf;
	key_t key;
	if((key=ftok("/home/tanay/pipe.c",'1'))==-1)
	{
		perror("ftok");                       // creating key for message queue using file                                                          name
		                                      
		exit(1);                                  
	}
	if ((msqid = msgget(key, 0666 | IPC_CREAT )) == -1)
	{                                                  
		perror("msgget");
		exit(1);
	}
	if(msgrcv(msqid, &buf, sizeof(buf.message_txt)+1, SERVER, 0)<0)
	{
		perror("msgrcv");                        
		exit(-1);
	}
	printf("SERVER receives:\n");
        int result_1=mathematical_engine(buf.message_txt);
	printf("%d\n%d", buf.message_txt[1],buf.message_txt[2]);
	 if(a==0)                                       
      {
	printf("\n%d",result_1);                           
	buf.message_type=1;
	buf.message_txt[0]=result_1;
        buf.message_txt[1]=a;
        }
        else 
        buf.message_txt[1]=a;
	if(msgsnd(msqid, &buf, sizeof(buf.message_txt)+1, IPC_NOWAIT)==-1)
	{                                                 
		perror("msgsnd");                       // sending result back to client
		exit(-1);
	}
	return 0;
}

