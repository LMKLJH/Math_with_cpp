#include <iostream>
#include <string.h> // �������ͷ�ļ���ʹ�� strcmp ����
using namespace std;

char MS[4][6];

int main()
{
    // �ӿ���̨��ȡ���벢�洢���ַ�������
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 6; ++j) {
            cin >> MS[i][j];
        }
        cout << endl;
    }

    // �����ǰħ��״̬
    cout << "��ǰħ��״̬��" << endl;
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 6; ++j) {
            cout << MS[i][j] << " ";
        }
        cout << endl;
    }

    // ����һ�� MS �������ݵ� MS1 ������
    char MS1[4][6];
    memcpy(MS1, MS, sizeof(char) * 4 * 6);

    // �Ƚ��������������Ƿ���ͬ
    if (memcmp(MS1, MS, sizeof(char) * 4 * 6) == 0) {
        cout << "��������������ͬ" << endl;
    }
    else {
        cout << "�����������ݲ���ͬ" << endl;
    }

    return 0;
}

