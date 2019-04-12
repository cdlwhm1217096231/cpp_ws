#include "iostream"


using namespace std;


// 对象的动态与静态类型
class B{
    public:
        void DoSomething(){
            cout << "B DoSomething()......\n";
        }
        virtual void vfun(){
            cout << "B vfun()......\n";
        }
        // 缺省参数和虚函数一起出现
        virtual void func(int i = 20){
            cout << "B func()......\n";
        }
};


class C: public B{
    public:
        void DoSomething(){  // 首先说明一下，这个子类重新定义了父类的no-virtual函数，这是一个不好的设计，会导致名称隐藏；这里只是为了说明动态绑定和静态绑定才这样使用。
            cout << "C DoSomething().....\n";
        }
        virtual void vfun(){
            cout << "C vfun()......\n";
        }
        virtual void func(){
            cout << "C func()......\n";
        }
};

class D:public B{
    public:
        void DoSomething(){
            cout << "D DoSomething().....\n";
        }
        virtual void vfun(){
            cout << "D vfun()......\n";
        }
        virtual void func(){
            cout << "D func()......\n";
        }
};



int main(){
    // D *pD = new D();  // pD的静态类型是它声明的类型D*，动态类型也是D*
    // B *pB = pD;  // pB的静态类型是它声明的类型B*，动态类型是pB所指向的对象pD的类型D*
    // C *pC = new C();  // pC的静态类型是它声明的类型C*，动态类型也是C*
    // pB = pC;  // pB的动态类型是可以更改的，现在它的动态类型是C*
    cout << "-------------------------------------------------------\n";
    // 静态绑定
    // D *pD = new D();
    // B *pB = pD;
    // pD->DoSomething();
    // pB->DoSomething();
    // cout << "-------------------------------------------------------\n";
    // // 动态绑定
    // pD->vfun();
    // pD->vfun();
    cout << "-------------------------------------------------------\n";
    // 缺省参数和虚函数一起出现,是静态绑定！
    D *pD = new D();
    B* pB = pD;
    pD->func();
    pB->func();
    return 0;
}
