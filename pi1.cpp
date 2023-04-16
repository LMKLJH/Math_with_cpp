#include <stdlib.h> 
#include <stdio.h> 
 
#define BITS 2000
int a=10000,b,c=BITS*7/2,d,e,f[BITS*7/2+1],g; 
 
int main() 
{   
	for(;b-c;) 
		f[b++]=a/5; 
	for(;d=0,g=c*2;c-=14,printf("%.4d",e+d/a),e=d%a) 
		for(b=c;d=d+f[b]*a,f[b]=d%--g,d/=g--,--b;d=d*b);     
	//getchar();
	return 0;
} 
