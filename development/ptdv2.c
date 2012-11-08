/*
Ensure that the compiler flag -lm is used AFTER the source file, else the ANSI math
will not link (-l => linker -m => math) 
gcc -o  fr.o find_root.c -lm
Alternative usage gcc find_root.c -lm -o fr2.o (noting order)
gcc 
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define DEGREE_MAX 5

//double poly_eval(float [],int,float);
float poly_eval(float);
float find_root(float, float);
float *get_interval_init(float,float); //doubles as exhaustive enumeration method

float coa[DEGREE_MAX] = {-2,0,1};  //represents the fn x^2 -4
int order = 2; //both float and order are external so that the fn call can be f(x)

float pt,guess_init_min,guess_init_max;
int i; //generic loop counter

void main()
{
  float fx,dx;
  int order = 2; 
  dx=0.001;
  printf("The polynomial is: ");
  i=order;
  while (i-->=0){
    printf("%.2fx^%d ",coa[i+1],i+1);
  }
  putchar('\n');
  pt = 0;  
  for (pt=0;pt<=2;pt++){
    //    fx = poly_eval(coa,order,pt);
    fx = poly_eval(pt);
    printf("The value of f_x(%.2f) is: %.2f\n",pt,fx);
  } //end for
  // poly_eval(coa,order,pt);
  //while(abs(fx_r)>epsilon){ //note that f(x_r) equals 0 at root
  get_interval_init(0,dx);
return;  
}

//float poly_eval(float ca[],int ord, float p)
float poly_eval(float p)
{
  float fx_val=0;
  int i=0; //loop cntr
  while (i++<=order){
    fx_val += coa[i-1]*pow(p,i-1);
    } //end while
  return fx_val;
}

float *get_interval_init(float xl_0, float dx)
{
  float inta[2];
  float fx,fx_0;
  float *dum;
  int i=0; //variables to test values of xl and xh
  float x;

  printf("*get_interval_init called....\n");
  fx_0 = poly_eval(xl_0);
  dum = &fx_0;
  printf("The value of poly_eval(xl_0) and dx are %3.3f and %3.3f\n",fx_0,dx);
  x=xl_0;
  printf("iter\t |x\t   |poly_eval(x)\n");
  
  if (fx_0<0){ // Mon increasing casethis will be shifted to the while condition
    while(poly_eval(x)<=0){
      x+=dx;
      printf("%7d  | %6.3f  | %6.3f\n",i,x,poly_eval(x));
      i++;
    } //end while
  }
  inta[0] = xl_0;
  inta[1] = x;
  dum = inta;
  return dum;
}
// float find_root(float eps,float f_xn, float g_0_min, float g_0_max)
  /*this function will have initial guess hardcoded
    final version will automoate determination of guess_min & guess_max init 
{
 
} */
