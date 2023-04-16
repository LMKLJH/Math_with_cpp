#include <iostream>
#include <cmath>
#include <stdio.h>
#include <processthreadsapi.h>

double get_cpu_time(){
    FILETIME a,b,c,d;
    if (GetProcessTimes(GetCurrentProcess(),&a,&b,&c,&d) != 0){
        //  Returns total user time.
        //  Can be tweaked to include kernel times as well.
        return
            (double)(d.dwLowDateTime |
            ((unsigned long long)d.dwHighDateTime << 32)) * 0.0000001;
    }else{
        //  Handle error
        return 0;
    }
}

using namespace std;
int main() {
    int n = 3;
    int max_val;
    cout<<"验证范围不超过？"; 
	cin>> max_val;
    
    // Start measuring time
    double begin = get_cpu_time();
    

    for (int x = 1; x <= max_val; x++) {
        for (int y = x; y <= max_val; y++) {
            for (int z = y; z <= max_val; z++) {
                if (pow(x, n) + pow(y, n) == pow(z, n)) {
                    cout << "Fermat's Last Theorem is false!" << endl;
                    cout << "x = " << x << ", y = " << y << ", z = " << z << endl;
                    return 0;
                }
            }
        }
    }

    cout << "Fermat's Last Theorem is true for n = " << n << endl;
    // Stop measuring time and calculate the elapsed time
    double end = get_cpu_time();
    double elapsed = (end - begin);

    printf("消耗时间: %.3f 秒.\n", elapsed);

    system ("pause");
    return 0;
}
