#include <iostream>
#include <cstring>

using namespace std;

const int MAXN = 100000000;
bool isPrime[MAXN + 1];

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

    int cnt = 0;
    for (int i = 2; i <= MAXN; i++)
    {
        if (isPrime[i]) cnt++;
    }
    cout << "质数的个数为：" << cnt << endl;

    return 0;
}
