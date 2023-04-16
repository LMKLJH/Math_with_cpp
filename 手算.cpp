#include <iostream>  
#include <cstring>  
#include<string>
#include <algorithm>  
using namespace std;  
  
string add(string a, string b) { // 实现大整数的加法  
    string res = "";  
    int len_a = a.size(), len_b = b.size(), carry = 0;  
    reverse(a.begin(), a.end());  
    reverse(b.begin(), b.end());  
    int len = max(len_a, len_b);  
    for (int i = 0; i < len; i++) {  
        int tmp = carry;  
        if (i < len_a) tmp += a[i] - '0';  
        if (i < len_b) tmp += b[i] - '0';  
        carry = tmp / 10;  
        res += to_string(tmp % 10);  
    }  
    if (carry) res += "1";  
    reverse(res.begin(), res.end());  
    return res;  
}  
  
string sub(string a, string b) { // 实现大整数的减法  
    string res = "";  
    int len_a = a.size(), len_b = b.size(), borrow = 0, i = 0;  
    reverse(a.begin(), a.end());  
    reverse(b.begin(), b.end());  
    while (i < len_a || i < len_b) {  
        int difference = (i < len_a ? a[i] - '0' : 0) - borrow - (i < len_b ? b[i] - '0' : 0);  
        borrow = 0;  
        if (difference < 0) {  
            difference += 10;  
            borrow = 1;  
        }  
        res.push_back(difference + '0');  
        i++;  
    }  
    while (res.size() > 1 && res.back() == '0') res.pop_back();  
    reverse(res.begin(), res.end());  
    return res;  
}  
  
string mul(string a, string b) { // 实现大整数的乘法  
    int len_a = a.size(), len_b = b.size();  
    string res(len_a + len_b, '0');  
    for (int i = len_a - 1; i >= 0; i--) {  
        int carry = 0;  
        for (int j = len_b - 1; j >= 0; j--) {  
            int tmp = (a[i] - '0') * (b[j] - '0') + carry + (res[i + j + 1] - '0');  
            carry = tmp / 10;  
            res[i + j + 1] = tmp % 10 + '0';  
        }  
        res[i] += carry;  
    }  
    while (res.size() > 1 && res.front() == '0') res.erase(res.begin());  
    return res;  
}  
  
string div(string a, string b) { // 实现大整数的除法  
    if (b == "0") return "error";  
    if (a == "0") return "0";  
    if (a.size() < b.size()) return "0";  
    string res = "", r = a;  
    for (int i = 0; i < (int)a.size() - (int)b.size() + 1; i++) {  
        int j = 0;  
        while (j < (int)b.size() && r[i + j] == b[j]) j++;  
        if (j == (int)b.size() || r[i + j] < b[j]) {  
            res += (char)(r[i] != '0' || res.size() ? r[i] : ' ');  
            r[i + j] -= j == (int)b.size() ? 0 : (b[j] - '0');  
        }  
        else {  
            res += (char)(r[i] != '0' || res.size() ? r[i] - 1 : ' ');  
            r[i + j] -= j == (int)b.size() ? 0 : (b[j] - '0') + 10;  
        }  
        for (j = (int)b.size() - 1; j > 0; j--) {  
            if (r[i + j] < '0') {  
                r[i + j] += 10;  
                r[i + j - 1]--;  
            }  
        }  
    }  
    while (res.size() > 1 && res.front() == '0') res.erase(res.begin());  
    return res;  
}  
  
int main() {  
    string a, b;  
    char op;  
    cin >> a >> op >> b;  
    if (op == '+') cout << add(a, b) << endl;  
    else if (op == '-') cout << sub(a, b) << endl;  
    else if (op == '*') cout << mul(a, b) << endl;  
    else if (op == '/') cout << div(a, b) << endl;  
    else cout << "error" << endl;  
    return 0;  
}  
