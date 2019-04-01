#include "iostream"

using namespace std;

class Box{
    public:
        static int count;  // 声明一个静态成员变量！
        Box(double l, double w, double h): length(l), width(w), height(h){
            cout << "这是Box类对象的构造函数....\n";
            count++; // 每创建一个Box类的对象时，count增加1
        }
        double getVolume(){
            return length * width * height;
        }
        // 静态成员函数定义!!!
        static int getCount(){
            return count;
        }
    private:
        double length;
        double width;
        double height;
};
// 静态成员变量要在类外初始化！
int Box::count = 0;

// 可以使用静态成员变量清楚了解构造与析构函数的调用情况
class Cpoint{
    public:
        static int value;
        static int num;
        Cpoint(int x, int y): xp(x), yp(y){
            value++;
            cout << "调用构造: " << value << endl;
            cout << this->xp << " " << this->yp << endl;
        }
        ~Cpoint(){
            num++;
            cout << "调用析构: " << num << endl;
            cout << this->xp << " " << this->yp << endl;
        }
    private:
        int xp;
        int yp;
};

// 静态成员变量初始化
int Cpoint::num = 0;
int Cpoint::value = 0;


class CRect{
    public:
        CRect(int x1, int x2): mpt1(x1, x1), mpt2(x2, x2){
            cout << "调用构造\n";
        }
        ~CRect(){
            cout << "调用析构\n";
        }
    private:
        Cpoint mpt1, mpt2;
};
int main(){
    // 在创建对象前输出对象的总数
    cout << "未创建对象前的对象数是: " << Box::getCount() << endl;
    Box box1(3.2, 1.4, 5.5);
    Box box2(6.6, 4.2, 8.7);
    cout << "Box类总共的对象数是: " << Box::getCount() << endl;
    cout << "---------------------------------------\n";
    CRect p(10, 20);
    cout << "hello world!\n";
    return 0;
}