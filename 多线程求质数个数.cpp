#include <iostream>
#include <cstring>
#include <thread>
#include <mutex>

using namespace std;

const int MAXN = 100000000;
bool isPrime[MAXN + 1];

mutex mtx;
int cnt = 0;

void countPrimes(int start, int end) {
    for (int i = start; i <= end; i++) {
        if (isPrime[i]) {
            mtx.lock();
            cnt++;
            mtx.unlock();
        }
    }
}

int main()
{
    memset(isPrime, true, sizeof(isPrime)); // ��ʼ����������������
    isPrime[0] = isPrime[1] = false; // 0��1��������

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

    const int THREAD_COUNT = 1; // ʹ���ĸ��߳�
    thread threads[THREAD_COUNT];
    int interval = MAXN / THREAD_COUNT; // ÿ���̴߳�������䳤��

    for (int i = 0; i < THREAD_COUNT; i++) {
        int start = i * interval + 1;
        int end = (i == THREAD_COUNT - 1 ? MAXN : (i + 1) * interval);
        threads[i] = thread(countPrimes, start, end); // �������߳�
    }

    for (int i = 0; i < THREAD_COUNT; i++) {
        threads[i].join(); // �ȴ��߳̽���
    }

    cout << "�����ĸ���Ϊ��" << cnt << endl;

    return 0;
}

