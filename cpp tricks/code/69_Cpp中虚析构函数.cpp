#include <iostream>

using namespace std;

// 基类
class Base{
    public:
        Base(){};
        virtual ~Base(){  // 基类的析构函数是虚函数！
            cout << "delete Base\n";
        };
        virtual void DoSomething(){
            cout << "Do Something in class Base!\n";
        };
};


// 派生类
class Derived: public Base{
    public:
        Derived(){};
        ~Derived(){
            cout << "delete Derived\n";
        };
        void DoSomething(){
            cout << "Do Something in Derived\n";
        };
};


int main(){
    Base *b = new Derived;
    b->DoSomething();  // 重写DoSomething函数
    delete b;
    return 0;
}