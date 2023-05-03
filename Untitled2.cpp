#include <iostream>
#include <cstring>
#include <omp.h> // ���ͷ�ļ�

using namespace std;

const int MAXN = 10000000;
bool isPrime[MAXN + 1];

int main()
{
    memset(isPrime, true, sizeof(isPrime)); // ��ʼ����������������
    isPrime[0] = isPrime[1] = false; // 0��1��������

    omp_set_num_threads(8); // �����߳�����Ϊ8

#pragma omp parallel for
    for (int i = 2; i * i <= MAXN; i++)
    {
        if (isPrime[i])
        {
            for (int j = i * i; j <= MAXN; j += i)
            {
                isPrime[j] = false; // ��i�ı������Ϊ����
            }
        }
    }

    int cnt = 0;
#pragma omp parallel for reduction(+:cnt)
    for (int i = 2; i <= MAXN; i++)
    {
        if (isPrime[i]) cnt++;
    }

    cout << "�����ĸ���Ϊ��" << cnt << endl;

    return 0;
}

