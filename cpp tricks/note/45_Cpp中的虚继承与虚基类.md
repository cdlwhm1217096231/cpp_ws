### 1.Cpp中的虚继承与虚基类
- 在多继承时，很容易产生命名冲突的问题，即使我们很小心地将所有类中的成员变量和成员函数都命名为不同的名字，命名冲突依然有可能发生，比如典型的是菱形继承，如下图所示：
![菱形继承.png](https://upload-images.jianshu.io/upload_images/13407176-7f51d7a2fbfa30f7.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)
- 类A派生出类B和类C，类D继承自类B和类C，这个时候类A中的成员变量和成员函数继承到类D中变成了两份，一份来自A-->B-->D这条路径，另一份来自A-->C-->D这条路径。在一个派生类中保留**间接基类的多份同名成员**，虽然可以在不同的成员变量中分别存放不同的数据，但大多数情况下这是多余的：因为保留多份成员变量不仅占用较多的存储空间，还容易产生命名冲突。假如类A有一个成员变量a，那么在类D中直接访问a 就会产生歧义，编译器不知道它究竟来自A -->B-->D这条路径，还是来自A-->C-->D这条路径。下面是菱形继承的具体实现：
    ```
        #include "iostream"

        using namespace std;

        // 间接基类
        class A
        {
        protected:
            int m_a;
        };
        // 直接基类B
        class B : public A
        {
        protected:
            int m_b;
        };

        // 直接基类C
        class C : public A
        {
        protected:
            int m_c;
        };

        // 派生类D
        class D : public B, public C
        {
        public:
            // void seta(int a) { m_a = a; }   命名冲突,为了解决命名冲突，可以使用void B::seta(int a){m_a = a;}
            void setb(int b) { m_b = b; }
            void setc(int c) { m_c = c; }

        private:
            int m_d;
        };

        int main()
        {
            D d;
            return 0;
        }
    ```
### 2.虚继承
- 为了解决多继承时的命名冲突和冗余数据问题，C++提出了虚继承，使得在派生类中只保留一份间接基类的成员。在继承方式前面加上virtual关键字就是虚继承，请看下面的例子：
    ```
        #include "iostream"

        using namespace std;

        // 间接基类
        class A
        {
        protected:
            int m_a;
        };
        // 直接基类B
        class B : virtual public A   // 加上关键字virtual!
        {
        protected:
            int m_b;
        };

        // 直接基类C
        class C : virtual public A
        {
        protected:
            int m_c;
        };

        // 派生类D
        class D : public B, public C
        {
        public:
            void seta(int a) { m_a = a; }   // 正确！
            void setb(int b) { m_b = b; }
            void setc(int c) { m_c = c; }

        private:
            int m_d;
        };

        int main()
        {
            D d;
            return 0;
        }
    ```
- 虚继承的目的是让某个类做出声明，承诺愿意共享它的基类。其中，这个被共享的基类就称为虚基类（Virtual Base Class），本例中的A就是一个虚基类。在这种机制下，不论虚基类在继承体系中出现了多少次，在派生类中都只包含一份虚基类的成员。重新梳理一下本例的继承关系，如下图所示：
![虚基类.png](https://upload-images.jianshu.io/upload_images/13407176-9fa90373110358a5.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)
- 观察这个新的继承体系，我们会发现虚继承的一个不太直观的特征：**必须在虚派生的真实需求出现前就已经完成虚派生的操作**。在上图中，当定义D类时才出现了对虚派生的需求，但是如果B类和C类不是从A类虚派生得到的，那么D类还是会保留A类的两份成员。**换个角度讲，虚派生只影响从指定了虚基类的派生类中进一步派生出来的类，它不会影响派生类本身**。
### 3.虚基类成员的可见性
- 因为在虚继承的最终派生类中只保留了一份虚基类的成员，所以该成员可以被直接访问，不会产生二义性。此外，如果虚基类的成员只被一条派生路径覆盖，那么仍然可以直接访问这个被覆盖的成员。但是如果该成员被两条或多条路径覆盖了，那就不能直接访问了，此时必须指明该成员属于哪个类。
- 以图2中的菱形继承为例，假设B定义了一个名为x的成员变量，当我们在D中直接访问x时，会有三种可能性：
    - 如果B和C中都没有x的定义，那么x将被解析为B的成员，此时不存在二义性。
    - 如果B或C其中的一个类定义了x，也不会有二义性，派生类的x比虚基类的x优先级更高。
    - 如果B和C中都定义了x，那么直接访问x将产生二义性问题。
### 4.虚继承时的构造函数
- 在虚继承中，虚基类是由最终的派生类初始化的。换句话说，最终派生类的构造函数必须要调用虚基类的构造函数。对最终的派生类来说，虚基类是间接基类，而不是直接基类。这跟普通继承不同，**在普通继承中，派生类构造函数中只能调用直接基类的构造函数，不能调用间接基类的**。
    ```
        // 虚基类AA
        class AA{
        protected:
            int m_a;
        public:
            AA(int a);
        };
        // 类外定义虚基类AA的构造函数
        AA::AA(int a):m_a(a){}
        // 直接派生类BB
        class BB: virtual public AA{
        protected:
            int m_b;
        public:
            BB(int a, int b);
            void show();
        };
        BB::BB(int a, int b): AA(a), m_b(b){}
        void BB::show(){
        cout << "m_a = " << m_a << ",m_b = " << m_b << endl;
        }

        // 直接派生类CC
        class CC: virtual public AA{
        public:
            CC(int a, int c);
            void show();
        protected:
            int m_c;
        };
        CC::CC(int a, int c):AA(a), m_c(c){}
        void CC::show(){
        cout << "m_a = " << m_a << ",m_c = " << m_c << endl;
        }

        // 间接派生类DD
        class DD: public BB, public CC{
        protected:
            int m_d;
        public:
            DD(int a, int b, int c, int d);
            void show();
        };
        DD::DD(int a, int b, int c, int d):AA(a), BB(90, b), CC(100, c), m_d(d){}
        void DD::show(){
        cout <<"m_a = " << m_a << ",m_b = " << m_b << ",m_c = " << m_c << ",m_d = " << m_d << endl;
        }

        int main()
        {
            BB bb(10, 20);
            bb.show();
            CC cc(30, 40);
            cc.show();
            DD dd(50, 60, 70, 80);
            dd.show();
            return 0;
        }
    ```
- 在最终派生类DD的构造函数中，除了调用BB和CC的构造函数，还调用了AA的构造函数，这说明DD不但要负责初始化直接基类BB和CC，还要负责初始化间接基类AA。而**在以往的普通继承中，派生类的构造函数只负责初始化它的直接基类，再由直接基类的构造函数初始化间接基类**，用户尝试调用间接基类的构造函数将导致错误。
- 现在采用了虚继承，虚基类AA在最终派生类DD中只保留了一份成员变量m_a，如果由BB和CC初始化m_a，那么BB和CC在调用AA的构造函数时很有可能给出不同的实参，这个时候编译器就会犯迷糊，不知道使用哪个实参初始化m_a。为了避免出现这种矛盾的情况，C++干脆规定必须由最终的派生类DD来初始化虚基类AA，直接派生类BB和CC对AA的构造函数的调用是无效的。在代码中，调用BB的构造函数时试图将m_a初始化为90，调用CC的构造函数时试图将m_a初始化为100，但是输出结果有力地证明了这些都是无效的，m_a最终被初始化为50，这正是在DD中直接调用AA的构造函数的结果。
- 另外,**需要关注的是构造函数的执行顺序**。虚继承时构造函数的执行顺序与普通继承时不同：在最终派生类的构造函数调用列表中，不管各个构造函数出现的顺序如何，编译器总是先调用虚基类的构造函数，再按照出现的顺序调用其他的构造函数；**而对于普通继承，就是按照构造函数出现的顺序依次调用的**。