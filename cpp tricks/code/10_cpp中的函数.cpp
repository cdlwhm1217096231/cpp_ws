#include "iostream"
#include "vector"
#include "string"

using namespace std;

int maxnum(int num1, int num2);  // 函数声明
void swap(int a, int b);
void swap1(int *a, int *b);
void swap2(int &a, int &b);

int main(){
    int num1 = 3, num2 = 6;
    int result;
    result = maxnum(num1, num2);
    cout << "两个数之间的最大数是: " << result << endl;
    // 1 传值调用
    int a = 4, b = 40;
    cout << "交换前的a, b值: " << "a = " << a << ",b = " << b << endl;
    swap(a, b);  // 传值调用只是形参从实参那复制了一份实参的值，被调用函数内的代码不会改变用于调用函数的实际参数
    cout << "交换后的a, b值: " << "a = " << a << ",b = " << b << endl;
    // 2 指针调用
    int x = 4, y = 40;
    cout << "交换前的x, y值: " << "x = " << x << ",y = " << y << endl;
    swap1(&x, &y);  // 实际参数将实际值的地址复制后再传给形式参数，形式参数获得地址后，在被调用函数的内部可以通过传进来的地址访问调用中用到的实际参数，修改形式参数会影响实际参数！
    cout << "交换后的x, y值: " << "x = " << x << ",y = " << y << endl;
    // 3 引用调用
    int m = 4, n = 40;
    cout << "交换前的m, n值: " << "m = " << m << ",n = " << n << endl;
    swap2(m, n); // 将实参的引用的地址复制了一份传给形参,形式参数获得实际参数引用的地址后，在被调用函数的内部可以通过传进来的实际参数的引用的地址访问调用中用到的实际参数，修改形式参数会影响实际参数！
    cout << "交换后的m, n值: " << "m = " << m << ",n = " << n << endl;
    return 0;
}


// 函数定义
int maxnum(int num1, int  num2){
    if (num1 > num2)
        return num1;
    else
        return num2;
}

// 传值调用方式
void swap(int a, int b){
    int temp;
    temp = a;
    a = b;
    b = temp;
}
// 指针传递方式
void swap1(int *a, int *b){
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

// 引用传递方式
void swap2(int &a, int &b){
    int temp;
    temp = a;
    a = b;
    b = temp;
}

