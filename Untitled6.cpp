#include <iostream>
#include <string.h> // 加入这个头文件以使用 strcmp 函数
using namespace std;

char MS[4][6];

int main()
{
    // 从控制台读取输入并存储到字符数组中
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 6; ++j) {
            cin >> MS[i][j];
        }
        cout << endl;
    }

    // 输出当前魔方状态
    cout << "当前魔方状态：" << endl;
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 6; ++j) {
            cout << MS[i][j] << " ";
        }
        cout << endl;
    }

    // 复制一份 MS 数组内容到 MS1 数组中
    char MS1[4][6];
    memcpy(MS1, MS, sizeof(char) * 4 * 6);

    // 比较两个数组内容是否相同
    if (memcmp(MS1, MS, sizeof(char) * 4 * 6) == 0) {
        cout << "两个数组内容相同" << endl;
    }
    else {
        cout << "两个数组内容不相同" << endl;
    }

    return 0;
}

