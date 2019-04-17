### 1.C++中类型转换函数:将当前类的类型转换为其它类型
- 转换构造函数能够将其它类型转换为当前类类型（例如将double类型转换为complex类型），但是不能反过来将当前类类型转换为其它类型（例如将complex类型转换为double 类型），C++提供了类型转换函数（Type conversion function）来解决这个问题。**类型转换函数的作用就是将当前类类型转换为其它类型，它只能以成员函数的形式出现，也就是只能出现在类中**。
- 类型转换函数的语法格式为:
    ```
        operator type(){  // type是目标类型
            // TODO;
            return data; // 返回的type类型的数据
        }
    ```
- 因为要转换的目标类型是type，所以返回值data也必须是type类型。**既然已经知道了要返回type类型的数据，所以没有必要再像普通函数一样明确地给出返回值类型。这样做导致的结果是：类型转换函数看起来没有返回值类型，其实是隐式地指明了返回值类型。类型转换函数也没有参数，因为要将当前类的对象转换为其它类型，所以参数不言而喻。实际上编译器会把当前对象的地址赋值给this指针**，这样在函数体内就可以操作当前对象了。
### 2.实例如下:
- 为complex类添加类型转换函数，使得complex类型能够转换为double类型，详细见下例:
    ```
        #include "iostream"

        using namespace std;

        /*--------------------将当前类的类型转换为其它类型-----------------------*/

        class complex{
            public:
                complex():m_real(0.0), m_img(0.0){}
                complex(double real, double img):m_real(real), m_img(img){}
            public:
                friend complex operator+ (const complex &c1, const complex &c2);
                friend ostream & operator<< (ostream &out, const complex &c);
                operator double() const{return m_real;}  // 类型转换函数(类型转换运算符)!!!，将complex类转化为double类型

            private:
                double m_real;
                double m_img;  
        };

        complex operator+ (const complex &c1, const complex &c2){
            complex c;
            c.m_real = c1.m_real + c2.m_real;
            c.m_img = c1.m_img + c2.m_img;
            return c;
        }

        ostream & operator<< (ostream &out, const complex &c){
            out << c.m_real << " + " << c.m_img << "i";
            return out;
        }


        int main(){
            complex c1(24.6, 100);
            double f = c1;
            cout << "f = " << f << endl;

            f = 12.5 + c1 + 6;
            cout << "f = " << f << endl;

            int n = complex(46.5, 9.4);
            cout << "n = " << n << endl;

            return 0;
        }
    ```
### 3.关于类型转换函数的说明
- type可以是内置类型、类类型以及由typedef定义的类型别名，任何可作为函数返回类型的类型（void 除外）都能够被支持。一般而言，不允许转换为数组或函数类型，转换为指针类型或引用类型是可以的;
- 类型转换函数一般不会更改被转换的对象，所以通常被定义为const成员;
- 类型转换函数可以被继承，可以是虚函数;
- 一个类虽然可以有多个类型转换函数（类似于函数重载），但是如果多个类型转换函数要转换的目标类型本身又可以相互转换（类型相近），那么有时候就会产生二义性。以complex类为例，假设它有两个类型转换函数：
    ```
        operator double() const{return m_real;}  // 转换为double类型
        operator int() const{return m_real;}  // 转换为int类型
        // 那么下面的写法就会引发二义性：
        complex c1(2.45, 3.45);
        float f = c1 + 12.5;
    ```
    