### 1.cpp中的基本内置数据类型（7种）
- bool  char  int float double void(无类型) wchar_t(宽字符型)：typedef wchar_t short int;
- 一个基本类型可以被一个或多个类型修饰符来修饰。
    - signed
    - unsigned
    - short 
    - long
- 下表显示了各种变量类型在内存中存储值时需要占用的内存，以及该类型的变量所能存储的最大值和最小值(**变量的大小会根据编译器和所使用的电脑而有所不同**)
![基本数据类型.png](https://upload-images.jianshu.io/upload_images/13407176-b102c5b08a016185.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)
### 2.typedef声明
- 使用typedef为已有的类型取一个新的名字，语法如下：
```
格式：typedef type name;
例如：typedef int feet;  feet是int的另一个名称
     feet distance;  创建一个整型变量distance
```
- typedef 可以声明各种类型名，但不能用来定义变量。用 typedef 可以声明数组类型、字符串类型，使用比较方便。
- 用typedef只是对已经存在的类型增加一个类型名，而没有创造新的类型。
- 当在不同源文件中用到同一类型数据（尤其是像数组、指针、结构体、共用体等类型数据）时，常用 typedef 声明一些数据类型，把它们单独放在一个头文件中，然后在需要用到它们的文件中用 ＃include 命令把它们包含进来，以提高编程效率。
- 使用 typedef 有利于程序的通用与移植。有时程序会依赖于硬件特性，用 typedef 便于移植。
- typedef 与 #define 的区别
    - 2.1 执行时间不同
        - 关键字 typedef 在编译阶段有效，由于是在编译阶段，因此 typedef 有类型检查的功能。
        - #define 则是宏定义，发生在预处理阶段，也就是编译之前，它只进行简单而机械的字符串替换，而不进行任何检查
        ```
            typedef unsigned int UINT;
            void func(){
                UINT value = "abc";  // 类型检测，将会报错
                cout << value << endl;
            }
            //--------------------------------------------------------//
            #define f(x) x*x

            int main(){
                int a = 6, b = 2, c;
                c = f(a) / f(b);
                printf("%d\n", c);
                return 0;
            }
        ```
    - 2.2 功能上的差异
        - typedef 用来定义类型的别名，定义与平台无关的数据类型，与 struct 的结合使用等。
        - #define 不只是可以为类型取别名，还可以定义常量、变量、编译开关等。
    - 2.3 作用域不同
        - #define 没有作用域的限制，只要是之前预定义过的宏，在以后的程序中都可以使用。而 typedef 有自己的作用域。
        ```
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
        ```
    - 2.4 对指针的操作----二者修饰指针类型时，作用不同
        ```
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
        ```
### 3.枚举类型
- 枚举类型是cpp中的一种派生数据类型，是由用户定义的若干枚举常量的集合
- 如果一个变量只有几种可能的值，可以定义为枚举类型。“枚举”就是将变量的值一一列举出来，变量的值只能在列举出来的值的范围内。
- 创建枚举，需要用到关键字enum，枚举类型的一般形式为:
```
enum 枚举名{
    标识符[=整型常量];
    标识符[=整型常量];
    ....
    标识符[=整型常量];
} 枚举变量;
```
- 如果枚举没有初始化，即省略掉'=整型常数'时,则从第一个标识开始，如下面的例子，变量c的类型是color,最后被赋值为blue。
```
enum color{
    red, green, blue
} c;
c = blue;
```
- 默认情况下，第一个名称的值是0，第二个名称的值是1，第三个名称的值是2，依次类推。可以在定义枚举类型时，对枚举元素赋值。此时，赋值的枚举值为所赋的值，而其他没有赋值的枚举值在为前一个枚举值加1，例如下面：
```
enum color{
    red, greed = 5, blue
};
blue = 6,默认情况下，每个名称都会比前一个名称大，但red的值仍然是0.
```

