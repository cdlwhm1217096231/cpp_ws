#include "iostream"

using namespace std;


class Base{
    public:
        Base(){
            cout << "Base::Base()\n";
            fun();
        }
        virtual ~Base(){
            cout << "Base::Base()\n";
            fun();
        }
        virtual void fun(){
            cout << "Base::fun() virtual\n";
        }
};

// ÅÉÉúÀà
class Derive: public Base{
    public:
        Derive(){
            cout << "Derive::Derive()\n";
            fun();
        }
        ~Derive(){
            cout << "Derive::Derive()\n";
            fun();
        }
        virtual void fun(){
            cout << "Derive::fun() virtual\n";
        }
};

int main(){
    Base *b = new Base();
    delete b;
    cout << "-----------------------------------\n";
    Derive *d = new Derive();
    delete d;
    cout << "-----------------------------------\n";
    Base *bd = new Derive();
    delete bd;
    return 0;
}
