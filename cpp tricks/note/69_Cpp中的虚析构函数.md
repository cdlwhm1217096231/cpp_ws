### Cpp中的虚析构函数
- 1.虚析构函数的作用：为了避免内存泄漏，**而且是当子类中会有指针成员变量时才会使用到。**即**虚析构函数使得在删除指向子类对象的基类指针时，可以调用子类的析构函数来实现释放子类中堆内存的目的，从而防止内存泄漏。**
- 2.C++中开发中，基类中的析构函数一般都是虚函数，如下面的例子：
    ```
        #include <iostream>

        using namespace std;

        // 基类
        class Base{
            public:
                Base(){};
                virtual ~Base(){  // 基类的析构函数是虚函数！
                    cout << "delete Base\n";
                };
                virtual void DoSomething(){
                    cout << "Do Something in class Base!\n";
                };
        };


        // 派生类
        class Derived: public Base{
            public:
                Derived(){};
                ~Derived(){
                    cout << "delete Derived\n";
                };
                void DoSomething(){
                    cout << "Do Something in Derived\n";
                };
        };


        int main(){
            Base *b = new Derived;
            b->DoSomething();  // 重写DoSomething函数
            delete b;
            return 0;
        }
    ```

- 3.如果把基类Base中的虚析构函数改成普通析构函数，结果如下所示。也就是说，派生类Derived中的析构函数压根就没有被调用！一般来说，类的析构函数用来释放内存中的资源，当析构函数没有被调用的话，就会造成内存泄漏。

- 4.虚析构函数作用总结：
    - (a) 如果基类的析构函数不加virtual关键字，那么就是普通析构函数
        - 当基类中的析构函数没有声明为虚析构函数时，派生类开始从基类继承，基类的指针指向派生类的对象时，delete基类的指针时，只会调用基类的析构函数，不会调用派生类的析构函数。
    - (b) 如果基类的析构函数加virtual关键字，那么就是虚析构函数
        - 当基类中的析构函数声明为虚析构函数时，派生类开始从基类继承，基类的指针指向派生类的对象时，delete基类的指针时，先调用派生类的析构函数，再调用基类中的析构函数。
