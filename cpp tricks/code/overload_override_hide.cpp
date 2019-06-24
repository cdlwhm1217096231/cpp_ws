#include "iostream"

using namespace std;


// 重载、重写(覆盖)、隐藏对比

class A{
    public:
        void test(int i);  // overload
        void test(double i);  // overload
        void test(int i, double j);  // overload
        void test(double i, int j);  // overload
        // int test(int i);  函数重载不关心返回值的类型，所以不是函数重载！！！
};

// 重写(覆盖)override
class Base{
    public:
        virtual void fun(int i){   // 基类中被重写的函数！
            cout << "Base::fun(int): " << i << endl;  
        }
};

class Derived: public Base{
    public:
        virtual void fun(int i){   // 在派生类中重写基类中的函数
            cout << "Derived::fun(int): " << i << endl;
        }
};

// 隐藏hide
class AA{
    public:
        void func(double i, int j){
            cout << "AA::func(double, int): " << endl;
        }
};

class BB: public AA{
    public:
        int func(int i){
            cout << "BB::func(int i): " << i << endl;
            return i;
        }
};

// 重载 重写 隐藏的对比
class AAA{
    public:
        virtual void f(float x){
            cout << "AAA::f(float x): " << x << endl;
        }
        void g(float x){
            cout << "AAA::g(float x): " << x << endl;
        }
        void h(float x){
            cout << "AAA::h(float x): " << x << endl;
        }
        // 函数重载
        void foo(int i){
            cout << "AAA::foo(int i): " << i << endl;
        }

        void foo(double d){
            cout << "AAA::foo(double d): " << d << endl;
        }
};

class BBB: public AAA{
    public:
        virtual void f(float x){
            cout << "BBB::f(float x): " << x << endl;
        }
        void g(int x){
            cout << "BBB::g(int x): " << x << endl;
        }
        void h(float x){
            cout << "BBB::h(float x): " << x << endl;
        }
};

int main(){
    Base b;
    Base *pb = new Derived();
    pb->fun(666);  // Derived::fun(int) 
    cout << "---------------------------------------\n";
    BB bb;
    bb.func(1000);  // BB::func(int i)
    // bb.func(0.01, 1000);  BB::func函数不接受2个参数！！！
    cout << "---------------------------------------\n";
    AAA aaa;
    BBB bbb;
    AAA *paaa = &bbb;
    BBB *pbbb = &bbb;
    paaa->f(3.14);
    pbbb->f(3.14);

    paaa->g(3.14);
    pbbb->g(3.14);

    paaa->h(3.14);
    pbbb->h(3.14);
    cout << "---------------------------------------\n";
    paaa->foo(3.14);
    return 0;
}