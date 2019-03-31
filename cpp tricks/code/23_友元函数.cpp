#include "iostream"

using namespace std;


class Box{
    double width;  // 默认是private
    public:
        double length;
        friend void printWidth(Box box);  // 友元函数声明
        friend class BigBox;  // 友元类的声明
        void setWidth(double wid);
};

// 成员函数的定义
void Box::setWidth(double wid){
    width = wid;
}
// 友元函数的定义
// 请注意：printWidth() 不是任何类的成员函数!!!
void printWidth(Box box){
     /* 因为printWidth()是Box的友元函数，它可以直接访问该类的任何成员 */
    cout << "Width of Box: " << box.width << endl;
}


class INT{
    friend void Print(const INT& obj);  // 声明友元函数
};
// 友元函数的定义
void Print(const INT& obj){
    cout << "我是INT类的友元函数，我骄傲!\n";
}

// 友元类的使用
class BigBox{
    public:
        void Print(int width, Box &box){
            // BigBox是Box类的友元类，它可以直接访问Box类的任何成员
            box.setWidth(width);
            cout << "Width of Box: " << box.width << endl;
        }
};

int main(){
    Box box;
    BigBox big;
    // 使用成员函数设置宽度
    box.setWidth(10.0);
    // 使用友元函数输出宽度
    printWidth(box); // 调用友元函数！
    cout << "-------------------------------------\n";
    INT obj;
    Print(obj);  // 直接调用友元函数，不需要使用对象或者指针！
    cout << "-------------------------------------\n";
    // 使用友元类中的方法设置宽度
    big.Print(20, box);
    return 0;
}