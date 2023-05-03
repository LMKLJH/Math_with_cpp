#include <iostream>
using namespace std;

const int MAXSIZE = 100;

int group[MAXSIZE][MAXSIZE];
int n;

bool has_inverse() {
    for(int i=0;i<n;i++) {
        bool found = false;
        for(int j=0;j<n;j++) {
            if(group[i][j] == 1 && group[j][i] == 1) {
                found = true;
                break;
            }
        }
        if(!found) {
            return false;
        }
    }
    return true;
}

int main() {
    cout << "请输入矩阵元素个数n：";
    cin >> n;
    cout << "请输入矩阵元素（一行一个，总共" << n*n << "个）:\n";
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin >> group[i][j];
        }
    }
    if(has_inverse()) {
        cout << "给定的环中每个元素都可逆！" << endl;
    } else {
        cout << "给定的环中存在不可逆元素！" << endl;
    }
    return 0;
}
