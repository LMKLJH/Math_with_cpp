#include<iostream> 
#include<cmath>
using namespace std;
int main()
{long double x,r;
 int i;
 cout<<"���������ʼֵ��ϵ��r"<<endl; 
 cin>>x>>r;
 i=0;
 while(i<50) 
 {x=r*x*(1-x);
 i=i+1;
 cout<<"x["<<i<<"]="<<x<<endl;
 }
}
