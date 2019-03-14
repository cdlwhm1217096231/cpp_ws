### 1.Cpp中的存储类
- **存储类定义C++程序中变量/函数的范围（可见性）和生命周期**。这些说明符放置在它们所修饰的类型之前。从C++ 11开始，auto关键字不再是C++存储类说明符，且register关键字被弃用。下面列出C++程序中可用的存储类：
    - auto
    - register
    - static
    - extern
    - mutable
    - thread_local (C++11)
### 2.auto存储类
- 自C++11以来，auto关键字用于两种情况：**声明变量时根据初始化表达式自动推断该变量的类型、声明函数时函数返回值的占位符**。C++98标准中auto关键字用于自动变量的声明，但由于使用极少且多余，在C++11中已删除这一用法。根据初始化表达式自动推断被声明的变量的类型，如：
```
auto f = 3.14;  // double
auto s("hello");  // const char*
auto z = new auto(9);  // int*
auto x1 = 5, x2 = 5.0, x3 = 'r';  // 错误，必须是同一类型
```
### 3.register存储类
- register 存储类用于定义存储在寄存器中而不是 RAM 中的局部变量。这意味着变量的最大尺寸等于寄存器的大小（通常是一个词），且不能对它应用一元的'&'运算符（因为它没有内存位置）。
```
{
   register int  miles;
}
```
- 寄存器只用于需要快速访问的变量，比如计数器。还应注意的是，定义 'register' 并不意味着变量将被存储在寄存器中，它意味着变量可能存储在寄存器中，这取决于硬件和实现的限制。
### 4.static存储类
- static存储类指示编译器在程序的生命周期内保持局部变量的存在，而不需要在每次它进入和离开作用域时进行创建和销毁。因此，使用 static修饰局部变量可以在函数调用之间保持局部变量的值。
- static修饰符也可以应用于全局变量。当 static 修饰全局变量时，会使变量的作用域限制在声明它的文件内。
- 在C++中，当static用在类数据成员上时，会导致仅有一个该成员的副本被类的所有对象共享。
```
#include "iostream"

using namespace std;


// static存储类实例
static int count = 10;  // 静态全局变量
void fun(void);



int main(){
    // static存储类
    while(count--){
        fun();
    }
    return 0;
}

void fun(void){
    static int i = 5;   // 静态局部变量
    i++;
    cout << "变量i为：" << i << endl;
    cout << "变量count为: " << count << endl;
}
```
- 静态局部变量有以下特点：
    - 该变量在全局数据区分配内存；
    - 静态局部变量在程序执行到该对象的声明处时被首次初始化，即以后的函数调用不再进行初始化；
    - 静态局部变量一般在声明处初始化，如果没有显式初始化，会被程序自动初始化为0；
    - 它始终驻留在全局数据区，直到程序运行结束。但其作用域为局部作用域，当定义它的函数或语句块结束时，其作用域随之结束；
- static修饰类的成员变量：
    - 静态成员变量是先于类的对象而存在
    - 这个类的所有对象共用一个静态成员
    - 如果静态成员是公有的，那么可以直接通过类名调用
    - 静态成员数据在声明时候,在类外进行初始化
```
#include <iostream>

using namespace std;
class Data
{
public:
    Data(){}
    ~Data(){}
    void show()
    {
        cout<<this->data<<" "<<number<<endl;
    }

    static void showData()//先于类的对象而存在
    {
        //这方法调用的时候不包含this指针
        cout<<" "<<number<<endl;
    }

private:
    int data;
public:
    static int number; //静态数据在声明时候类外初始化
};
int Data::number=0;//静态成员初始化

int main()
{
    Data::showData();//通过类名直接调用


    Data::number = 100;//通过类名直接使用
    Data d;
    d.show();
    d.showData();//通过对象调用

    cout << "Hello World!" << endl;
    return 0;
}
```
- static 修饰类的成员方法：
    - 静态成员函数是先于类的对象而存在
    - 可用类名直接调用（公有）
    - 在静态成员函数中没有this指针，所以不能使用非静态成员
- const修饰的成员变量必须在构造方法的参数列表初始化（const static int pdata=10;除外）const 修饰的成员变量不能被修改。
```
class foo{
public:
    foo():i(100){}
private:
    const int i=100; // 错误!!!
};
//或者通过这样的方式来进行初始化
foo::foo():i(100){}
```
- const修饰的成员函数中不能修改成员变量，不能调用非const修饰的函数
### 5.extern存储类
- extern存储类用于提供一个全局变量的引用，全局变量对所有的程序文件都是可见的。当您使用'extern'时，对于无法初始化的变量，会把变量名指向一个之前定义过的存储位置。
- 当你有多个文件且定义了一个可以在其他文件中使用的全局变量或函数时，可以在其他文件中使用extern来得到已定义的变量或函数的引用。可以这么理解，extern是用来在另一个文件中声明一个全局变量或函数。
- extern修饰符通常用于当有两个或多个文件共享相同的全局变量或函数的时候，如下所示：
```
// 第一个文件main.cpp
#include <iostream>
 
int count ;
extern void write_extern();
 
int main()
{
   count = 5;
   write_extern();
}

// 第二个文件support.cpp
#include <iostream>
 
extern int count;
 
void write_extern(void)
{
   std::cout << "Count is " << count << std::endl;
}
在这里，第二个文件中的 extern 关键字用于声明已经在第一个文件 main.cpp 中定义的 count。现在 ，编译这两个文件，如下所示：
g++ main.cpp support.cpp -o write
这会产生 write 可执行程序，尝试执行 write，它会产生下列结果：
./write
```
### 6.mutable存储类
- mutable说明符仅适用于类的对象，这将在本教程的最后进行讲解。它允许对象的成员替代常量。也就是说，mutable成员可以通过const成员函数修改。
### 7.thread_local 存储类
- 使用 thread_local 说明符声明的变量仅可在它在其上创建的线程上访问。 变量在创建线程时创建，并在销毁线程时销毁，每个线程都有其自己的变量副本。
- thread_local说明符可以与static或extern 合并。
- **可以将thread_local仅应用于数据声明和定义，thread_local不能用于函数声明或定义。**以下演示了可以被声明为 thread_local 的变量：
```
thread_local int x;  // 命名空间下的全局变量
class X
{
    static thread_local std::string s; // 类的static成员变量
};
static thread_local std::string X::s;  // X::s 是需要定义的
 
void foo()
{
    thread_local std::vector<int> v;  // 本地变量
}
```
