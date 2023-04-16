#include <stdio.h>
#include <math.h>
int main() 
{long double s=0,a=1123,p=1;
 int i=0;
 while(i<5)
 {s=s+p*a;
 a=a+21460;
 i=i+1;
 p=p*(4*i-3)*(4*i-2)*(4*i-1)*(4*i)/(-i*i*i*i*199148544.0);
 double pi=3528.0/s;
 printf("½á¹ûÎª£º%.20lf\n", pi);
 }
}
