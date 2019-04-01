#include "iostream"

using namespace std;



class Box{
    public:
        Box(double l, double w, double h): length(l), width(w), height(h){
            cout << "Box类的构造函数在这!\n";
        }
        double Volume(){
            return length * width *height;
        }
    private:
        double length;
        double width;
        double height;
};


int main(){
    Box box1(3.3, 4.3, 2.1);
    Box box2(4.8, 1.2, 3.9);
    Box *boxptr;  // 定义一个指向Box类的指针变量boxptr
    // 指针变量的初始化
    boxptr = &box1;  // 保存第一个对象的地址
    cout << "Box1的体积是: " << boxptr->Volume() << endl;
    boxptr = &box2;
    cout << "Box2的体积是: " << boxptr->Volume() << endl;
    return 0;
}