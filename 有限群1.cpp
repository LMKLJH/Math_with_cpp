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
    cout << "���������Ԫ�ظ���n��";
    cin >> n;
    cout << "���������Ԫ�أ�һ��һ�����ܹ�" << n*n << "����:\n";
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin >> group[i][j];
        }
    }
    if(has_inverse()) {
        cout << "�����Ļ���ÿ��Ԫ�ض����棡" << endl;
    } else {
        cout << "�����Ļ��д��ڲ�����Ԫ�أ�" << endl;
    }
    return 0;
}
