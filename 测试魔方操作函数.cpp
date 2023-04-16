#include <iostream>
#include <stdio.h>
#include <processthreadsapi.h>
#include <string>
using namespace std;
char MS[4][6];//待输入的魔方状态 
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




// 主函数
int main()
{

	cout<<"请输入摆正后的魔方状态，分别用小写字母d,u,b,l,f,r表示底，上，后，左，前，右面"; 
	for(int i=0; i<4; ++i)
    {
        for(int j=0; j<6; ++j)
        {
            cin>>MS[i][j];
        }
        cout << endl;
    }
	cout << "当前魔方状态：" << endl;

    // 输出当前魔方状态
    for(int i=0; i<4; ++i)
    {
        for(int j=0; j<6; ++j)
        {
            cout <<MS[i][j] << " ";
        }
        cout << endl;
    }
    
    char MS1[4][6];// 复制一份 MS 数组内容到 MS1 数组中
    memcpy(MS1, MS, sizeof(char) * 4 * 6);
    
       
     
    TMS(0); // 拧U-面90
    cout << "拧U-面90后魔方状态：" << endl;

    // 输出拧U-面后的魔方状态
    for(int i=0; i<4; ++i)
    {
        for(int j=0; j<6; ++j)
        {
            cout << MS[i][j] << " ";
        }
        cout << endl;
    }

    
	memcpy(MS, MS1, sizeof(char) * 4 * 6); 


    TMS(1); // 拧U-面
    cout << "拧U-面180后魔方状态：" << endl;

    // 输出拧U-面后的魔方状态
    for(int i=0; i<4; ++i)
    {
        for(int j=0; j<6; ++j)
        {
            cout << MS[i][j] << " ";
        }
        cout << endl;
    }

    memcpy(MS, MS1, sizeof(char) * 4 * 6); 

    TMS(2); // 拧U-面
    cout << "拧U-面270后魔方状态：" << endl;

    // 输出拧U-面后的魔方状态
    for(int i=0; i<4; ++i)
    {
        for(int j=0; j<6; ++j)
        {
            cout << MS[i][j] << " ";
        }
        cout << endl;
    }

    memcpy(MS, MS1, sizeof(char) * 4 * 6); 

    TMS(3); // 拧F-面
    cout << "拧F-面后魔方状态：" << endl;

    // 输出拧F-面后的魔方状态
    for(int i=0; i<4; ++i)
    {
        for(int j=0; j<6; ++j)
        {
            cout << MS[i][j] << " ";
        }
        cout << endl;
    }
      
    memcpy(MS, MS1, sizeof(char) * 4 * 6);  
      
     TMS(4); // 拧F-面
    cout << "拧F-面后魔方状态：" << endl;

    // 输出拧F-面后的魔方状态
    for(int i=0; i<4; ++i)
    {
        for(int j=0; j<6; ++j)
        {
            cout << MS[i][j] << " ";
        }
        cout << endl;
    }
    
    memcpy(MS, MS1, sizeof(char) * 4 * 6); 
    
    
     TMS(5); // 拧F-面
    cout << "拧F-面后魔方状态：" << endl;

    // 输出拧F-面后的魔方状态
    for(int i=0; i<4; ++i)
    {
        for(int j=0; j<6; ++j)
        {
            cout << MS[i][j] << " ";
        }
        cout << endl;
    }
    
    
    memcpy(MS, MS1, sizeof(char) * 4 * 6); 
    
     // 拧R-面
    TMS(6);
    cout << "拧R-面后魔方状态：" << endl;

    // 输出拧R-面后的魔方状态
    for(int i=0; i<4; ++i)
    {
        for(int j=0; j<6; ++j)
        {
            cout << MS[i][j] << " ";
        }
        cout << endl;
    }
    
    
    memcpy(MS, MS1, sizeof(char) * 4 * 6); 
    
    TMS(7);
    cout << "拧R-面后魔方状态：" << endl;

    // 输出拧R-面后的魔方状态
    for(int i=0; i<4; ++i)
    {
        for(int j=0; j<6; ++j)
        {
            cout << MS[i][j] << " ";
        }
        cout << endl;
    }
     
     
     memcpy(MS, MS1, sizeof(char) * 4 * 6); 
     
   TMS(8);
    cout << "拧R-面后魔方状态：" << endl;

    // 输出拧R-面后的魔方状态
    for(int i=0; i<4; ++i)
    {
        for(int j=0; j<6; ++j)
        {
            cout << MS[i][j] << " ";
        }
        cout << endl;
    }



    return 0;
}
