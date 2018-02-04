#include<stdio.h>
#include<stdlib.h>
#include<wiringPi.h>
#include<string.h>
int i=0;
void myInterrupt(void)
{
int w,x,y,z;
w=digitalRead(2);
x=digitalRead(3);
y=digitalRead(4);
z=digitalRead(5);
i=(w*1)+(x*2)+(y*4)+(z*8);
printf("\n%d",i);
}
int main(void)
{
wiringPiSetup();
waitForInterrupt(0,-1);
wiringPiISR(0,INT_EDGE_RISING,&myInterrupt);
while(1)
{
}
return 0;
}
