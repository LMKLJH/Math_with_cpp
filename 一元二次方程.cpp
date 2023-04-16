#include<iostream> 
#include<cmath>
#include<stdio.h>
using namespace std;
int main()
{long double a,b,c,d;
 cout<<"依次输入a,b,c"<<endl; 
 cin>>a>>b>>c;
 if (fabs(a)<=1e-8)
 {cout<<"这不是二次方程"<<endl;}
 else{d=b*b-4*a*c;
     if (d>=0)
      {d=sqrt(d);
     cout<<"x["<<1<<"]="<<(b-d)/(2*a)<<endl;
     cout<<"x["<<2<<"]="<<(b+d)/(2*a)<<endl;
      }
     else
     d=sqrt(-d);
     cout<<"x["<<1<<"]="<<b/(2*a)<<"+"<<d/(2*a)<<"i"<<endl;
      cout<<"x["<<2<<"]="<<b/(2*a)<<"-"<<d/(2*a)<<"i"<<endl;
   }
   system("pause");
}
