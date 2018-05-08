// c++存储类
/*
存储类定义了 C++ 程序中变量/函数的范围（可见性）和生命周期。这些说明符放置在它们所修饰的类型之前
C++ 程序中可用的存储类：auto register extern static mutable thread_local (C++11)
从 C++ 11 开始，auto 关键字不再是 C++ 存储类说明符，且 register 关键字被弃用
*/

// auto 存储类
/*
自 C++ 11 以来，auto 关键字用于两种情况：声明变量时,根据初始化表达式,自动推断该变量的类型;声明函数时函数返回值的占位符。
根据初始化表达式,自动推断被声明的变量的类型，如：
auto f=3.14;      //double
auto s("hello");  //const char*
auto z = new auto(9); // int*
auto x1 = 5, x2 = 5.0, x3 = 'r';//错误，必须是初始化为同一类型
*/

// register 存储类
/*
register 存储类用于定义存储在寄存器中而不是 RAM 中的局部变量,这意味着变量的最大尺寸等于寄存器的大小（通常是一个词）
且不能对它应用一元的 '&' 运算符（因为它没有内存位置）。
register int  miles;
*/

// static 存储类
/*
使用 static 修饰局部变量可以在函数调用之间保持局部变量的值
static 修饰符也可以应用于全局变量。当 static 修饰全局变量时，会使变量的作用域限制在声明它的文件内。
未经初始化的全局静态变量会被自动初始化为0

static 修饰类的成员变量:
1). 静态成员变量是先于类的对象而存在
2). 这个类的所有对象共用一个静态成员
3). 如果静态成员是公有的，那么可以直接通过类名调用
4). 静态成员数据在声明时候类外初始化
5). 在静态成员函数中没有this指针，所以不能使用非静态成员

#include <iostream>

using namespace std;
class Data
{
public:
Data(){}
~Data(){}
void show()
{
cout <<this->data<<" "<<number<<endl;
}

static void showData()//先于类的对象而存在
{
//这个方法调用的时候不包含this指针
cout <<" "<<number<<endl;
}

private:
int data;
public:
static int number; //静态数据在声明的时候，类外初始化
};
int Data::number=0;//静态成员类外初始化

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
*/
#include <iostream>
 

static int count = 10; /* 全局变量 */

// 函数声明 
void func(void);

// 函数定义
void func(void)
{
	static int i = 5; // 局部静态变量
	i++;
	std::cout << "变量 i 为 " << i;
	std::cout << " ,变量 count 为 " << count << std::endl;
}
// 假设你不使用预处理 using namespace std;,就要加上 std::cin 或者 std::cout。
/*
cin 用于从控制台获取用户输入，cout 用于将数据输出到控制台。
cin 是输入流对象，cout 是输出流对象，它们分别可以用 >> 和 <<
*/
 
int main()
{
    while(count--)
    {
       func();
    }
    return 0;
}

// extern 存储类
/*
当您有多个文件且定义了一个可以在其他文件中使用的全局变量或函数时，可以在其他文件中使用 extern 来得到已定义的变量或函数的引用。
可以这么理解，extern 是用来在另一个文件中声明一个全局变量或函数。
第一个文件：
#include <iostream>

int count ;
extern void write_extern();

int main()
{
count = 5;
write_extern();
}
第二个文件：
#include <iostream>

extern int count;

void write_extern(void)
{
std::cout << "Count is " << count << std::endl;
}
在这里，第二个文件中的 extern 关键字用于声明已经在第一个文件中定义的 count
*/

// mutable 存储类
/*
mutable 说明符仅适用于类的对象,mutable 成员可以通过 const 成员函数修改。
*/

// thread_local 存储类
/*
可以将 thread_local 仅应用于数据声明和定义，thread_local 不能用于函数声明或定义。

*/