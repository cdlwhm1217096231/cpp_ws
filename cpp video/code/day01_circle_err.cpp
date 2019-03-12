#include "iostream"

using namespace std;


class Circle{
public:
    double r;
    double pi = 3.1415926;
    double area = pi * r * r;   // 为什么需要成员函数？
};

int main(){
    Circle c1;
    cout << "请输入圆的半径: ";
    cin >> c1.r;

    cout << c1.area << endl;  // 乱码
    return 0;
}