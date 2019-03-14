#include "iostream"
#include <stdio.h>
#include <stdlib.h>

using namespace std;


class Test1{
public:
    Test1(int n){
        num = n;
        cout << "num = " << num << endl;
    }  // 普通构造函数
private:
    int num;
};

class Test2{
public:
    explicit Test2(int n){
        num = n;
        cout << "num = " << num << endl;
    }  //  explicit(显式)构造函数
private:
    int num;
};

int main(){
    short int i;  // 有符号短整型
    short unsigned int j;  // 无符号短整型
    j = 50000;
    i = j;
    cout << i << " " << j << endl;
    // explicit关键字的使用
    Test1  t1 = 12;  //  隐式调用其构造函数,成功
    // Test2  t2 = 12;  编译错误,不能隐式调用其构造函数
    Test2 t2(12);   // 显式调用成功
    return 0;
}