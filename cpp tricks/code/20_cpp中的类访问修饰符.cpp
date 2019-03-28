#include "iostream"
#include "assert.h"


using namespace std;

// 公有成员
class Line{
    public:
        double length;
        void setLength(double len);
        double getLength(void);
};

// 私有成员
class Box{
    public:
        double length;
        void setWidth(double wid);
        double getWidth(void);
    private:
        double width;  // 默认是私有成员类型！
};

// 保护成员
// 基类
class Box1{
    protected:
        double width;   // width是父类只的保护成员，但是不像私有成员那样，类的外部无法访问
};
// 派生类
class SmallBox:Box1{  // SmallBox是派生类
    public:
        void setSmallBoxWidth(double wid);
        double getSmallBoxWidth(void);
};

// public继承
// 基类
class A{
    public:
        int a;
        A(){ // 构造函数
            a1 = 1;
            a2 = 2;
            a3 = 3;
            a = 4;
        }
        void fun(){  // 普通成员函数
            cout << "a = " << a <<  endl;
            cout << "a1 = " << a1 << endl;
            cout << "a2 = " << a2 << endl;
            cout << "a3 = " << a3 << endl;
        }
    public:
        int a1;
    protected:
        int a2;
    private:
        int a3;
};

// 派生类
class B: public A{  // 公有继承
    public:
        int a;
        B(int i){  // 构造函数
            A();
            a = i;
        }
        void fun(){  // 普通成员函数
            cout << "a = " << a <<  endl;  // 正确，public成员
            cout << "a1 = " << a1 << endl;  // 正确，基类的public成员，在派生类中仍是public成员。
            cout << "a2 = " << a2 << endl;  // 正确，基类的protected成员，在派生类中仍是protected可以被派生类
            // cout << "a3 = " << a3 << endl; 报错，a3在基类A中是private成员，通过public继承后，派生类中仍然是private
        }
};

// 私有继承private
// 基类
class AA{
    public:
        int a;
        AA(){
            a1 = 1;
            a2 = 2;
            a3 = 3;
            a = 4;
        }
        void fun(){
            cout << "a = " << a << endl;
            cout << "a1 = " << a1 << endl;
            cout << "a2 = " << a2 << endl;
            cout << "a3 = " << a3 << endl;
        }
    public:
        int a1;
    protected:
        int a2;
    private:
        int a3;
};
// 派生类
class BB : private AA{
    public:
        int a;
        BB(int i){
            AA();
            a = i;
        }
        void fun(){
            cout << "a = " << a << endl;  // 正确，public成员
            cout << "a1 = " << a1 << endl;  // 正确，基类public成员,在派生类中变成了private,可以被派生类访问
            cout << "a2 = " << a2 << endl;  // 正确，基类的protected成员，在派生类中变成了private,可以被派生类
            // cout << "a3 = " << a3 << endl;  // 错误，基类的private成员不能被派生类访问
        }
};
// 保护继承protected
// 基类
class AAA{
    public:
        int a;
        AAA(){
            a1 = 1;
            a2 = 2;
            a3 = 3;
            a = 4;
        }
        void fun(){
            cout << "a = " << a << endl;
            cout << "a1 = " << a1 << endl;
            cout << "a2 = " << a2 << endl;
            cout << "a3 = " << a3 << endl;
        }
    public:
        int a1;
    protected:
        int a2;
    private:
        int a3;
};
// 派生类
class BBB : protected AAA{
    public:
        int a;
        BBB(int i){
            A();
            a = i;
        }
        void fun(){
            cout << "a = " << a << endl;   // 正确，public成员
            cout << "a1 = " << a1 << endl;  // 正确，基类的public成员，在派生类中变成了protected，可以被派生类访问
            cout << "a2 = " << a2 << endl;  // 正确，基类的protected成员，在派生类中还是protected，可以被派生类访问
            // cout << "a3 = " << a3 << endl;   // 错误，基类的private成员不能被派生类访问
        }
};


// 成员函数的定义
void Line::setLength(double len){
    length = len;
}

double Line::getLength(void){
    return length;
}

void Box::setWidth(double wid){
    width = wid;
}

double Box::getWidth(void){
    return width;
}

// 子类的成员函数定义
void SmallBox::setSmallBoxWidth(double wid){
    width = wid;
}

double SmallBox::getSmallBoxWidth(void){
    return width;
}



int main(){
    Line line;
    line.setLength(5.9);  // 使用成员函数设置长度
    cout << "线段的长度是: " << line.getLength() << endl;

    // 不使用成员函数设置长度
    line.length = 6.6;
    cout << "线段的长度是: " << line.getLength() << endl;
    cout << "------------------------------------------------------\n";
    Box box;
    // 不使用成员函数设置长度，因为长度是公有的
    box.length = 3.15;
    cout << "Box的长度是: " << box.length << endl;
    // 不使用成员函数设置宽度将会报错，因为width是私有的
    // box.width = 9.99;  错误！
    box.setWidth(9.99);
    cout << "Box的宽度是: " << box.getWidth() << endl;
    cout << "------------------------------------------------------\n";
    SmallBox sbox;
    sbox.setSmallBoxWidth(4.44);
    cout << "派生类SmallBox的宽度是: " << sbox.getSmallBoxWidth() << endl;
    cout << "------------------------------------------------------\n";
    B b(10);
    cout << "a = " << b.a << endl;
    cout << "a1 = " << b.a1 << endl;
    // cout << b.a2 << endl;  // 错误，类外不能访问protected成员
    // cout << b.a3 << endl;   // 错误，类外不能访问private成员
    cout << "------------------------------------------------------\n";
    BB bb(100);
    cout << "a = " << bb.a << endl;  // 正确,public成员
    // cout << "a1 = " << bb.a1 << endl;    // 错误，private成员不能在类外访问
    // cout << "a2 = " << bb.a2 << endl;    // 错误, private成员不能在类外访问
    // cout << "a3 = " << bb.a3 << endl;    // 错误, private成员不能在类外访问
    cout << "------------------------------------------------------\n";
    BBB bbb(666);
    cout << "a = " << bbb.a << endl;  // 正确,public成员
    // cout << "a1 = " << bbb.a1 << endl;  // 错误，protected成员不能在类外访问
    // cout << "a2 = " << bbb.a2 << endl;  // 错误，protected成员不能在类外访问
    // cout << "a3 = " << bbb.a3 << endl;  // 错误，private成员不能在类外访问
    return 0;
}