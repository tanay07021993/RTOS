#include<stdio.h>
#include<unistd.h>
#include <syslog.h>
#include<sys/types.h>
#include <signal.h>
#include <sys/stat.h>
#include <error.h>

int g_first,g_second,g_third;
void PrintVariable()
{
static int j,k,l;
printf("\n address of j=%p" , &j );
printf("\naddress of k=%p ", &k);
printf("\naddress of l=%p", &l);
printf("\n address of g_first=%p", &g_first);
printf("\naddress of g_second=%p  ",&g_second);
printf("\naddress of g_third=%p ",&g_third);
}
int main()
{
int a,b,c;
printf("\n address of a=%p",&a);
printf("\naddress of b=%p",&b);
printf("\naddress of c=%p",&c);
printf("\n address of g_first=%p",&g_first);
printf("\n address of g_second=%p",&g_second);
printf("address of g_third=%p ",&g_third);
	   int pid_p1=fork();
	   if(pid_p1!=-1)
	   {
	    if(pid_p1==0)
	     {
               PrintVariable();
	       while(1)
	       {
	         }
	      }
	    else
	    {
	     int pid_p2=fork(); 
	      if(pid_p2!=-1)
	       {
	        if(pid_p2==0)
	         {
	           PrintVariable();
	            while(1)
	              {
	              }
	         }
	        else
	        {
                int pid_p3=fork();
	        if(pid_p3!=-1)
	         {
	         if(pid_p3==0)
	          {
	            PrintVariable();
	            while(1)
	              {
	             }
	          }
	        else
	         {
                   FILE *fp = fopen("file_kill.sh","w+");
                   fprintf(fp,"%s\n","#/bin/bash");
                   fprintf(fp,"kill -9 %d\n",pid_p1);
                   fprintf(fp,"kill -9 %d\n",pid_p2);
		   fprintf(fp,"kill -9 %d\n",pid_p3);
	            fprintf(fp,"kill -9 %d\n",getpid());
                    fputs("rm kill.sh",fp);
                    system("chmod +x kill.sh");
                    fclose(fp);
	         while(1)
	         {
	         }
	       }
	      }
	     }
	    }
	   }
	  }
	return 0;
	}






















