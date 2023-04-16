#include<iostream>
using namespace std;
int f(long double x,long double y);

int main()
{
  double x,y;
  cin>>x>>y;
  cout<<f(x,y)<<endl;
  system("pause");
  return 0;
} 

int f(long double x,long double y)
{
	int i=0;
	double a=0.615,b=0.141;
	do
	{
		double t=x;
		x=x*x-y*y+a;
		y=2*t*y+b;
		cout<<x<<"+"<<y<<"i"<<endl; 
	 } while(i<=100&&x*x+y*y<=1e+16);
	if(x*x+y*y>1e+16) return 0;
	return 1;
	 
	
}
