#include "iostream"
#include "cstdlib"

using namespace std;



// 静态多态
int Add(int a, int b){
    return a+b;
}
double Add(double a, int b){
    return a+b;
}

// 动态多态
class TakeBus{
    public:
        void TakeBusToSubway(){
            cout << "go to subway\n";
        }
        void TakeBusToStation(){
            cout << "go to station\n";
        }
};

class Bus{
    public:
        virtual void TakeBusToSomewhere(TakeBus& tb) = 0;   // 纯虚函数,Bus是个抽象类,提供一个接口
};

class Subway: public Bus{
    public: 
        virtual void TakeBusToSomewhere(TakeBus& tb){  // 虚函数
            tb.TakeBusToSubway();
        }
};

class Station: public Bus{
    public:
        virtual void TakeBusToSomewhere(TakeBus& tb){   // 虚函数
            tb.TakeBusToStation();
        }
};
// 动态多态2

// 基类
class Base{
    public:
        virtual void fun(int i){  // fun在基类中被声明是虚函数，可以动态绑定，根据传入的派生类对象进行调用对应的成员函数
            cout << "Base::fun()\n";
        }
        void fun1(int i){  // fun1在基类中没有被声明是虚函数，不能动态绑定
            cout << "Base::fun1()\n";
        }
};

class Derived: public Base{
    public:
        virtual void fun(int i){
            cout << "Derived::fun()\n";
        }
        virtual void fun1(int i){
            cout << "Derived::fun1()\n";
        }
        void fun2(int i){
            cout << "Derived::fun2()\n";
        }
};
// 全局函数
void TestVirtual(Base& b){
    b.fun(0);
    b.fun1(1);
}


int main(){
    Add(10, 20);
    Add(10.0, 20);
    cout << "------------------------\n";
    TakeBus tb;
    Bus *b = NULL;
    for(int i = 1; i <= 10; ++i){
        if((rand() % i) & 1)
            b = new Subway();
        else    
            b = new Station();
    }
    b->TakeBusToSomewhere(tb);
    delete b;
    cout << "------------------------\n";
    Base b1;
    Derived d1;
    TestVirtual(b1);
    TestVirtual(d1);

    return 0;
}