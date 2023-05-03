#include <iostream>
#include<fstream>
#include <processthreadsapi.h>
#include <string> // �������ͷ�ļ���ʹ�� strcmp ����
using namespace std;
double cpu_time();
// �������ħ������Magic Square: MS,������ħ��ʵ���һһ��Ӧ 
//d����  u����  b���� l���� r���� fǰ�� 
char const MS0[4][6] = {'w','w','y','y','g','g',
                        'w','w','y','y','g','g',
                        'o','o','b','b','r','r',
				        'o','o','b','b','r','r'};//��׼״̬ 
char MS[4][6];//�������ħ��״̬  
/* 
   ��ħ��������ת���Կ����ǲ���ģ���ôL��˳ʱ����ת90���൱�� 
R��˳ʱ����ת90�ȣ�����ͬ������ֻ�迼������������ UFR�棬
ÿ���������ת�Ƕ�����3�����,Ҳ����9������������ÿ����������
����һ���û���U��Ӧ1��2��3��F��Ӧ4��5��6��R��Ӧ7��8��9��
 
   �����ϵ�֮����11�����ҵ�ħ���ܴ��ڲ�����11���Ľⷨ��
ÿ�ֽⷨ���Զ�Ӧһ��������������(p1,p2,p3,p4,p5,p6,p7,p8,p9,p10,p11)
��Ч�Ľⷨ��Ȼ�������㣺ǰ��šͬһ���漴 
����������������Ĵ����� (��Ȼ�������Ҳ����С��11��Ԫ��)

   ����ʵ�ʴ���ħ��ʱ����Ҫ�Ѱ�ħ��������ʹ������URF����Ӱ����Ǹ��ǿ�
��ԭ��Ȼ������ħ����״̬����Ȼ������ħ������šħ�����飬ÿšһ��
�ȶԸ�ԭ�ľ����ж��Ƿ��Ѿ���ԭ��ֱ����ԭ����ѭ�����õ�һ������
Ȼ������������ת����ħ����ʽ����� 
*/ 
// ����ģ��šħ���ĺ���Twist Magic Square��TMS 
void TMS(int direction)
{
    char t1,t2,t;
    if(direction == 0) // U-��˳ʱ����ת90 
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
    else if(direction == 1) // U-��˳ʱ����ת180 
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
    else if(direction == 2) // U-��˳ʱ����ת270 
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
    else if(direction == 3) // F-��˳ʱ����ת90 
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
    else if(direction == 4) // F-��˳ʱ����ת180 
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
    else if(direction == 5) // F-��˳ʱ����ת270 
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
    else if(direction == 6) // R-��˳ʱ����ת90 
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
    else if(direction == 7) // R-��˳ʱ����ת180 
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
    else if(direction == 8) // R-��˳ʱ����ת270 
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


double cpu_time()//��������ʱ��ʹ�õĺ��� 
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


string r(int n)//����ѱ��ת��Ϊħ����ʽ�ĺ��� 
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
    else return "�޽�"; 
}


// ������
int main()
{
	cout<<"�����ħ��״̬��ʹ�ðס��ȡ��̵Ľǿ鸴ԭ"<<endl;
	cout<<"������������ħ��״̬���ֱ�����ɫ������ĸw,r,y,b,g,o(����Сд)��ʾ��24���ַ�"; 
	for(int i=0; i<4; ++i)
    {
        for(int j=0; j<6; ++j)
        {
            cin>>MS[i][j];
        }
        cout << endl;
    }
     
	double begin = cpu_time();   //��ʼ��ʱ 
	ofstream write;
     write.open("�ϵ۽ⷨ����.txt");
	double end, elapsed;
	cout << "��ǰħ��״̬��" << endl;

    // �����ǰħ��״̬
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
												cout<<"��"<<h<<"���ⷨ" <<endl;
												write<<"��"<<h<<"���ⷨ" <<endl;
											cout<<r(p1)<<r(p2)<<r(p3)<<r(p4)<<r(p5)<<r(p6)<<r(p7)<<r(p8)<<r(p9)<<r(p10)<<r(p11)<<endl;
											write<<r(p1)<<r(p2)<<r(p3)<<r(p4)<<r(p5)<<r(p6)<<r(p7)<<r(p8)<<r(p9)<<r(p10)<<r(p11)<<endl;//����ת��Ϊħ����ʽ��� 
											} 
								        }
							        }
						        }	
							}
						}
					}
				}
			}
		cout<<"���н���"<<(p1*81+p2*9+p3+1.0)*100/729<<"%";    //��ʾ���н���
		end = cpu_time();//������ʱ 
        elapsed = end - begin;
        printf("����ʱ��: %.3f ��.\n", elapsed);  
		}
	 }
  }	
     write.close();
	end = cpu_time();//������ʱ 
    elapsed = end - begin;
    printf("����ʱ��: %.3f ��.\n", elapsed); 
    return 0;
}

