#include "iostream"
#include "string"


using namespace std;

// 变量的声明
extern int a, b;
extern int c;
extern float f;

// 函数声明
int func();



int main(){
    // 变量的定义
    int a, b;
    int c;
    float f;
    // 实际初始化
    a = 10;
    b = 20;
    c = a + b;
    cout << c << endl;
    f = 70.0 / 3.0;
    cout << f << endl;

    // 函数调用
    int i = func();

    // 自动转换
    int aa = 1;
    double bb = 2.1;
    aa = bb;
    cout << "aa = " << aa << endl;  //输出为 2，丢失小数部分

    int a1 = 1;
    double b1 = 2.1;
    cout << "a1 + b1 = " << a1 + b1 << endl;  //输出为a + b = 3.1

    // 强制转换
    int as = 1;
    float e = 2.3;
    cout << "as + e = " << as + (int) e << endl;
    
    // 变量的定义与声明的区别
    int a2 = 0;     //定义并声明了变量 a2
    extern int a2;  //只是声明了有一个变量 a2 存在，具体 a2 在哪定义的，需要编译器编译的时候去找。
    return 0;
}

// 函数定义
int func(){
    return 0;
}