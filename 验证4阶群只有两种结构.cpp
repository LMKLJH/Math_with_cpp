//�����ǻ���C++�ĳ�����������֤4��Ⱥֻ�����ֽṹ
#include <iostream>
using namespace std;

// ����4��ȺԪ�ص�����Ϊ 0, 1, 2, 3
enum GroupElement { ZERO, ONE, TWO, THREE };

// ����˷������
GroupElement mul_table[4][4] = {
    {ZERO, ONE, TWO, THREE},
    {ONE, ZERO, THREE, TWO},
    {TWO, THREE, ZERO, ONE},
    {THREE, TWO, ONE, ZERO}
};

// ����Ƿ���ڵ�λԪ
bool has_identity() {
    for(int i=0; i<4; i++) {
        bool is_id = true;
        for(int j=0; j<4; j++) {
            if(mul_table[i][j] != j || mul_table[j][i] != j) {
                is_id = false;
                break;
            }
        }
        if(is_id) {
            return true;
        }
    }
    return false;
}

// ���ÿ��Ԫ���Ƿ񶼿���
bool has_inverses() {
    for(int i=0; i<4; i++) {
        bool found_inv = false;
        for(int j=0; j<4; j++) {
            if(mul_table[i][j] == ZERO && mul_table[j][i] == ZERO) {
                found_inv = true;
                break;
            }
        }
        if(!found_inv) {
            return false;
        }
    }
    return true;
}

// ��������Ƿ����
bool is_associative() {
    for(int i=0; i<4; i++) {
        for(int j=0; j<4; j++) {
            for(int k=0; k<4; k++) {
                if(mul_table[mul_table[i][j]][k] != mul_table[i][mul_table[j][k]]) {
                    return false;
                }
            }
        }
    }
    return true;
}

// ����Ƿ�ɽ���
bool is_commutative() {
    return mul_table[1][2] == mul_table[2][1];
}

int main() {
    // ���˷����С
    if(sizeof(mul_table) / sizeof(GroupElement) != 16) {
        cerr << "�˷��������ȷ��" << endl;
        return 1;
    }
    // ���Ⱥ����
    if(!has_identity() || !has_inverses() || !is_associative()) {
        cout << "�����ľ�����һ��Ⱥ��" << endl;
        return 0;
    }
    // ���Ⱥ�Ƿ�ɽ���
    if(is_commutative()) {
        cout << "������Ⱥ��һ������Ⱥ��" << endl;
    } else {
        cout << "������Ⱥ��һ���ǽ���Ⱥ��" << endl;
    }
    return 0;
}
/*

�ó�����������²��ԣ��ȼ��˷����Ƿ�Ϊ4 x 4��С��������ǣ������������Ϣ���˳����򡣽����������Ǽ��þ����Ƿ�����˷���ա����е�λԪ��ÿ��Ԫ�ض����桢����ɳ������Ӷ���֤����һ��Ⱥ����Щ���������κ�Ⱥ����������������Ǽ���Ⱥ�Ƿ�ɽ����������Ƿ�����AbelȺ�Ķ��壩��������ɽ����������"������Ⱥ��һ������Ⱥ��"���������"������Ⱥ��һ���ǽ���Ⱥ��"��

�ڱ������У�����ʹ����ö�������������ĸ�ȺԪ�أ���ʹ�ô�����������͵��ԡ�ע�⣺���Ǽ�������е�ֵ��0��ʼ������3����ʾ����ʾ�����ȺԪ�ز������֣�����Ҫ���Ĵ�������Ӧ��ͬ�������
*/
