#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<wiringPi.h>

int g=0;/*counter*/
void interrupt(int j, int k ,int l,int m)
{
g=(8*m)+(4*l)+(2*k)+(1*j);
printf("\n%d",g);
}
int main(void)
{
wiringPiSetup();
pinMode(0,INPUT);
pinMode(2,INPUT);
pinMode(3,INPUT);
pinMode(4,INPUT);
int j=k=l=m=0;
while(1)
{
if(((j^digitalRead(0))|(k^digitalRead(2))|(l^digitalRead(3))|(m^digitalRead(4)))==1)
{
	j=digitalRead(0);
	k=digitalRead(2);
	l=digitalRead(3);
	m=digitalRead(4);
	interrupt(j,k,l,m);
}
delay(300);
}
return 0;
}
