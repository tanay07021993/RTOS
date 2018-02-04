
#include<stdio.h>
#include<stdlib.h>
    
static  int  y_n,y_n1,y_n2;     
              
static  int  data_input,g=0,h=0;  //temporary variables
static  int  x_n,x_n1,x_n2;                  
               
#define p   0.00544                   // constants for filter
#define q   0.0108                  
#define s   0.00544                  
#define r   1.779                    
#define t   0.803                 
int main()
{
	FILE *f_in,*f_out ;              
	f_in=fopen("abc.txt","r");      
	f_out=fopen("xyz.txt","w+");   
	while(g<5000)                  //  reading values from input file 
	{                                     
		fscanf(f_in,"%d",&data_input);         
		
		x_n2=x_n1;                                                                     
		x_n1=x_n;                                                                      
		x_n=data_input;                                                                        
		y_n2=y_n1;                                                                    
		y_n1=y_n;                                                                    
		y_n=((p*x_n)+(q*x_n1)+(s*x_n2)+(r*y_n1)-(t*y_n2));    /* sampling frequency=120hz cut off frequency=3hz */                           
		fprintf(f_out,"%d\n",y_n); 
                g++;                                                   // printing filtered output in output file 
	}                                       
                                 
        fclose(f_in);
        fclose(f_out);
                                                         
    FILE *pipe = popen("gnuplot -persist","w");
    fprintf(pipe, "set xrange [600.000:1000.000]\n");    
    fprintf(pipe, "set yrange [400.000:600.000]\n");    
    fprintf(pipe, "set terminal png\n");                
    fprintf(pipe, "set output 'lmno.png'\n");         
    fprintf(pipe," plot 'xyz.txt' with l  " );      
    fclose(pipe);

}
