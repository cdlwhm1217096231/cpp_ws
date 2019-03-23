#include "iostream"

using namespace std;

void swap(int &a, int &b);
double & setValues(int i, double *arr);
int & func();
void print_info();
void swaps(int *x, int *y);



// 定义一个结构体类型
typedef struct{
    int age;
    char name;
    double salary;
}Student;

int main(){
    // 声明简单变量
    int i;
    double d;
    // 声明引用变量
    int &r = i;  // 与int r = i;的区别是内存的分配，后者会再分配一个内存空间
    double &s = d;

    i = 5;
    cout << "i = " << i << endl;
    cout << "i的引用是: " << r << endl;
    cout << "i的地址是: " << &i << endl;
    cout << "r的地址是: " << &r << endl;

    d = 11.7;
    cout << "d = " << d << endl;
    cout << "d的引用是: " << s << endl;
    /*注意与上面的对比不同*/
    int x;
    int y = x;
    x = 6;
    cout << "x = " << x << endl;
    cout << "y = " << y << endl;
    cout << "x的地址是: " << &x << endl;
    cout << "y的地址是: " << &y << endl;
    // 结构体类型的引用
    print_info();
    // 指针类型的引用
    int m = 10; // 定义一个整型的变量a
    int *p = &m; // 定义一个指向变量a的指针p
    int *&p_reference = p;  // 定义指针p的引用p_reference即是p的别名
    *p_reference = 20; // 把20赋值给*p_reference,相当于把20赋值给*p,也就是相当于把值赋值给a
    cout << "m = " << m << endl;
    // 引用作为函数参数
    int a = 100;
    int b = 200;
    cout << "没有交换前a,b的值分别是: a = " << a << ",b = " << b << endl; 
    swap(a, b);
    cout << "交换后a,b的值分别是: a = " << a << ",b = " << b << endl;
    // 指针作为函数参数
    int aa = 100;
    int bb = 200;
    cout << "没有交换前aa,bb的值分别是: aa = " << aa << ",bb = " << bb << endl; 
    swaps(&aa, &bb);
    cout << "交换后aa,bb的值分别是: aa = " << aa << ",bb = " << bb << endl;
    // 引用作为函数的返回值
    double vals[] = {10.1, 12.6, 3.14, 24.1, 50.5};
    cout << "数组没改变前的值: " << endl;
    for (int i = 0; i < 5; i++)
        cout << "vals[" << i << "] = " << vals[i] << endl;
    cout << "数组改变后的值: " << endl;
    setValues(1, vals) = 20.23;  // 改变数组的第2个元素
    setValues(3, vals) = 78.99;  // 改变数组的第4个元素
    for (int i = 0; i < 5; i++)
        cout << "vals[" << i << "] = " << vals[i] << endl;
    return 0;
}

void swap(int &x, int &y){
    int temp;
    temp = x;
    x = y;
    y = temp;
}

// 引用作为函数的返回值
double &setValues(int i, double *arr){
    return arr[i];
}

// 当返回一个引用时，注意被引用的对象不能超过作用域。所以返回一个对局部变量的引用时不合法的，可以返回一个静态变量的引用
int & func(){
    int q;
    // return q;编译错误
    static int x;
    return x;  // 编译正确，x在函数作用域外依然有效
}

void print_info(){
    Student s1;  // 定义一个结构体变量，s1
    Student &s = s1;   // 给s1起了一个别名叫s
    s.age = 20;  // 通过引用给结构体变量的数据成员赋值
    s.name = 'A';
    cout << "s.age = " << s.age << ", s.name = " << s.name << endl;
}

void swaps(int *x, int *y){
    int temp;
    temp = *x;
    *x = *y;
    temp = *x;
}