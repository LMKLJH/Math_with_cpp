#include <iostream>
#include <vector>

using namespace std;

const int N = 2; // 质数表中大于等于10000000的最小质数为1047301

int main()
{
    vector<bool> prime(N, true); // 定义初始全为true的布尔型向量
    prime[0] = false; // 0和1不是质数
    prime[1] = false; 
    int count = 0; // 记录已找到的质数个数
    for (int i = 2; i < N && count < 10000000; ++i) // 从2开始遍历整个数组，直到找到1千万个质数为止
    {
        if (prime[i]) 
        {
            ++count;
            for (int j = i * 2; j < N; j += i) // 筛去i的倍数
            {
                prime[j] = false;
            }
        }
    }
    cout << "The 1 millionth prime number is: " << count << endl; // 输出结果
    return 0;
}
