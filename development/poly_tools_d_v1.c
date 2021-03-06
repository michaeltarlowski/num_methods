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

double poly_eval(float [],int,float);
double find_root(double, double);
double *get_interval_init(double, double);

float coa[DEGREE_MAX] = {-4,0,1};  //represents the fn x^2 -4
float pt,guess_init_min,guess_init_max;
int i; //generic loop counter

void main()
{
  float fx;
  int order = 2; 
  printf("The polynomial is: ");
  i=order;
  while (i-->=0){
    printf("%.2fx^%d ",coa[i+1],i+1);
  }
  putchar('\n');
  pt = 0;  
  for (pt=0;pt<=2;pt++){
    fx = poly_eval(coa,order,pt);
    printf("The value of f_x(%.2f) is: %.2f\n",pt,fx);
  } //end for
  // poly_eval(coa,order,pt);
  //while(abs(fx_r)>epsilon){ //note that f(x_r) equals 0 at root
  get_interval_init(0,0);
return;  
}

double poly_eval(float ca[],int ord, float p)
{
  float fx_val=0;
  int i=0; //loop cntr
  while (i++<=ord){
    fx_val += ca[i-1]*pow(p,i-1);
    } //end while
  return fx_val;
}

double *get_interval_init(double xl_0, double dx)
{
  double inta_0[2] = {xl_0,0};
  double fx_0=0;
  double *dum;
  dum = &fx_0;
  printf("*get_interval_init called....\n");
  printf("The value of poly_eval(0) is %.2f\n",poly_eval(coa,2,xl_0));
  return dum;
}
// double find_root(double eps,double f_xn, double g_0_min, double g_0_max)
  /*this function will have initial guess hardcoded
    final version will automoate determination of guess_min & guess_max init 
{
 
} */
