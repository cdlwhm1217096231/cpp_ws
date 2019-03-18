#include "iostream"
#include "cmath"
#include "ctime"
#include "cstdlib"
#include "cstdio"

#define random(x) (rand() % x)
using namespace std;

int main(){
    // 数字定义
    short s;
    int i;
    long l;
    float f;
    double d;
    // 数字赋值
    s = 10;
    i = - 1000;
    l = 1000000;
    f = 230.45;
    d = 4545.398;
    cout << "s = " << s << endl;
    cout << "i = " << i << endl;
    cout << "l = " << l << endl;
    cout << "f = " << f << endl;
    cout << "d = " << d << endl;
    // 数学运算
    cout << "sin(d) = " << sin(d) << endl;
    cout << "abs(i) = " << abs(i) << endl;
    cout << "floor(d) = " << floor(d) << endl;
    cout << "sqrt(f) = " << sqrt(f) << endl;
    cout << "pow(d, 2) = " << pow(d, 2) << endl;
    // 随机数1
    int m, n;
    // 设置随机数种子
    srand((unsigned)time(NULL)); // time()用来获取系统时间的秒数，通过调用rand()函数来生成随机数
    // 生成10个随机数
    for(m = 0; m < 10; m++){
        // 生成实际的随机数
        n = rand();
        cout << "随机数: " << n << endl;
    }
    // 随机数2
    const int MAX = 10;
    int number[MAX] = {0};
    int k;
    srand((unsigned) time(NULL));  // 播种子
    for (k = 0; k < MAX; k++){
        number[k] = rand() % 100;  // 产生100内的随机数
        cout << "number[" << k << "] = " << number[k] << endl;
    }
    // 随机数3
    srand((int)time(0));
    for (int a = 0; a < 10; a++){
        cout << random(100) << endl; // 输出0-100内的随机数
    }
    return 0;
}