#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <semaphore.h>
int a,b,c;
sem_t l1,l2,l3;
void * thread1proc()
{
int i,j,k;
printf("\n A's address in t1=%p",(void*)&a);
printf("\n B's address in t1=%p",(void*)&b);
printf("\n C's address in t1=%p",(void*)&c);
printf("\n I's address in t1=%p",(void*)&i);
printf("\n J's address in t1=%p",(void*)&j);
printf("\n K's address in t1=%p",(void*)&k);

while(1)
{
sem_wait(&l3);
printf("\nA in t1=%d",a);
printf("\nB in t1=%d",b);
printf("\nC in t1=%d",c);
printf("\nI in t1=%d",i);
printf("\nJ in t1=%d",j);
printf("\nK in t1=%d",k);
printf("\nPLEASE ENTER GLOBAL VALUES FOR T1\n");
scanf("%d %d %d",&a,&b,&c);
printf("\nPLEASE ENTER LOCAL VALUES FOR T1\n");
scanf("%d %d %d",&i,&j,&k);
sem_post(&l1);
}

}
void * thread2proc()
{
int i,j,k;
printf("\n  I's address  in t2=%p",(void*)&i);
printf("\n  J's address  in t2=%p",(void*)&j);
printf("\n  K's address  in t2=%p",(void*)&k);
printf("\n  A's address  in t2=%p",(void*)&a);
printf("\n  B's address  in t2=%p",(void*)&b);
printf("\n  C's address in t2=%p",(void*)&c);
while(1)
{
sem_wait(&l1);
printf("\nA in t2=%d",a);
printf("\nB in t2=%d",b);
printf("\nC in t2=%d",c);
printf("\nI in t2=%d",i);
printf("\nJ in t2=%d",j);
printf("\nK in t2=%d",k);
printf("\nPLEASE ENTER GLOBAL VALUES FOR T2\n");
scanf("\n%d %d %d",&a,&b,&c);
printf("\nPLEASE ENTER LOCAL VALUES FOR T2\n");
scanf("%d %d %d",&i,&j,&k);
sem_post(&l2);
}
}
void * thread3proc()
{
int i,j,k;
printf("\n  I's address in t3=%p",(void*)&i);
printf("\n  J's address in t3=%p",(void*)&j);
printf(" \n K's address in t3=%p",(void*)&k);
printf("\n  A's address in t3=%p",(void*)&a);
printf("\n  B's address in t3=%p",(void*)&b);
printf("\n  C's address  in t3=%p",(void*)&c);
sem_post(&l3);
while(1)
{
sem_wait(&l2);
printf("\nA in t3=%d",a);
printf("\nB in t3=%d",b);
printf("\nC in t3=%d",c);
printf("\nI in t3=%d",i);
printf("\nJ in t3=%d",j);
printf("\nK in t3=%d",k);
printf("\nPLEASE ENTER GLOBAL VALUES FOR T3\n");
scanf("\n%d %d %d",&a,&b,&c);
printf("\nPLEASE ENTER LOCAL VALUES FOR T3\n");
scanf("\n%d %d %d",&i,&j,&k);
sem_post(&l3);
}
}
int main()
{int i,j,k;
printf("\nA's value in main=%d",a);
printf("\nB's value in main=%d",b);
printf("\nC's value in main=%d",c);
printf("\n  I's address in main=%p",(void*)&i);
printf("\n  J's address in main=%p",(void*)&j);
printf(" \n K's address in main=%p",(void*)&k);
pthread_t w1,w2,w3;
pthread_create(&w1,NULL,thread1proc,NULL);
pthread_create(&w2,NULL,thread2proc,NULL);
pthread_create(&w3,NULL,thread3proc,NULL);
pthread_join(w1,NULL);
pthread_join(w2,NULL);
pthread_join(w3,NULL);
}
