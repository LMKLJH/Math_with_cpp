#include <iostream>
#include <stdio.h>
#include <processthreadsapi.h>
#include <string>
using namespace std;
char MS[4][6];//�������ħ��״̬ 
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
    
    char MS1[4][6];// ����һ�� MS �������ݵ� MS1 ������
    memcpy(MS1, MS, sizeof(char) * 4 * 6);
    
       
     
    TMS(0); // šU-��90
    cout << "šU-��90��ħ��״̬��" << endl;

    // ���šU-����ħ��״̬
    for(int i=0; i<4; ++i)
    {
        for(int j=0; j<6; ++j)
        {
            cout << MS[i][j] << " ";
        }
        cout << endl;
    }

    
	memcpy(MS, MS1, sizeof(char) * 4 * 6); 


    TMS(1); // šU-��
    cout << "šU-��180��ħ��״̬��" << endl;

    // ���šU-����ħ��״̬
    for(int i=0; i<4; ++i)
    {
        for(int j=0; j<6; ++j)
        {
            cout << MS[i][j] << " ";
        }
        cout << endl;
    }

    memcpy(MS, MS1, sizeof(char) * 4 * 6); 

    TMS(2); // šU-��
    cout << "šU-��270��ħ��״̬��" << endl;

    // ���šU-����ħ��״̬
    for(int i=0; i<4; ++i)
    {
        for(int j=0; j<6; ++j)
        {
            cout << MS[i][j] << " ";
        }
        cout << endl;
    }

    memcpy(MS, MS1, sizeof(char) * 4 * 6); 

    TMS(3); // šF-��
    cout << "šF-���ħ��״̬��" << endl;

    // ���šF-����ħ��״̬
    for(int i=0; i<4; ++i)
    {
        for(int j=0; j<6; ++j)
        {
            cout << MS[i][j] << " ";
        }
        cout << endl;
    }
      
    memcpy(MS, MS1, sizeof(char) * 4 * 6);  
      
     TMS(4); // šF-��
    cout << "šF-���ħ��״̬��" << endl;

    // ���šF-����ħ��״̬
    for(int i=0; i<4; ++i)
    {
        for(int j=0; j<6; ++j)
        {
            cout << MS[i][j] << " ";
        }
        cout << endl;
    }
    
    memcpy(MS, MS1, sizeof(char) * 4 * 6); 
    
    
     TMS(5); // šF-��
    cout << "šF-���ħ��״̬��" << endl;

    // ���šF-����ħ��״̬
    for(int i=0; i<4; ++i)
    {
        for(int j=0; j<6; ++j)
        {
            cout << MS[i][j] << " ";
        }
        cout << endl;
    }
    
    
    memcpy(MS, MS1, sizeof(char) * 4 * 6); 
    
     // šR-��
    TMS(6);
    cout << "šR-���ħ��״̬��" << endl;

    // ���šR-����ħ��״̬
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
    cout << "šR-���ħ��״̬��" << endl;

    // ���šR-����ħ��״̬
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
    cout << "šR-���ħ��״̬��" << endl;

    // ���šR-����ħ��״̬
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
