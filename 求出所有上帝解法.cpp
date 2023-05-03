#include <iostream>
#include<fstream>
#include <processthreadsapi.h>
#include <string> // 加入这个头文件以使用 strcmp 函数
using namespace std;
double cpu_time();
// 定义二阶魔方矩阵Magic Square: MS,建立与魔方实体的一一对应 
//d底面  u上面  b后面 l左面 r右面 f前面 
char const MS0[4][6] = {'w','w','y','y','g','g',
                        'w','w','y','y','g','g',
                        'o','o','b','b','r','r',
				        'o','o','b','b','r','r'};//标准状态 
char MS[4][6];//待输入的魔方状态  
/* 
   把魔方整体旋转可以看作是不变的，那么L面顺时针旋转90度相当于 
R面顺时针旋转90度，其他同理，于是只需考虑两两正交的 UFR面，
每个面根据旋转角度又有3种情况,也就是9个操作函数，每个操作函数
都是一种置换。U对应1，2，3；F对应4，5，6；R对应7，8，9；
 
   根据上帝之数是11，打乱的魔方总存在不超过11步的解法。
每种解法可以对应一个操作函数序列(p1,p2,p3,p4,p5,p6,p7,p8,p9,p10,p11)
有效的解法显然必须满足：前后不拧同一个面即 
这样将大大减少历遍的次数。 (当然这个序列也可能小于11个元素)

   到了实际打乱魔方时，就要把把魔方摆正，使得其中URF不能影响的那个角块
复原，然后输入魔方的状态矩阵，然后对这个魔方进行拧魔方历遍，每拧一次
比对复原的矩阵，判断是否已经复原，直到复原跳出循环，得到一串数列
然后根据这个数列转换成魔方公式输出。 
*/ 
// 定义模拟拧魔方的函数Twist Magic Square：TMS 
void TMS(int direction)
{
    char t1,t2,t;
    if(direction == 0) // U-面顺时针旋转90 
    {
        t  = MS[0][2];
        MS[0][2] = MS[1][2];
		MS[1][2] = MS[1][3];
		MS[1][3] = MS[0][3];
		MS[0][3] = t;
		
		t1 = MS[2][0];
        t2 = MS[2][1];
        MS[2][0] = MS[2][2];
        MS[2][1] = MS[2][3];
        MS[2][2] = MS[2][4];
        MS[2][3] = MS[2][5];
		MS[2][4] = MS[0][4];
		MS[2][5] = MS[0][5];
		MS[0][4] = t1;
		MS[0][5] = t2;
		        
    }
    else if(direction == 1) // U-面顺时针旋转180 
    {	
		t  = MS[1][2];
        MS[1][2] = MS[0][3];
		MS[0][3] = t;
		t  = MS[0][2];
        MS[0][2] = MS[1][3];
		MS[1][3] = t;
			
		t1 = MS[2][2];
        t2 = MS[2][3];
        MS[2][2] = MS[0][4];
        MS[2][3] = MS[0][5];
		MS[0][4] = t1;
		MS[0][5] = t2;
		t1 = MS[2][0];
        t2 = MS[2][1];
        MS[2][0] = MS[2][4];
        MS[2][1] = MS[2][5];
		MS[2][4] = t1;
		MS[2][5] = t2;
		
		  	  
    }
    else if(direction == 2) // U-面顺时针旋转270 
    {
		t  = MS[0][3];
        MS[0][3] = MS[1][3];
		MS[1][3] = MS[1][2];
		MS[1][2] = MS[0][2];
		MS[0][2] = t;	
		
		t1 = MS[0][4];
        t2 = MS[0][5];
        MS[0][4] = MS[2][4];
        MS[0][5] = MS[2][5];
        MS[2][4] = MS[2][2];
        MS[2][5] = MS[2][3];
		MS[2][2] = MS[2][0];
		MS[2][3] = MS[2][1];
		MS[2][0] = t1;
		MS[2][1] = t2;
				
    }
    else if(direction == 3) // F-面顺时针旋转90 
    {
        t  = MS[2][2];
        MS[2][2] = MS[3][2];
		MS[3][2] = MS[3][3];
		MS[3][3] = MS[2][3];
		MS[2][3] = t;
		
		t1 = MS[1][2];
        t2 = MS[1][3];
        MS[1][2] = MS[3][1];
        MS[1][3] = MS[2][1];
        MS[2][1] = MS[0][0];
        MS[3][1] = MS[0][1];
		MS[0][0] = MS[3][4];
		MS[0][1] = MS[2][4];
		MS[2][4] = t1;
		MS[3][4] = t2;
		  
    }
    else if(direction == 4) // F-面顺时针旋转180 
    {
        t  = MS[2][2];
        MS[2][2] = MS[3][3];
		MS[3][3] = t;
		t  = MS[3][2];
        MS[3][2] = MS[2][3];
		MS[2][3] = t;
			
		t1 = MS[1][2];
        t2 = MS[1][3];
        MS[1][2] = MS[0][1];
        MS[1][3] = MS[0][0];
		MS[0][1] = t1;
		MS[0][0] = t2;
		t1 = MS[2][1];
        t2 = MS[3][1];
        MS[2][1] = MS[3][4];
        MS[3][1] = MS[2][4];
		MS[3][4] = t1;
		MS[2][4] = t2;
		  
    }
    else if(direction == 5) // F-面顺时针旋转270 
    {	
		t  = MS[2][3];
        MS[2][3] = MS[3][3];
		MS[3][3] = MS[3][2];
		MS[3][2] = MS[2][2];
		MS[2][2] = t;
		
		t1 = MS[2][4];
        t2 = MS[3][4];
        MS[2][4] = MS[0][1];
        MS[3][4] = MS[0][0];
        MS[0][1] = MS[3][1];
        MS[0][0] = MS[2][1];
		MS[2][1] = MS[1][3];
		MS[3][1] = MS[1][2];
		MS[1][2] = t1;
		MS[1][3] = t2;
		  	  
    }
    else if(direction == 6) // R-面顺时针旋转90 
    {	
		t  = MS[2][4];
        MS[2][4] = MS[3][4];
		MS[3][4] = MS[3][5];
		MS[3][5] = MS[2][5];
		MS[2][5] = t;
		
		t1 = MS[2][3];
        t2 = MS[3][3];
        MS[2][3] = MS[0][1];
        MS[3][3] = MS[1][1];
        MS[0][1] = MS[1][4];
        MS[1][1] = MS[0][4];
		MS[1][4] = MS[0][3];
		MS[0][4] = MS[1][3];
		MS[0][3] = t1;
		MS[1][3] = t2;
		  	  
    }
    else if(direction == 7) // R-面顺时针旋转180 
    {	
	     t  = MS[2][4];
        MS[2][4] = MS[3][5];
		MS[3][5] = t;
		t  = MS[2][5];
        MS[2][5] = MS[3][4];
		MS[3][4] = t;
			
		t1 = MS[2][3];
        t2 = MS[3][3];
        MS[2][3] = MS[1][4];
        MS[3][3] = MS[0][4];
		MS[1][4] = t1;
		MS[0][4] = t2;
		t1 = MS[0][3];
        t2 = MS[1][3];
        MS[0][3] = MS[0][1];
        MS[1][3] = MS[1][1];
		MS[0][1] = t1;
		MS[1][1] = t2;
		  		  	  
    }  
    else if(direction == 8) // R-面顺时针旋转270 
    {	
		t  = MS[2][4];
        MS[2][4] = MS[2][5];
		MS[2][5] = MS[3][5];
		MS[3][5] = MS[3][4];
		MS[3][4] = t;
		
		t1 = MS[2][3];
        t2 = MS[3][3];
        MS[2][3] = MS[0][3];
        MS[3][3] = MS[1][3];
        MS[0][3] = MS[1][4];
        MS[1][3] = MS[0][4];
		MS[1][4] = MS[0][1];
		MS[0][4] = MS[1][1];
		MS[0][1] = t1;
		MS[1][1] = t2;
		  	  
    }
       
}


double cpu_time()//计算运行时间使用的函数 
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


string r(int n)//定义把编号转换为魔方公式的函数 
{
    if(n == 0)
        return "U";
    else if(n == 1)
        return "U2";
    else if(n == 2)
        return "U'";
    else if(n == 3)
        return "F";
    else if(n == 4)
        return "F2";
    else if(n == 5)
        return "F'";
    else if(n == 6)
        return "R";
    else if(n == 7)
        return "R2";
    else if(n == 8)
        return "R'";
    else return "无解"; 
}


// 主函数
int main()
{
	cout<<"请摆正魔方状态，使得白、橙、绿的角块复原"<<endl;
	cout<<"请输入摆正后的魔方状态，分别用颜色的首字母w,r,y,b,g,o(必须小写)表示的24个字符"; 
	for(int i=0; i<4; ++i)
    {
        for(int j=0; j<6; ++j)
        {
            cin>>MS[i][j];
        }
        cout << endl;
    }
     
	double begin = cpu_time();   //开始计时 
	ofstream write;
     write.open("上帝解法集合.txt");
	double end, elapsed;
	cout << "当前魔方状态：" << endl;

    // 输出当前魔方状态
    for(int i=0; i<4; ++i)
    {
        for(int j=0; j<6; ++j)
        {
            cout <<MS[i][j] << " ";
            write <<MS[i][j] << " ";
        }
        cout << endl;
    }
  
  
   char MS1[4][6];
   memcpy(MS1, MS, sizeof(char) * 4 * 6);
    
    
int p1,p2,p3,p4,p5,p6,p7,p8,p9,p10,p11;	
int h=0;
  for(p1=0;p1<9;p1++)
  {
  	for(p2=0;p2<9;p2++)
  	{
  		for(p3=0;p3<9;p3++)
  		{
  			for(p4=0;p4<9;p4++)
  			{
			  	for(p5=0;p5<9;p5++)
			  	{
			  	   	for(p6=0;p6<9;p6++)
			  	   	{ 
			  	   	    for(p7=0;p7<9;p7++)
			  	   	    {
			  	   	    	for(p8=0;p8<9;p8++)
			  	   	    	{        
								for(p9=0;p9<9;p9++)             
								{
									for(p10=0;p10<9;p10++)
									{
										for(p11=0;p11<9;p11++)
										{
										   memcpy(MS, MS1, sizeof(char) * 4 * 6);

										    TMS(p1);
			  	   	    					
			  	   	    					TMS(p2);
			  	   	    					
			  	   	    					TMS(p3);
			  	   	    				
			  	   	    					TMS(p4);
			  	   	    					
			  	   	    					TMS(p5);
			  	   	    				
			  	   	    					TMS(p6);
			  	   	    					
			  	   	    					TMS(p7);
                                                  	  	   	    					
			  	   	    					TMS(p8);
			  	   	    					
			  	   	    					TMS(p9);
			  	   	    					
			  	   	    					TMS(p10);
			  	   	    					
			  	   	    					TMS(p11);
			  	   	    					
			  	   	    				    if (memcmp(MS0, MS, sizeof(char) * 4 * 6) == 0)
											{
												h=h+1;
												cout<<"第"<<h<<"个解法" <<endl;
												write<<"第"<<h<<"个解法" <<endl;
											cout<<r(p1)<<r(p2)<<r(p3)<<r(p4)<<r(p5)<<r(p6)<<r(p7)<<r(p8)<<r(p9)<<r(p10)<<r(p11)<<endl;
											write<<r(p1)<<r(p2)<<r(p3)<<r(p4)<<r(p5)<<r(p6)<<r(p7)<<r(p8)<<r(p9)<<r(p10)<<r(p11)<<endl;//编码转换为魔方公式输出 
											} 
								        }
							        }
						        }	
							}
						}
					}
				}
			}
		cout<<"运行进度"<<(p1*81+p2*9+p3+1.0)*100/729<<"%";    //显示运行进度
		end = cpu_time();//结束计时 
        elapsed = end - begin;
        printf("消耗时间: %.3f 秒.\n", elapsed);  
		}
	 }
  }	
     write.close();
	end = cpu_time();//结束计时 
    elapsed = end - begin;
    printf("消耗时间: %.3f 秒.\n", elapsed); 
    return 0;
}

