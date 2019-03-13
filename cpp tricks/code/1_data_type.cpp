#include "iostream"
#include "string"
#include "limits"
#include "stdio.h"


using namespace std;



#define f(x)  x*x  // 宏定义


// 1 typedef执行时间不同
typedef unsigned int UINT;
void func(){
    // UINT value = "abc";  类型检测，将出错
    // cout << value << endl;
}

// 2 作用域不同

// 宏的作用域
void func1(){
    #define HW "helloworld"
}

void func2(){
    string str = HW;
    cout << str << endl;
}
// typedef的作用域

void func3(){
    typedef unsigned int UINT;
}

void func4(){
    // UNIT uvalue = 5;  报错！
}


class A{
    typedef unsigned int UINT;
    UINT uvalueA;
    A(): uvalueA(0){}
};

class B{
    // UINT uvalueB;  报错
};
// 在B类中使用UINT会出错，因为UINT只在类A的作用域中。
// 此外，在类中用typedef定义的类型别名还具有相应的访问权限

class AA{
    typedef unsigned int UINT;
    UINT valueA;
    AA(): valueA(0){}
};

void func5(){
    // AA::UINT i = 1;报错，在typedef前加上public权限则可以
}

// 3 对指针的操作---二者修饰指针类型时，作用不同
typedef int* pint;
#define PINT int*


int i1 = 1, i2 = 2;
const pint p1 = &i1;  // 等价于int * const p;指针常量:指针p是一个常量,p不可更改，p指向的内容可以更改
const PINT p2 = &i2;  // 等价于const int *p/int const *p，p可以更改，p指向的内容不可更改，常量指针

pint s1, s2;  // s1 和 s2都是int类型指针
PINT s3, s4;  // 相当于 int * s3, s4;只有一个是指针

void TestPointer(){
    cout << "p1:" << p1 << " *p1 = " << *p1 << endl;
    // p1 = &i2; 指针常量p1不能被修改
    *p1 = 5;   // 但是p1指向的内容可以修改
    cout << "p1:" << p1 << " *p1 = " << *p1 << endl;

    cout << "p2:" << p2 << " *p2 = " << *p2 << endl;
    // *p2 = 5; 常量指针p2能被修改
    p2 = &i1;   // 但是p2指向的内容不可以修改
    cout << "p2:" << p2 << " *p2 = " << *p2 << endl;

}



// 定义一个枚举类型
enum color{
    red, green, blue=5, yellow
};
int main(){
    cout << "bool: " << "所占字节数：" << sizeof(bool) << endl; 
    cout << "char: " << "所占字节数：" << sizeof(char) << endl;  
    cout << "signed char: " << "所占字节数：" << sizeof(signed char) << endl;  
    cout << "int: " << "所占的字节数: " << sizeof(int) << endl;
    cout << "unsigned int: " << "所占的字节数: " << sizeof(unsigned int) << endl;
    cout << "signed int: " << "所占的字节数: " << sizeof(signed int) << endl;
    cout << "short int: " << "所占的字节数: " << sizeof(short int) << endl;
    cout << "unsigned short int: " << "所占的字节数: " << sizeof(unsigned short int) << endl;
    cout << "signed short int: " << "所占的字节数: " << sizeof(signed short int) << endl;
    cout << "long int: " << "所占的字节数: " << sizeof(long int) << endl;
    cout << "signed long  int: " << "所占的字节数: " << sizeof(signed long int) << endl;
    cout << "unsigned long  int: " << "所占的字节数: " << sizeof(unsigned long int) << endl;
    cout << "float: " << "所占的字节数: " << sizeof(float) << endl;
    cout << "double: " << "所占的字节数: " << sizeof(double) << endl;
    cout << "long double: " << "所占的字节数: " << sizeof(long double) << endl;
    cout << "wchar_t: " << "所占的字节数: " << sizeof(wchar_t) << endl;

    typedef int feet;   // typedef声明,但typedef int feet = 100;错误！
    feet distance;
    // 1 宏定义执行时间不同
    int a = 6, b = 6, c;
    c = f(a) / f(b);
    printf("%d\n", c);


    TestPointer();


    cout << "red = " << red << " yellow = " << yellow << endl;
    // 枚举类型举例
    enum days{
        one, two, three
    }day;
    day = one;
    switch(day){
        case one:
            cout << "one" << endl;
            break;
        case two:
            cout << "two" << endl;
            break;
        default:
            cout << "默认输出" << endl;
            break;
    }
    return 0;
}