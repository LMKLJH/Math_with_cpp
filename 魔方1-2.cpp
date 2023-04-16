#include <iostream>
#include <stdio.h>
#include <processthreadsapi.h>
#include <string>
#include <string.h> // �������ͷ�ļ���ʹ�� strcmp ����
using namespace std;
double cpu_time();
// �������ħ������Magic Square: MS,������ħ��ʵ���һһ��Ӧ 
//d����  u����  b���� l���� r���� fǰ�� 
char const MS0[4][6] = {'d','d','u','u','b','b',
                        'd','d','u','u','b','b',
                        'l','l','f','f','r','r',
				        'l','l','f','f','r','r'};//��׼״̬ 
char MS[4][6];//�������ħ��״̬ 
// ����ģ��šħ���ĺ���Twist Magic Square��TMS 
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
  	if(n=0)
  	return "U";
  	else if(n=1)
  	return "U2";
  	else if(n=2)
  	return "U'";
  	else if(n=3)
  	return "F";
  	else if(n=4)
  	return "F2";
  	else if(n=5)
  	return "F'";
  	else if(n=6)
  	return "R";
  	else if(n=7)
  	return "R2";
  	else if(n=8)
  	return "R'";

  }


// ������
int main()
{
	cout<<"������������ħ��״̬���ֱ���Сд��ĸd,u,b,l,f,r��ʾ�ף��ϣ�����ǰ������"; 
	for(int i=0; i<4; ++i)
    {
        for(int j=0; j<6; ++j)
        {
            cin>>MS[i][j];
        }
        cout << endl;
    }
     
	double begin = cpu_time();   //��ʼ��ʱ 
	cout << "��ǰħ��״̬��" << endl;

    // �����ǰħ��״̬
    for(int i=0; i<4; ++i)
    {
        for(int j=0; j<6; ++j)
        {
            cout <<MS[i][j] << " ";
        }
        cout << endl;
    }
  
  
   char MS1[4][6];
    memcpy(MS1, MS, sizeof(char) * 4 * 6);
 
  
	








int p1,p2,p3,p4,p5,p6,p7,p8,p9,p10,p11,k,h;	
h=0;
  for(p1=0;p1<9;p1++)
  {  
  k=(p1/3+1)%9;
  	for(p2=p1+3*k;p2<=p1+6+3*k;p2++)
  	{ 	
  	k=(p2/3+1)%9;
  		for(p3=p2+3*k;p3<=p2+6+3*k;p3++)
  		{  	
		  k=(p3/3+1)%9;		
  			for(p4=p3+3*k;p4<=p3+6+3*k;p4++)
  			{  	
			  k=(p4/3+1)%9;			
			  	for(p5=p4+3*k;p5<=p4+6+3*k;p5++)
			  	{	
				  k=(p5/3+1)%9;		  	
			  	   	for(p6=p5+3*k;p6<=p5+6+3*k;p6++)
			  	   	{	
						 (k=p6/3+1)%9;	  	  							 			  	   	    
						for(p7=p6+3*k;p7<=p6+6+3*k;p7++)
			  	   	    {	
							 k=(p7/3+1)%9;		  	   	    
			  	   	    	for(p8=p7+3*k;p8<=p7+6+3*k;p8++)
			  	   	    	{	
								k=(p8/3+1)%9;		  	   	    	
			  	   	    		for(p9=p8+3*k;p9<=p8+6+3*k;p9++)
			  	   	    		{	
									 k=(p9/3+1)%9;		  	   	    		
			  	   	    			for(p10=p9+3*k;p10<=p9+6+3*k;p10++)
			  	   	    			{	
										 k=(p10/3+1)%9;		  	   	    			
			  	   	    				for(p11=p10+3*k;p11<=p10+6+3*k;p11++)
			  	   	    				{
                                                                                                                                                                                               memcpy(MS, MS1, sizeof(char) * 4 * 6);
										   TMS(p1%9);
			  	   	    					if (memcmp(MS0, MS, sizeof(char) * 4 * 6) == 0) break;
			  	   	    					TMS(p2%9);
			  	   	    					if (memcmp(MS0, MS, sizeof(char) * 4 * 6) == 0) break;
			  	   	    					TMS(p3%9);
			  	   	    					if (memcmp(MS0, MS, sizeof(char) * 4 * 6) == 0) break;
			  	   	    					TMS(p4%9);
			  	   	    					if (memcmp(MS0, MS, sizeof(char) * 4 * 6) == 0) break;
			  	   	    					TMS(p5%9);
			  	   	    					if (memcmp(MS0, MS, sizeof(char) * 4 * 6) == 0) break;
			  	   	    					TMS(p6%9);
			  	   	    					if (memcmp(MS0, MS, sizeof(char) * 4 * 6) == 0) break;
			  	   	    					TMS(p7%9);
			  	   	    					if (memcmp(MS0, MS, sizeof(char) * 4 * 6) == 0) break;
			  	   	    					TMS(p8%9);
			  	   	    					if (memcmp(MS0, MS, sizeof(char) * 4 * 6) == 0) break;
			  	   	    					TMS(p9%9);
			  	   	    					if (memcmp(MS0, MS, sizeof(char) * 4 * 6) == 0) break;
			  	   	    					TMS(p10%9);
			  	   	    					if (memcmp(MS0, MS, sizeof(char) * 4 * 6) == 0) break;
			  	   	    					TMS(p11%9);
			  	   	    					h=h+1;
			  	   	    					cout<<p11<<"   "<<h<<endl;
			  	   	    				
										}
									if (memcmp(MS0, MS, sizeof(char) * 4 * 6) == 0) break;	
									}
								if (memcmp(MS0, MS, sizeof(char) * 4 * 6) == 0) break;
								}
							if (memcmp(MS0, MS, sizeof(char) * 4 * 6) == 0) break;
							 }
							if (memcmp(MS0, MS, sizeof(char) * 4 * 6) == 0) break;
						}
						if (memcmp(MS0, MS, sizeof(char) * 4 * 6) == 0) break;
					}
					if (memcmp(MS0, MS, sizeof(char) * 4 * 6) == 0) break;
				}
				if (memcmp(MS0, MS, sizeof(char) * 4 * 6) == 0) break;
			}
			if (memcmp(MS0, MS, sizeof(char) * 4 * 6) == 0) break;
		}
		if (memcmp(MS0, MS, sizeof(char) * 4 * 6) == 0) break;
	}
	cout<<(p1+1)*100/9<<"%"<<endl;
	if (memcmp(MS0, MS, sizeof(char) * 4 * 6) == 0) break;
  }	
  cout<<r(p1%9)<<r(p2%9)<<r(p3%9)<<r(p4%9)<<r(p5%9)<<r(p6%9)<<r(p7%9)<<r(p8%9)<<r(p9%9)<<r(p10%9)<<r(p11%9)<<endl;//����ת��Ϊħ����ʽ��� 

	
	double end = cpu_time();
    double elapsed = end - begin;
    printf("����ʱ��: %.3f ��.\n", elapsed); 
    return 0;
}


