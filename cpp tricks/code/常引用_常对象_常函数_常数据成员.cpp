#include "iostream"

using namespace std;


// 常引用作为函数形参，保证了不会对实参的值进行误修改，常引用的格式是: const 类型名 &引用名;
void fun(const double &d);


// 常对象
class A{
    public:
        A(int i, int j){
            i = x;
            j = y;
        }
    private:
        int x;
        int y;
};

// 常成员函数
class R{
    public:
        R(int i1, int i2){
            R1 = i1;
            R2 = i2;
        }
        void Print();
        void Print() const;   // 常成员函数
    private:
        int R1;
        int R2;
};

void R::Print(){
    cout << "R1 = " << R1 << " , R2 = " << R2 << endl;
}

void R::Print() const{
    cout << "R1 = " << R1 << " , R2 = " << R2 << endl;
}

// 常数据成员
class B{
    public:
        B(int i);
        void Print();
        const int &r;   // 常引用r是对变量a的引用
    private:
        const int a;   // 常数据成员
        static const int b;  // 静态常数据成员，必须在类外进行初始化！！！
};
// 静态常数据成员初始化
const int B::b = 330;
// 类外进行构造函数定义
B::B(int i): a(i), r(a){
    cout << "B的对象的构造函数\n";
}

void B::Print(){
    cout << "a = " << a << " , b = " << b << " , r = " << r << endl;
}


int main(){
    double d = 3.14;
    fun(d);
    cout << "------------------\n";
    const A a(1, 2); // 等价于A const a(1, 2);  a是常对象，不能被更新！！！
    cout << "------------------\n";
    R r(5, 4);
    r.Print();  // 调用的是普通成员函数void Print()
    R const rr(20, 45);  // rr是一个常对象
    rr.Print();  // 常对象只能调用常成员函数，所以此处调用的是void Print() const;
    cout << "------------------\n";
    //建立对象b1和b2，并以50和550作为初值，分别调用构造函数，通过构造函数的初始化列表给对象的常数据成员赋初值
    B b1(50);
    B b2(550);
    b1.Print();
    b2.Print();
    return 0;
}

void fun(const double &d){
    // 常引用作形参，在函数中不能更新d所引用的对象
    double i = 6.66;
    // d = i;  此处将报错！！！
    cout << "d = " << d << endl;
}
