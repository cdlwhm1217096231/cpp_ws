#include "iostream"

using namespace std;


class Shape{
    public:
        void setWidth(int w){
            width = w;
        }
        void setHeight(int h){
            height = h;
        }
    protected:
        int width;
        int height;
};

class Rect: public Shape{
    public:
        int getArea(){
            return width * height;
        }
};


// 多继承
class PaintCost{
    public:
        int getCost(int area){
            return area * 66;
        }
};



class DD: public Shape, public PaintCost{
    public:
        int getArea(){
            return width * height;
        }
};

// 虚继承
class D{
    public:
        D(){
            cout << "D对象的构造函数\n";
        }
        ~D(){
            cout << "D对象的析构函数\n";
        }
    protected:
        int d;
};

class B: virtual public D{
    public:
        B(){
            cout << "B对象的构造函数\n";
        }
        ~B(){
            cout << "B对象的析构函数\n";
        }
    protected:
        int b;
};

class A: virtual public D{
    public:
        A(){
            cout << "A对象的构造函数\n";
        }
        ~A(){
            cout << "A对象的析构函数\n";
        }
    protected:
        int a;  
};

class C: public A, public B{
    public:
        C(){
            cout << "C对象的构造函数\n";
        }
        ~C(){
            cout << "C对象的析构函数\n";
        }
    protected:
        int c;
};

int main(){
    Rect r1;
    r1.setWidth(3);
    r1.setHeight(4);
    cout << "r1对象的面积是: " << r1.getArea() << endl;
    cout << "-------------------------------------------------------------\n";
    DD dd;
    int area;
    dd.setWidth(4);
    dd.setHeight(5);
    area = dd.getArea();
    cout << "总面积是: " << dd.getArea() << endl;
    cout << "总代价是: " << dd.getCost(area) << endl; 
    cout << "-------------------------------------------------------------\n";
    C c; // D B A C
    cout << "sizeof(c) = " << sizeof(c) << endl;
    return 0;
}