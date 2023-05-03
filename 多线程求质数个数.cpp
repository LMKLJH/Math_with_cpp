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
    memset(isPrime, true, sizeof(isPrime)); // 初始化所有数都是质数
    isPrime[0] = isPrime[1] = false; // 0和1不是质数

    for (int i = 2; i * i <= MAXN; i++)
    {
        if (isPrime[i])
        {
            for (int j = i * i; j <= MAXN; j += i)
            {
                isPrime[j] = false; // 将i的倍数标记为合数
            }
        }
    }

    const int THREAD_COUNT = 1; // 使用四个线程
    thread threads[THREAD_COUNT];
    int interval = MAXN / THREAD_COUNT; // 每个线程处理的区间长度

    for (int i = 0; i < THREAD_COUNT; i++) {
        int start = i * interval + 1;
        int end = (i == THREAD_COUNT - 1 ? MAXN : (i + 1) * interval);
        threads[i] = thread(countPrimes, start, end); // 创建新线程
    }

    for (int i = 0; i < THREAD_COUNT; i++) {
        threads[i].join(); // 等待线程结束
    }

    cout << "质数的个数为：" << cnt << endl;

    return 0;
}

