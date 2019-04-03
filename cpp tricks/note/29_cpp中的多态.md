### 1.Cpp中的多态
- 多态按字面的意思就是多种形态。当类之间存在层次结构，并且类之间是通过继承关联时，就会用到多态。**C++多态意味着调用成员函数时，会根据调用函数的对象的类型来执行不同的函数。**
- 多态的实例如下：
    ```
        #include "iostream"

        using namespace std;


        class Shape{
            protected:
                int width;
                int height;
            public:
                Shape(int a = 0, int b = 0): width(a), height(b){
                    cout << "基类Shape类的构造函数\n";
                }
                int area(){
                    cout << "基类Shape的area(): " << endl;
                    return 0;
                }
        };

        class Rect: public Shape{
            public:
                Rect(int a = 0, int b = 0): Shape(a,b){
                    cout << "派生类Rect的构造函数\n";
                }
                int area(){
                    cout << "派生类Rect的area(): " << endl;
                    return width * height;
                }
        };

        class Triangle: public Shape{
            public:
                Triangle(int a=0, int b=0): Shape(a, b){
                    cout << "派生类Triangle的构造函数\n";
                }
                int area(){
                    cout << "派生类Triangle的area(): " << endl;
                    return width * height / 2;
                }
        };

        int main(){
            Shape *shape;  // 指向类Shape的指针shape
            Rect r(10, 7);
            Triangle t(10, 5);

            shape = &r;  // 存储矩形的地址
            // 调用矩形的求面积函数
            shape->area();

            // 存储三角形的地址
            shape = &t;
            // 调用三角形的求面积函数
            shape->area();
            return 0;
        }
    ```
- 上面代码输出错误！原因是：调用函数area()被编译器设置为基类中的版本，这就是所谓的**静态多态或静态链接**：函数调用在程序执行前就准备好了。有时候这也被称为**早绑定**，因为area()成员函数在程序编译期间就已经设置好了。对上的代码进行修改，在Shape类中的成员函数area()的声明前放置关键字virtual,如下面所示：
    ```
        #include "iostream"

        using namespace std;


        class Shape{
            protected:
                int width;
                int height;
            public:
                Shape(int a = 0, int b = 0): width(a), height(b){
                    cout << "基类Shape类的构造函数\n";
                }
                virtual int area(){     // 此处已经修改，在area()函数的前面加上了virtual关键字！！！ 
                    cout << "基类Shape的area()" << endl;
                    return 0;
                }
        };

        class Rect: public Shape{
            public:
                Rect(int a = 0, int b = 0): width(a), height(b){
                    cout << "派生类Rect的构造函数\n";
                }
                int area(){
                    cout << "派生类Rect的area()" << endl;
                    return width * height;
                }
            protected:
                int width;
                int height;
        };

        class Triangle: public Shape{
            public:
                Triangle(int a=0, int b=0): Shape(a, b){
                    cout << "派生类Triangle的构造函数\n";
                }
                int area(){
                    cout << "派生类Triangle的area()" << endl;
                    return width * height / 2;
                }
        };

        int main(){
            Shape *shape;  // 指向类Shape的指针shape
            Rect r(10, 7);
            Triangle t(10, 5);

            shape = &r;  // 存储矩形的地址
            // 调用矩形的求面积函数
            shape->area();

            // 存储三角形的地址
            shape = &t;
            // 调用三角形的求面积函数
            shape->area();
            return 0;
        }
    ```
- 此时，编译器看的是指针的内容，而不是它的类型。因此，由于Rect和Triangle类的对象的地址存储在*shape中，所以会调用各自的成员函数area()。每个子类都有都有一个函数area()的独立实现，这就是多太的一般使用方式。**有了多态，可以有多个不同的类，这些不同的类都带有同一个名称但具有不同实现的函数，函数的参数甚至可以是相同的**。
### 2.虚函数
- **虚函数**是在基类中使用关键字virtual声明的函数。在派生类中重新定义基类中定义的虚函数时，会告诉编译器不要静态链接到基类中声明的成员函数。我们希望的是在程序中任意点可以根据所调用的对象类型来选择调用的函数，这种操作被称为**动态链接或后期绑定**。
- 虚函数声明如下：**virtual ReturnType FunctionName(Parameter)**虚函数必须实现，如果不实现，编译器将报错，错误提示为：
    ```
        error LNK****: unresolved external symbol "public: virtual void __thiscall ClassName::virtualFunctionName(void)"
    ```
- 对于虚函数来说，基类和派生类都有各自的版本方法来实现，由多态方式调用的时候动态绑定
- 虚函数是C++中用于实现多态(polymorphism)的机制，核心理念就是通过基类访问派生类定义的函数
- 在有动态分配堆上内存的时候，析构函数必须是虚函数，但没有必要是纯虚的
- 友元不是成员函数，只有成员函数才可以是虚函数，因此友元不能是虚函数。但是，可以通过让友元函数调用虚函数来解决友元的虚拟问题。
- 析构函数应当是虚函数，将调用相应对象类型的析构函数。因此，如果指针指向的是派生类对象，将调用派生类的析构函数，然后自动调用基类的析构函数。
- C++多态意味着调用成员函数时，会根据调用函数的对象的类型来执行不同的函数。形成多态必须具备三个条件：
    - 必须存在继承关系;
    - 继承关系必须有同名虚函数（其中虚函数是在基类中使用关键字Virtual声明的函数，在派生类中重新定义基类中定义的虚函数时，会告诉编译器不要静态链接到该函数）;
    - 存在基类类型的指针或者引用，通过该指针或引用调用虚函数
### 3.纯虚函数
- 我们希望在基类中定义虚函数，以便在派生类中重新定义该函数更好地适用于对象。但是，在基类中又不能对虚函数给出有意义的实现，这个时候就会用到纯虚函数。见下面的实例,将基类Shape中的虚函数area()改写成下面的样子。虚函数可以不实现（仅仅是定义）,不实现（仅仅是定义）的虚函数是纯虚函数。
    ```
        class Shape{
            protected:
                int width;
                int height;
            public:
                Shape(int a=0, int b=0):width(a), height(b){
                    cout << "基类Shape的构造函数\n";
                }
                // 纯虚函数，在基类中没有给出有意义的实现过程！！！
                virtual int area() = 0; // =0表示告诉编译器，函数没有主体，此函数的纯虚函数
        }
    ```
- 纯虚函数声明如下：**virtual void funtion1()=0;**,纯虚函数一定没有定义，纯虚函数用来规范派生类的行为，即接口。**包含纯虚函数的类是抽象类，抽象类不能定义实例对象，但可以声明指向实现该抽象类的具体类的指针或引用**。
- 实现了纯虚函数的派生类，该纯虚函数在派生类中就变成了虚函数，派生类的派生类即孙子类可以覆盖该虚函数，由多态方式调用的时候动态绑定。
- 在一个类中如果存在未定义的虚函数，那么不能直接使用该类的实例，可以理解因为未定义 virtual 函数，其类是抽象的，无法实例化。将报错误：
    ```
        undefined reference to `vtable for xxx'
    ```
- 这和其它语言的抽象类，抽象方法是类似的——我们必须实现抽象类，否则无法实例化,virtual和abstract还是有些区别的。也就是说，如果存在以下代码：
    ```
        // 在一个类中如果存在未定义的虚函数，那么不能直接使用该类的实例，可以理解因为未定义virtual函数，其类是抽象的，无法实例化。
        class Base {
            public:
                // virtual void tail();  虚函数没有定义，仅仅是声明而已
        };

        class People : public Base {
            public:
                void tail() {
                    cout << "people" << endl;
                }
        };
        // Base base;  因为Base类中有未定义的虚函数，所以不能直接使用该类的实例化对象，Base类是抽象的，无法实例化
        People people;
        people.tail();
        (&people)->tail();  // &people相当于是指向People类的指针
    ```
- 基类中的虚函数或纯虚函数在派生类中依然是虚函数。有时，我们并不希望基类的某个函数在派生类中被重写，在C++11及以后可以用关键字 final来避免该函数再次被重写。
    ```
        class Parent{
            public:
                virtual void fun(){
                    cout << "这个是基类\n";
                }
        };
        class Son: public Parent{
            public:
                void fun() final{  // 正确，fun在Parent中是虚函数
                    cout << "这是派生类\n";
                }
        };

        class Children: public Son{
            /*   不正确，fun在Son中已经不再是虚函数，不能再被重写
            public:
                void fun(){
                    cout << "这是派生类的派生类即孙子类Children\n";
                }
            */
        };
        Son s;
        Children c;
        Parent* parent;
        parent = &s;
        parent->fun();
        parent = &c;
        Son *son;
        son = &c;
        parent->fun();
        son->fun();
    ```
- 如果不希望一个类被继承，也可以使用final关键字,则该类将不能被继承。格式如下：
    ```
        class 类名 final{
            ......
        };
    ```