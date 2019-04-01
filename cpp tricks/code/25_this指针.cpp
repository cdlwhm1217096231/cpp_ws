#include "iostream"

using namespace std;


class Box{
    public:
    // 构造函数定义
       Box(double l = 2.0, double w = 3.0, double h = 4.0): length(l), width(w), height(h){
            cout << "这是Box的构造函数...\n";
        }
        // 普通成员函数
        double Volume(){
            return length * width * height;
        }
        
        int compare(Box box){
            return this->Volume() > box.Volume();
        }
    private:
        int length;
        int width;
        int height;
};

class Rect{
    public:
        Rect(){;}
        ~Rect(){;}
        Rect* get_address(){  // 指针函数，返回this的地址
            return this;
        }
};


int main(){
    Box box1(3.3, 2.1, 1.5);
    Box box2(8.5, 6.0, 2.0);
    if(box1.compare(box2))
        cout << "box2 小于 box1\n";
    else
        cout << "box2 大于等于 box1\n";
    cout << "----------------------------\n";
    Rect r1;
    Rect r2;
    // Rect* 定义指针p接受对象r1的get_address()成员函数的返回值，并打印
    Rect* p = r1.get_address();
    cout << "通过this指针来返回调用get_address()成员函数的对象r1的地址p = " << p << endl;
    p = r2.get_address();
    cout << "通过this指针来返回调用get_address()成员函数的对象r2的地址p = " << p << endl;
    return 0;
}