#include <iostream>
#include <vector>

using namespace std;

const int N = 2; // �������д��ڵ���10000000����С����Ϊ1047301

int main()
{
    vector<bool> prime(N, true); // �����ʼȫΪtrue�Ĳ���������
    prime[0] = false; // 0��1��������
    prime[1] = false; 
    int count = 0; // ��¼���ҵ�����������
    for (int i = 2; i < N && count < 10000000; ++i) // ��2��ʼ�����������飬ֱ���ҵ�1ǧ�������Ϊֹ
    {
        if (prime[i]) 
        {
            ++count;
            for (int j = i * 2; j < N; j += i) // ɸȥi�ı���
            {
                prime[j] = false;
            }
        }
    }
    cout << "The 1 millionth prime number is: " << count << endl; // ������
    return 0;
}
