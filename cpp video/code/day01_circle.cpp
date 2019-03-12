#include "iostream"

using namespace std;


// 求圆的面积

// 1.用面向过程的方法求解

// >> <<不会用：标准输入cin和标准输出cout始终写在操作符的左边
// int main(){
//     double r = 0;
//     double s = 0;

//     cout << "请输入圆的半径: ";
//     // cin标准输入 代表键盘
//     cin >> r;

//     cout << "r的值是: " << r << endl;

//     s = 3.14 * r * r;
//     cout << "圆形的面积是: " << s << endl;
//     return 0;
// }



// 2.面向对象的方法求解
// 2.1 类的抽象 成员变量和成员函数  
// 2.2 实例化 类的对象  
// 2.3 求面积
    // 面向过程加工的是一个一个的函数
    // 面向对象加工的是一个一个的类
// 2.4 main函数集成测试


// 在Cpp中定义了一个自定义数据类型，即一个结构体
struct Circle{
    double m_s;  // 圆的面积
    double m_r;  // 圆的半径
};


// 在Cpp中定义了一个自定义数据类型 MyCircle

// 思考1：类的调用 执行过程分析==>类代码不是一步一步指向
// 类是一个数据类型,(固定大小内存块的别名)；定义一个类是一个抽象的概念，不会给你分配内存。
// 用数据类型定义变量的时候，才会分配内存
// cpp编译器是如何区分c1对象 c2对象 c3对象调用了类的方法
// class类是一个数据类型和对象是1：n的关系

// 思考2：cpp编译器是如何处理多个对象，调用类的成员函数的，具体一点：如何区分是c1 c2 c3调用了getS

class MyCircle{
public:
    double m_s;  // 圆的面积  属性  成员变量
    double m_r;  // 圆的半径
public:
    void setR(double r){  // 成员函数
        m_r = r;
    }

    double getR(){  // 成员函数
        return m_r;
    }

    double getS(){
        m_s = 3.14 * m_r * m_r;
        return m_s;
    }
protected:
private:
};



int main(){
    MyCircle c1, c2, c3;  // 用类定义变量(对象)
    double r1, r2, r3;

    // 圆形1
    cout << "请输入c1圆的半径: ";
    cin >> r1;
    // 给c1圆的属性赋值
    c1.setR(r1);
    cout << "c1圆的面积是: " << c1.getS() << endl;

    // 圆形2
    cout << "请输入c2圆的半径: ";
    cin >> r2;
    // 给c2圆的属性赋值
    c2.setR(r2);
    cout << "c2圆的面积是: " << c2.getS() << endl;

    return 0;
}

