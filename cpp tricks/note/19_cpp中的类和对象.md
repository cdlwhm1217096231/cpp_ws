### 1.C++中的类和对象
- C++在C语言的基础上增加了面向对象编程，C++支持面向对象编程。类是C++中的核心特性，通常被称为用户自定义的成员。类用于指定对象的形式，它包含了数据表示法和处理数据的方法。**类中的数据和方法称为类的成员，函数在一个类中被称为类的成员**。
### 2.C++类定义
- 定义一个类，本质上是定义一个数据类型的蓝图。这实际上并没有定义任何数据，但它定义了类的名称意味着什么。也就是说，它定义了类的对象包括了什么，以及可以在这个对象上执行哪些操作。类的定义是以关键字class开头，后面接着是类的名字，类的主体是包含在一对花括号中。类定义后必须跟着一个分号或一个声明列表,见下面的实例：
    ```
        class Box{
        public:
            double length;
            double breadth;
            double height;
        };
    ```
- 关键字public确定了类成员的访问属性，在类对象作用域内，公共成员在类的外部是可访问的，也可以指定类的成员是private或protected。
### 3.定义C++对象
- 类提供了对象的蓝图，所以基本上对象是根据类来创建的。声明类的对象，就像声明基本类型的变量一样。下面的语句声明了类Box的两个对象：
    ```
        Box box1;
        Box box2;
    ```
### 4.访问数据成员
- 类的对象的公共数据成员可以使用直接成员运算符.来访问，**注意：私有的成员和受保护的成员不能使用直接成员访问运算符.来访问**，见下面的实例：
    ```
            Box box1;
            Box box2;
            double volume = 0.0;
            // box1详细信息
            box1.length = 5.0;
            box1.breadth = 6.0;
            box1.height = 7.0;

            // box2详细信息
            box2.length = 12.0;
            box2.breadth = 13.0;
            box2.height = 10.0;

            // box1的体积
            volume = box1.length * box1.breadth * box1.height;
            cout << "Box1的体积是: " << volume << endl;

            // box2的体积
            volume = box2.length * box2.breadth * box2.height;
            cout << "Box2的体积是: " << volume << endl;
    ```
### 5.类和对象详解
![类和对象详解.png](https://upload-images.jianshu.io/upload_images/13407176-005535d888601bf9.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)
- 5.1 C++中的类成员函数
    - 类的成员函数是指那些把定义和原型写在类定义内部的函数，就像类定义中的其他变量一样。类成员函数是类的一个成员，它可以操作类的任意对象，可以访问对象中的所有成员。下面是使用成员函数来访问类的成员，而不是直接访问这些类的成员：
        ```
            class Box{
            public:
                double length;
                double breadth;
                double height;
                double getVolume(void);
            };
        ``` 
    - 成员函数可以定义在类定义的内部，或者单独使用**范围解析运算符::来定义**。在类定义中定义的成员函数把函数声明为内联的，即便没有使用inline标识符，见下面的实例：
        ```
            class Box{
            public:
                double length;
                double breadth;
                double height;
                double getVolume(void){  // 内联的成员函数inline
                    return length * breadth * height;
                }
            };
        ```
    - 也可以在类的外部使用范围解析运算符::定义该函数,注意: 在::运算符之前必须使用类名。调用成员函数是在对象上使用点运算符.,这样就能操作与该对象相关的数据。见下面的实例:
        ```
            #include "iostream"
            using namespace std;


            class Box{
            public:
                double length;
                double breadth;
                double height;
                double getVolume(void){  // 内联的成员函数inline
                    return length * breadth * height;
                }
                double getVolume1(void);
                // 成员函数的声明
                void setLength(double len);
                void setBreadth(double bre);
                void setHeight(double hei);
            };

            // 成员函数的定义
            double Box::getVolume1(void){
                return length * breadth * height;
            }

            void Box::setLength(double len){
                length = len;
            }

            void Box::setBreadth(double bre){
                breadth = bre;
            }

            void Box::setHeight(double hei){
                height = hei;
            }

            
            int main(){
                Box box1;
                Box box2;
                double volume = 0.0;
                

                // box1的详细信息
                box1.setLength(6.0);
                box1.setBreadth(7.0);
                box1.setHeight(8.0);
                // box1的体积
                volume = box1.length * box1.breadth * box1.height;
                cout << "Box1的体积是: " << volume << endl;

                // box2的详细信息
                box2.setLength(12.0);
                box2.setBreadth(13.0);
                box2.setHeight(10.0);
                // box2的体积
                volume = box2.length * box2.breadth * box2.height;
                cout << "Box2的体积是: " << volume << endl;
                // 1.类成员函数

                return 0;
            }
        ```
    - ::叫作用域区分符，指明一个函数属于哪个类或一个数据属于哪个类。::可以不跟类名，表示全局数据或全局函数(即非成员函数)
        ```
            int month;  // 全局变量
            int day;
            int year;

            void Set(int m, int d, int y){
                ::year = y;  // 给全局变量赋值
                ::day = d;
                ::month = m;
            }

            class Tdate{
            public:
                void Set(int m, int d, int y){  // 成员函数
                    ::Set(m, d, y);  // 非成员函数
                }
            private:
                int month;
                int day;
                int year;
            };
        ```
    - 类中的成员函数与inline:定义在类中的成员函数默认都是内联的，如果在类定义的时候就在类的内部给出函数定义，那当然是最好。如果在类中未给出成员函数定义，而又想内联该函数的话，那在类外要加上inline，否则就不是内联的，如下面的例子：
        ```
            class A{
            public:
                void Foo(int x, int y){  // 自动成为内联函数
                    语句;
                }
            };
        ```
    - 将成员函数的定义体放在类声明之中虽然能带来书写上的方便，但不是一种良好的编程风格，将上例改为下例:
        ```
            class A{
                public:
                    void Foo(int x, int y);
            };
            inline void A::Foo(int x, int y){  
                语句;
            }
        ```
    - inline是一种实现的关键字，关键字inline必须与函数定义体放在一起才能使函数成为内联，仅将inline放在函数声明前面不起任何作用。如下面风格的函数Foo不能成为内联函数:
        ```
            inline void Foo(int x, int y);   // inline 仅与函数声明放在一起
            void Foo(int x, int y){
                语句;
            }
        ```
    - 如下面的风格函数Foo则成为内联函数:
        ```
            void Foo(int x, int y);
            inline void Foo(int x, int y){
                语句;
            }
        ```
    - C++中函数调用非虚成员函数，调用虚函数的区别：
        - 1.调用非虚成员函数：和调用非成员函数一样，通过对象确定对象所属的类，然后找到类的成员函数。此过程不会涉及到对象的内容，只会涉及对象的类型，是一种静态绑定。
        - 2.调用虚函数与调用非虚成员函数不同，需同过虚函数表找到虚函数的地址，而虚函数表存放在每个对象中，不能再编译期间实现。只能在运行时绑定，是一种动态绑定。
    - 类成员函数实例如下：
        ```
            class Student{
            public:
                char name[20];
                char sex[10];
                float math;
                float english;
                float program;
                void input_name();
                void input_sex();
                void input_math();
                void input_english();
                void input_program();
                void input(class Student *stu);
                void show_student_info(class Student *stu);
            };

            void Student::input_name(){
                cout << "请输入学生姓名: ";
                cin.getline(name, sizeof(name));
                cout << "学生姓名: "  << name << endl;
            }

            void Student::input_sex(){
                cout << "请输入学生性别: ";
                cin.getline(sex, sizeof(sex));
            }

            void Student::input_math(){
                cout << "请输入学生的数学成绩: ";
                cin >> math;
            }

            void Student::input_english(){
                cout << "请输入学生的英语成绩: ";
                cin >> english;
            }

            void Student::input_program(){
                cout << "请输入学生的编程课成绩: ";
                cin >> program;
            }

            void Student::show_student_info(class Student *stu){
                cout << "学生姓名: " << stu->name << endl;
                cout << "学生性别: "  << stu->sex <<endl;
                cout << "学生数学成绩: " << stu->math << endl;
                cout << "学生英语成绩: " << stu->english << endl;
                cout << "学生编程课成绩: " << stu->program << endl;
            }

            void Student::input(class Student *stu){
                stu->input_name();
                stu->input_sex();
                stu->input_english();
                stu->input_math();
                stu->input_program();
            }
            
            int main(){
                Student dana;
                Student *dana_pointer = &dana;
                dana.input(dana_pointer);
                dana.show_student_info(dana_pointer);
                return 0;
            }
        ```
- 5.2 C++中的类访问修饰符
    - 数据封装是面向对象编程的一个重要特点，它防止函数直接访问类类型的内部成员。类成员的访问限制是通过在类主体内部对各个区域标记private、public、protected来指定的。关键字private、public、protected称为访问修饰符。一个类可以有多个private、public、protected标记区域。每个标记区域在下一个区域开始之前或者在遇到类主体结束右括号之前都是有效的。**成员和类的默认访问修饰符是private**。
        ```
            class Base{
                public:
                    // 公有成员
                private:
                    // 私有成员
                protected:
                    // 保护成员
            };
        ```
    - 公有成员(public):公有成员在程序中类的外部是可以访问的，可以不使用任何成员函数来设置和获取公有变量的值，见下面的实例：
        ```
            // 公有成员
            class Line{
                public:
                    double length;
                    void setLength(double len);
                    double getLength(void);
            };

            // 成员函数的定义
            void Line::setLength(double len){
                length = len;
            }

            double Line::getLength(void){
                return length;
            }



            int main(){
                Line line;
                line.setLength(5.9);  // 使用成员函数设置长度
                cout << "线段的长度是: " << line.getLength() << endl;

                // 不使用成员函数设置长度
                line.length = 6.6;
                cout << "线段的长度是: " << line.getLength() << endl;
                return 0;
            }
        ```
    - 私有成员(private):**私有成员变量或函数在类的外部是不可以访问的，甚至是不可查看的。只有类和友元函数可以访问私有成员。默认情况下，类的所有成员都是私有的**。下面的实例中width是一个私有成员，这意味着如果没有使用任何修饰符修饰时，类的成员将被假定是私有成员。
        ```
            class Box{
            double width;  // 默认是私有成员类型！
            public:
                double length;
                void setWidth(double len);
                double getWidth(void);
            };
        ```
    - 私有成员完整的实例如下：
        ```
            class Box{
            public:
                double length;
                void setWidth(double wid);
                double getWidth(void);
            private:
                double width;  // 默认是私有成员类型！
            };
            
            void Box::setWidth(double wid){
                width = wid;
            }

            double Box::getWidth(void){
                return width;
            }
            // 不使用成员函数设置长度，因为长度是公有的
            box.length = 3.15;
            cout << "Box的长度是: " << box.length << endl;
            // 不使用成员函数设置宽度将会报错，因为width是私有的
            // box.width = 9.99;  错误！
            box.setWidth(9.99);
            cout << "Box的宽度是: " << box.getWidth() << endl;
        ```
    - 保护成员(protected):保护成员变量与函数和私有成员十分相似，但是有一点不同。**保护成员在派生类(即子类)中是可以访问的**。
        ```
            // 保护成员
            class Box1{
                protected:
                    double width;   // width是父类只的保护成员，但是不像私有成员那样，类的外部无法访问
            };
            class SmallBox:Box1{  // SmallBox是派生类
            public:
                void setSmallBoxWidth(double wid);
                double getSmallBoxWidth(void);
            };
            // 子类的成员函数定义
            void SmallBox::setSmallBoxWidth(double wid){
                width = wid;
            }

            double SmallBox::getSmallBoxWidth(void){
                return width;
            }
            // 调用成员函数
            SmallBox sbox;
            sbox.setSmallBoxWidth(4.44);
            cout << "派生类SmallBox的宽度是: " << sbox.getSmallBoxWidth() << endl;
        ```
    - 继承中的特点：有private、public、protected三种继承方式，它们相应地改变了基类成员的访问属性。但是，无论哪种方式，下面的两点都没有改变：**1.private成员只能被本类成员(类内)和友元访问，不能被派生类访问。2.protected成员可以被派生类访问**。
        - public继承：基类private、public、protected成员的访问属性在派生类中分别变成private、public、protected
        - private继承：基类private、public、protected成员的访问属性在派生类中分别变成private、private、private
        - protected继承：基类private、public、protected成员的访问属性在派生类中分别变成protected、public、protected
    - public继承实例如下：
        ```
            // public继承
            // 基类
            class A{
                public:
                    int a;
                    A(){ // 构造函数
                        a1 = 1;
                        a2 = 2;
                        a3 = 3;
                        a = 4;
                    }
                    void fun(){  // 普通成员函数
                        cout << "a = " << a <<  endl;
                        cout << "a1 = " << a1 << endl;
                        cout << "a2 = " << a2 << endl;
                        cout << "a3 = " << a3 << endl;
                    }
                public:
                    int a1;
                protected:
                    int a2;
                private:
                    int a3;
            };

            // 派生类
            class B: public A{  // 公有继承
                public:
                    int a;
                    B(int i){  // 构造函数
                        A();
                        a = i;
                    }
                    void fun(){  // 普通成员函数
                        cout << "a = " << a <<  endl;  // 正确，public成员
                        cout << "a1 = " << a1 << endl;  // 正确，基类的public成员，在派生类中仍是public成员。
                        cout << "a2 = " << a2 << endl;  // 正确，基类的protected成员，在派生类中仍是protected可以被派生类
                        // cout << "a3 = " << a3 << endl; 报错，a3在基类A中是private成员，通过public继承后，派生类中仍然是private
                    }
            };
            B b(10);
            cout << "a = " << b.a << endl;
            cout << "a1 = " << b.a1 << endl;
            // cout << b.a2 << endl;  // 错误，类外不能访问protected成员
            // cout << b.a3 << endl;   // 错误，类外不能访问private成员
        ```
    - private继承实例如下：
        ```
            // 私有继承private
            // 基类
            class AA{
                public:
                    int a;
                    AA(){
                        a1 = 1;
                        a2 = 2;
                        a3 = 3;
                        a = 4;
                    }
                    void fun(){
                        cout << "a = " << a << endl;
                        cout << "a1 = " << a1 << endl;
                        cout << "a2 = " << a2 << endl;
                        cout << "a3 = " << a3 << endl;
                    }
                public:
                    int a1;
                protected:
                    int a2;
                private:
                    int a3;
            };
            // 派生类
            class BB : private AA{
                public:
                    int a;
                    BB(int i){
                        AA();
                        a = i;
                    }
                    void fun(){
                        cout << "a = " << a << endl;  // 正确，public成员
                        cout << "a1 = " << a1 << endl;  // 正确，基类public成员,在派生类中变成了private,可以被派生类访问
                        cout << "a2 = " << a2 << endl;  // 正确，基类的protected成员，在派生类中变成了private,可以被派生类
                        // cout << "a3 = " << a3 << endl;  // 错误，基类的private成员不能被派生类访问
                    }
            };
            BB bb(100);
            cout << "a = " << bb.a << endl;  // 正确,public成员
            // cout << "a1 = " << bb.a1 << endl;    // 错误，private成员不能在类外访问。
            // cout << "a2 = " << bb.a2 << endl;    //错误, private成员不能在类外访问。
            // cout << "a3 = " << bb.a3 << endl;    //错误, private成员不能在类外访问。
        ```
    - protected继承实例如下：
        ```
            // 保护继承protected
            // 基类
            class AAA{
                public:
                    int a;
                    AAA(){
                        a1 = 1;
                        a2 = 2;
                        a3 = 3;
                        a = 4;
                    }
                    void fun(){
                        cout << "a = " << a << endl;
                        cout << "a1 = " << a1 << endl;
                        cout << "a2 = " << a2 << endl;
                        cout << "a3 = " << a3 << endl;
                    }
                public:
                    int a1;
                protected:
                    int a2;
                private:
                    int a3;
            };
            // 派生类
            class BBB : protected AAA{
                public:
                    int a;
                    BBB(int i){
                        A();
                        a = i;
                    }
                    void fun(){
                        cout << "a = " << a << endl;   // 正确，public成员
                        cout << "a1 = " << a1 << endl;  // 正确，基类的public成员，在派生类中变成了protected，可以被派生类访问
                        cout << "a2 = " << a2 << endl;  // 正确，基类的protected成员，在派生类中还是protected，可以被派生类访问
                        // cout << "a3 = " << a3 << endl;   // 错误，基类的private成员不能被派生类访问
                    }
            };
            BBB bbb(666);
            cout << "a = " << bbb.a << endl;  // 正确,public成员
            // cout << "a1 = " << bbb.a1 << endl;  // 错误，protected成员不能在类外访问
            // cout << "a2 = " << bbb.a2 << endl;  // 错误，protected成员不能在类外访问
            // cout << "a3 = " << bbb.a3 << endl;  // 错误，private成员不能在类外访问
        ```
    - 如果继承时不显示声明是private、public、protected继承，**默认是private继承**；在结构体struct中默认是public继承。
        ```
            class B: A{
                B b;
                b.a;    // 错误
                b.a1;   // 错误
                b.a2;   // 错误
                b.a3;   // 错误
            }
        ```
    - 总结三种继承方式：
        ![三种继承方式.png](https://upload-images.jianshu.io/upload_images/13407176-4e540cf95bd142f8.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

