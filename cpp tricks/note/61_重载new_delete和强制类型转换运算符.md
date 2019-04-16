### 1.重载new和delete运算符
- 内存管理运算符new、new[]、delete和delete[]也可以进行重载，其重载形式既可以是类的成员函数，也可以是全局函数。一般情况下，内建的内存管理运算符就够用了，只有在需要自己管理内存时才会重载。
- 以成员函数的形式重载new运算符：
    ```
        void * className::operator new(size_t size){
            // TODO;
        }
    ```
- 以全局函数的形式重载new运算符：
    ```
        void * opetator new (size_t size){
            // TODO;
        }
    ```
- 两种重载形式的返回值相同，都是void *类型，并且都有一个参数，为size_t类型。在重载new或new[] 时，无论是作为成员函数还是作为全局函数，它的第一个参数必须是size_t类型。size_t表示的是要分配空间的大小，对于new[]的重载函数而言，size_t则表示所需要分配的所有空间的总和。**size_t在头文件\<cstdio\>中被定义为typedef unsigned int size_t;也就是无符号整型。当然，重载函数也可以有其他参数，但都必须有默认值，并且第一个参数的类型必须是size_t。**
- 同样的，delete 运算符也有两种重载形式。以类的成员函数的形式进行重载：
    ```
        void className::operator delete(void *ptr){
            // TODO;
        }
    ```
- 以全局函数的形式进行重载:
    ```
        void operator delete (void *ptr){
            // TODO;
        }
    ```
- 两种重载形式的返回值都是 void 类型，并且都必须有一个void类型的指针作为参数，该指针指向需要释放的内存空间。如果类中没有定义 new 和 delete 的重载函数，那么会自动调用内建的new和delete运算符。当以类的成员函数的形式重载了new和delete 操作符，其使用方法如下：
    ```
        C *c = new C;  // 分配内存空间
        // TODO;
        delete c;  // 释放内存空间
    ```
### 2.重载强制类型转化运算符()
- 在C++中，类型的名字（包括类的名字）本身也是一种运算符，即类型强制转换运算符。**类型强制转换运算符是单目运算符，也可以被重载，但只能重载为成员函数，不能重载为全局函数**。经过适当重载后，**(类型名)对象**这个对对象进行强制类型转换的表达式就等价于**对象.operator 类型名()**，即变成对运算符函数的调用。下面的程序对double类型强制转换运算符进行了重载:
    ```
        #include "iostream"

        using namespace std;


        // 强制类型转换运算符重载()
        class complex{
            public:
                complex(double real=0.0, double img=0.0):m_real(real), m_img(img){};
                operator double (){return m_real;}  // 重载强制类型转换运算符double
            
            private:
                double m_real;
                double m_img;
        };

        int main(){
            complex c(1.2, 3.4);
            cout << (double)c << endl;  // 输出 1.2
            double n = 2 + c;  // 等价于 double n = 2 + c. operator double()
            cout << n;  // 输出 3.2
            return 0;
        }
    ```
