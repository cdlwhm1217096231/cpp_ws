#include <iostream>

using namespace std;

// explicit函数的介绍!!!

// explicit函数的作用：explicit构造函数是用来防止隐式转换的
class Test1{
    public:
        Test1(int n){  // 普通隐式的构造函数
            num = n;
        }
    private:
        int num;
};

class Test2{
    public:
        explicit Test2(int n){   //explicit(显式)构造函数
            num = n;
        }
    private:
        int num;
};

class Test{
    public:
        Test():a(0){
            cout << "void\n";
        }
    explicit Test(int i):a(i){
        cout << "int\n";
    }
    Test(short s):a(s){
        cout << "short\n";
    }
    Test & operator=(int n){
        a = n;
        cout << "operator = ";
    }
    private:
        int a;
};


int main(){
    Test1 t1 = 12;  // 隐式调用其构造函数,成功
    // Test2 t2 = 12;  编译错误,不能隐式调用其构造函数
    Test2 t3(12);  //  显式调用成功
    int n;
    Test a = n;
    return 0;
}