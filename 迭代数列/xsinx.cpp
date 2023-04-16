#include<iostream> 
#include<cmath>
#include<iomanip>
using namespace std;
int main()
{long double x;
 int i,n;
 cout<<"依次输入初始值与迭代次数"<<endl; 
 cin>>x>>n;
 i=0;
 while(i<=n) 
 {x=sin(x);
 i=i+1;
 }
 long double y=x*sqrt(n);
 cout<<"迭代结果x="<<setw(18)<<setprecision(15)<<x<<endl;
 cout<<"y="<<setw(18)<<setprecision(15)<<y<<endl;
}
