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
  int order = 2; //order of the specific 
  //float coa[4];
  /*coa[0] = -4;
  coa[1] = 0;
  coa[2] = 1; //i.e x^2 -4*/
  //coa = {-4,0,1};
  printf("The polynomial is: ");
  i=order;
  while (i-->=0){
    printf("%.2fx^%d ",coa[i+1],i+1);
  }
  putchar('\n');
  pt = 0;  //f_x(0)->-4,f_x(1)->-3,f_x(2)->0 should evaluate to 0
  for (pt=0;pt<=2;pt++){
    f_x = poly_eval(coa,order,pt); //poly_co:co-efficient array,pt is a float
    printf("The value of f_x(%.2f) is: %.2f\n",pt,f_x);
  } //end for  
}

float poly_eval(float ca[],int ord, float p)
{
  float fx_val=0;
  int i=0; //loop cntr
  //printf("In poly_eval with ord equal to %d\n",ord);
  while (i++<=ord){
    // printf("Val of fx_val,ca[i-1] & i before call to pow are %.2f %.2f %d\n",fx_val,ca[i-1],i);
    // printf("Pt is: %.2f\n",p);
    fx_val += ca[i-1]*pow(p,i-1);
    // printf("Val of fx_val,ca[i-1] & i after call to pow are %.2f %.2f %d\n",fx_val,ca[i-1],i);
  } //end while
  return fx_val;
}
