#include "iostream"
#include "stdio.h"

using namespace std;

// 1.const分配内存时间：编译器编译时

// int main(){
//     int a;
//     const int b = 10;
//     int c;
//     printf("&a:%d,&b:%d,&c:%d\n", &a, &b, &c);
//     return 0;
// }

// 2.const和#define相同之处
// #define在编译预处理阶段 处理
// const常量是由编译器处理的,提供类型检查和作用域检测

/*
int main(){
    // int a = 10;
    // int b = 20;
    // int array[a+b];  // linux内核里面是成立的，原因是linux内核的gcc编译器支持，c/cpp编译器不支持

    const int c = 10;
    const int d = 20;
    int array[c+d];

    return 0;
}
*/

// 3.const和#define的不同之处
// cpp中的const常量类似于宏定义  const int c = 4;   #define c 4;
// cpp中的const常量与宏定义不同：
//      const常量是由编译器处理的,提供类型检查和作用域检测
//      宏定义由预编译器处理,单纯的文本替换

void fun1(){
    #define a 10
    const int b = 20;
    // #undef a;  #undef;
}

void fun2(){
    printf("a = %d\n", a);
    // printf("b = %d\n", b);
}

int main(){
    fun1();
    fun2();
    return 0;
}