#include<fstream>
#include<iostream> 
#include<cmath>
#include <stdio.h>
#include <processthreadsapi.h>
using namespace std;
double cpu_time();//函数的原型 
int main()
{ 
  ofstream write;
  write.open("十亿以内质数.txt");
  
  int m,i,k,n=0;
  double begin = cpu_time();   
  for(m=2;m<=1000000000;m++)
    {  
      k=int(sqrt(double(m))); 
	  i=2;
	  while(m%i&&i<=k)
	  i++;
	  if(i>k)
       {  
        write<<m<<'\t'<<'\t';
        n+=1;
        if(n%7==0) write<<endl;
       }
    }
    
  write.close();
  cout<<"所有质数已打印到文件，质数总个数："<<n<<endl;
    double end = cpu_time();
    double elapsed = end - begin;
    printf("消耗时间: %.3f 秒.\n", elapsed);
	system("pause");
  return(0); 
}

double cpu_time()
{
    FILETIME a,b,c,d;
    if (GetProcessTimes(GetCurrentProcess(),&a,&b,&c,&d) != 0)
	{
        return
            (double)(d.dwLowDateTime |
            ((unsigned long long)d.dwHighDateTime << 32)) * 0.0000001;
    }
	else
	{
        return 0;
    }
}



