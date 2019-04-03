#include "iostream"

using namespace std;


class Shape{
    protected:
        int width;
        int height;
    public:
        Shape(int a = 0, int b = 0): width(a), height(b){
            cout << "基类Shape类的构造函数\n";
        }
        virtual int area(){     // 此处已经修改，在area()函数的前面加上了virtual关键字！！！ 
            cout << "基类Shape的area()" << endl;
            return 0;
        }
};

class Rect: public Shape{
    public:
        Rect(int a = 0, int b = 0): width(a), height(b){
            cout << "派生类Rect的构造函数\n";
        }
        int area(){
            cout << "派生类Rect的area()" << endl;
            return width * height;
        }
    protected:
        int width;
        int height;
};

class Triangle: public Shape{
    public:
        Triangle(int a=0, int b=0): Shape(a, b){
            cout << "派生类Triangle的构造函数\n";
        }
        int area(){
            cout << "派生类Triangle的area()" << endl;
            return width * height / 2;
        }
};

// 在一个类中如果存在未定义的虚函数，那么不能直接使用该类的实例，可以理解因为未定义virtual函数，其类是抽象的，无法实例化。
class Base {
    public:
        // virtual void tail();  虚函数没有定义，仅仅是声明而已
};

class People : public Base {
    public:
        void tail() {
            cout << "people" << endl;
        }
};
// 基类中的虚函数或纯虚函数在派生类中依然是虚函数。
// 有时，我们并不希望基类的某个函数在派生类中被重写，在C++11及以后可以用关键字 final来避免该函数再次被重写。
class Parent{
    public:
        virtual void fun(){
            cout << "这个是基类\n";
        }
};
class Son: public Parent{
    public:
        void fun() final{  // 正确，fun在Parent中是虚函数
            cout << "这是派生类\n";
        }
};

class Children: public Son{
    /*   不正确，fun在Son中已经不再是虚函数，不能再被重写
    public:
        void fun(){
            cout << "这是派生类的派生类即孙子类Children\n";
        }
    */
};

int main(){
    Shape *shape;  // 指向类Shape的指针shape
    Rect r(10, 7);
    Triangle t(10, 5);

    shape = &r;  // 存储矩形的地址
    // 调用矩形的求面积函数
    shape->area();

    // 存储三角形的地址
    shape = &t;
    // 调用三角形的求面积函数
    shape->area();
    cout << "----------------------------------------------------\n";
    // Base base;  因为Base类中有未定义的虚函数，所以不能直接使用该类的实例化对象，Base类是抽象的，无法实例化
    People people;
    people.tail();
    (&people)->tail();  // &people相当于是指向People类的指针
    cout << "----------------------------------------------------\n";
    Son s;
    Children c;
    Parent* parent;
    parent = &s;
    parent->fun();
    parent = &c;
    Son *son;
    son = &c;
    parent->fun();
    son->fun();
    return 0;
}