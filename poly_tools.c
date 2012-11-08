/*
Ensure that the compiler flag -lm is used AFTER the source file, else the ANSI math
will not link (-l => linker -m => math) 
gcc -o  fr.o find_root.c -lm
Alternative usage gcc find_root.c -o -lm fr2.o
gcc 
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define DEGREE_MAX 5

float poly_eval(float [],int,float);
float coa[DEGREE_MAX] = {-4,0,1};
float pt;
int i; //generic loop counter

void main()
{
  float f_x;
  int order = 2; 
  printf("The polynomial is: ");
  i=order;
  while (i-->=0){
    printf("%.2fx^%d ",coa[i+1],i+1);
  }
  putchar('\n');
  pt = 0;  
  for (pt=0;pt<=2;pt++){
    f_x = poly_eval(coa,order,pt);
    printf("The value of f_x(%.2f) is: %.2f\n",pt,f_x);
  } //end for  
}

float poly_eval(float ca[],int ord, float p)
{
  float fx_val=0;
  int i=0; //loop cntr
  while (i++<=ord){
    fx_val += ca[i-1]*pow(p,i-1);
    } //end while
  return fx_val;
}

float find_root()
{

}
