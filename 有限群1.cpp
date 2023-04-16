#include<iostream>
using namespace std;

int main()
{
	int k;
	int a[4][4];
	for(k=0;k<4;k++)
	{
		a[k][0]=k;
		a[0][k]=k;
	 } 
	
	
	for(int i=0; i<4; ++i)
    {
        for(int j=0; j<4; ++j)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}
