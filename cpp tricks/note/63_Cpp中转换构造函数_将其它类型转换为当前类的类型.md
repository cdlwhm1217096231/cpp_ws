### 1.C++转换构造函数：将其它类型转换为当前类的类型
- 在C/C++中，不同的数据类型之间可以相互转换。**无需用户指明如何转换的称为自动类型转换（隐式类型转换），需要用户显式地指明如何转换的称为强制类型转换**。
    ```
        // 自动类型转换示例
        int a = 6;
        a = a + 3.12;  // 将小数转换为整数会抹掉小数点后面的数字
        // 强制类型转换示例
        int b = 100;
        int *p = &b;
        float *ptr = (float *)p;  // 将int *转换为float *只是简单地复制指针的值
    ```
- **不管是自动类型转换还是强制类型转换，前提必须是编译器知道如何转换**，例如，将小数转换为整数会抹掉小数点后面的数字，将int \*转换为float \*只是简单地复制指针的值，这些规则都是编译器内置的，我们并没有告诉编译器。总之，**如果编译器不知道转换规则就不能转换，使用强制类型也无用**，请看下面的例子：
    ```
        #include "iostream"

        using namespace std;

        // 如果编译器不知道转换规则就不能转换，使用强制类型也无用
        class complex{
            public:
                complex():m_real(0.0), m_img(0.0){}
                complex(double real, double img):m_real(real), m_img(img){}
            public:
                friend ostream & operator<< (ostream &out, const complex &c); // 友元函数
            private:
                double m_real;
                double m_img;
        };

        ostream & operator << (ostream &out, const complex &c){
            out << c.m_real << "+" << c.m_img << "i";
            return out;
        }

        int main(){
            complex a(10.0, 20.0);
            a = (complex) 25.5;  // 错误，转换失败
            return 0;
        }
    ```
- 上面的例子中，25.5是实数，a是复数，将25.5赋值给a后，我们期望a的实部变为25.5，而虚部为0。**但是，编译器并不知道这个转换规则，这超出了编译器的处理能力，所以转换失败，即使加上强制类型转换也无用**。幸运的是，C++允许我们自定义类型转换规则，用户可以将其它类型转换为当前类类型，也可以将当前类类型转换为其它类型。**这种自定义的类型转换规则只能以类的成员函数的形式出现。换句话说，这种转换规则只适用于类**，本节先讲解如何将其它类型转换为当前类类型。
### 2.转换构造函数
- **将其它类型转换为当前类类型需要借助转换构造函数（Conversion constructor）。转换构造函数也是一种构造函数，它遵循构造函数的一般规则,转换构造函数只有一个参数**。
    ```
        #include "iostream"

        using namespace std;

        /*---------------------------将其它类型转换为当前类的类型-------------------------------*/

        // 如果编译器不知道转换规则就不能转换，使用强制类型也无用
        class complex{
            public:
                complex():m_real(0.0), m_img(0.0){}
                complex(double real, double img):m_real(real), m_img(img){}
                complex(double real): m_real(real), m_img(0.0){}  // 转换构造函数,作用是将double类型的参数real转换成 complex类的对象，并将real作为复数的实部，将0作为复数的虚部
            public:
                friend ostream & operator<< (ostream &out, const complex &c); // 友元函数
            private:
                double m_real;
                double m_img;
        };

        ostream & operator << (ostream &out, const complex &c){
            out << c.m_real << " + " << c.m_img << "i";
            return out;
        }

        int main(){
            complex a(10.0, 20.0);
            cout << "a = " << a << endl;
            a = 25.5;  // 将赋值的过程转换成了函数调用的过程
            cout << "a = " << a << endl;
            return 0;
        }
    ```
- 转换构造函数也是构造函数的一种，它除了可以用来将其它类型转换为当前类类型，还可以用来初始化对象，这是构造函数本来的意义。下面创建对象的方式是正确的：
    ```
        complex c1(23.1);  // 创建具名对象
        complex c2 = 24.3;  // 以拷贝的方式初始化对象,编译器先调用转换构造函数，将24.3转换为complex类型（创建一个complex类的匿名对象），然后再拷贝给c2。
        complex(3.21);  // 创建匿名对象
        c1 = complex(34.2);  // 创建一个匿名对象并将它赋值给 c1
    ```
- 如果已经对+运算符进行了重载，使之能进行两个complex类对象的相加，那么下面的语句也是正确的：
    ```
        complex c1(15.6, 89.9);
        complex c2;
        c2 = c1 + 29.6;
        cout << c2 << endl;
    ```
- 注意:**为了获得目标类型，编译器会“不择手段”，会综合使用内置的转换规则和用户自定义的转换规则，并且会进行多级类型转换**，例如：
    - 编译器会根据内置规则先将int转换为double，再根据用户自定义规则将double转换为complex（int --> double --> complex）;
    - 编译器会根据内置规则先将char转换为int，再将int转换为double，最后根据用户自定义规则将double转换为complex（char --> int --> double --> complex）
        ```
            int main(){
                complex c1 = 100;  //int --> double --> complex
                cout << c1 << endl;
                c1 = 'A';  //char --> int --> double --> complex
                cout << c1 << endl;
                c1 = true;  //bool --> int --> double --> complex
                cout << c1 << endl;
                complex c2(25.8, 0.7);
                //假设已经重载了+运算符
                c1 = c2 + 'H' + true + 15;  //将char、bool、int都转换为complex类型再运算
                cout << c1 << endl;
                return 0;
            }
        ```
### 3.再谈构造函数
- 构造函数的本意是在创建对象的时候初始化对象，编译器会根据传递的实参来匹配不同的（重载的）构造函数,几种形式的构造函数:
    - 默认构造函数: 就是编译器自动生成的构造函数,以complex类为例，它的原型为：
        ```
            complex();  // 没参数
        ```
    - 普通构造函数: 就是用户自定义的构造函数,以complex类为例，它的原型为：
        ```
            complex(double real, double img);  // 两个参数
        ```
    - 拷贝构造函数: 在以拷贝的方式初始化对象时调用,以complex类为例，它的原型为：
        ```
            complex(const complex &c);
        ```
    - 转换构造函数: 将其它类型转换为当前类类型时调用,以complex为例，它的原型为：
        ```
            complex(double real);  // 一个参数
        ```
- 不管哪一种构造函数，都能够用来初始化对象，这是构造函数的本意。假设complex类定义了以上所有的构造函数，那么下面创建对象的方式都是正确的：
    ```
        complex c1();  // 调用complex()
        complex c2(10, 20);  // 调用complex(double real, double imag)
        complex c3(c2);  // 调用complex(const complex &c)
        complex c4(25.7);  // 调用complex(double real)
    ```
- 除了在创建对象时初始化对象，其他情况下也会调用构造函数，例如:以拷贝的的方式初始化对象时会调用拷贝构造函数，将其它类型转换为当前类类型时会调用转换构造函数。这些在其他情况下调用的构造函数，就成了特殊的构造函数了。特殊的构造函数并不一定能体现出构造函数的本意。
### 4.对complex类的进一步精简
- 上面的complex类中我们定义了三个构造函数，其中包括两个普通的构造函数和一个转换构造函数。**其实，借助函数的默认参数，我们可以将这三个构造函数简化为一个**，请看下面的代码：
    ```
        #include "iostream"

        using namespace std;

        /*---------------------------将其它类型转换为当前类的类型-------------------------------*/

        // 如果编译器不知道转换规则就不能转换，使用强制类型也无用
        class complex{
            public:
                complex(double real=0.0, double img=0.0):m_real(real), m_img(img){}
            public:
                friend ostream & operator<< (ostream &out, const complex &c); // 友元函数
            private:
                double m_real;
                double m_img;
        };

        ostream & operator << (ostream &out, const complex &c){
            out << c.m_real << " + " << c.m_img << "i";
            return out;
        }

        int main(){
            complex a(10.0, 20.0);  // 向构造函数传递2个实参，不使用默认参数
            cout << "a = " << a << endl;
            complex b(89.5);  // 向构造函数传递1个实参，使用1个默认参数
            cout << "b = " << b << endl;
            complex c;  // 不向构造函数传递实参，使用全部默认参数
            a = 25.5;  // 调用转换构造函数（向构造函数传递1个实参，使用1个默认参数）
            cout << "a = " << a << endl;
            return 0;
        }
    ```