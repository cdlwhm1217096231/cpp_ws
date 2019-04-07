### 1.Cpp中的模板template
- **模板是泛型编程的基础，泛型编程即以一种独立于任何特定类型的方式编写代码。模板是创建泛型类或函数的蓝图或公式**。库容器，比如迭代器和算法都是泛型编程的例子，它们都使用了模板的概念。每个容器都有一个单一的定义，比如向量vector可以定义许多不同类型的向量，如vector <int>或vector <string>。
### 2.函数模板
- 函数模板定义的一般形式如下:
    ```
        template <typename 类型参数1, typename 类型参数2,...> 返回值类型 函数名(形参列表){
            // 在函数体中可以使用累成参数
        }
    ```
    - typename: 一个关键字，用来声明具体的类型参数。**typename关键字也可以使用class关键字替代，它们没有任何区别**。C++早期对模板的支持并不严谨，没有引入新的关键字，而是用 class来指明类型参数，但是class关键字本来已经用在类的定义中了，这样做显得不太友好，**所以后来C++又引入了一个新的关键字 typename，专门用来定义类型参数**。不过至今仍然有很多代码在使用class关键字，包括C++标准库、一些开源程序等。
    - template: 是定义函数模板的关键字，后面紧跟尖括号<>
    - **类型参数(也可以说是虚拟的类型，或者说是类型占位符)**: 模板头中包含的**类型参数**可以用在函数定义的各个位置，包括返回值、形参列表和函数体。类型参数的命名规则跟其他标识符的命名规则一样，不过使用T、T1、T2、Type等已经成为了一种惯例。
    - template<typename T>: 模板头
- 函数模板实例1如下:
    ```
        #include <iostream>
        
        using namespace std;

        // 函数模板
        template<typename T> void Swap(T &a, T &b){  // 此处的tyname关键字可以改成class！
            T temp;
            temp = a;
            a = b;
            b = temp;
        }

        int main(){
            // int类型变量交换
            int n1 = 200, n2 = 100;
            Swap(n1, n2);
            cout << "n1 = " << n1 << ", n2 = " << n2 << endl;
            // float类型变量交换
            float f1 = 3.14, f2 = 5.99;
            Swap(f1, f2);
            cout << "f1 = " << f1 << ", f2 = " << f2 << endl;
            return 0;
        }
    ```
- 函数模板实例2如下：
    ```
        #include <iostream>


        using namespace std;

        // 函数模板的声明
        template<class T> T max(T a, T b, T c);

        int main(){
            // 求三个整数的最大值
            int i1, i2, i3, i_max;
            cout << "请依次输入三个整数: \n";
            cin >> i1 >> i2 >> i3;
            i_max = max(i1, i2, i3);
            cout << "i_max = " << i_max << endl;
            cout << "----------------------------------------------\n";
            // 求三个浮点数的最大值
            double d1, d2, d3, d_max;
            cout << "请依次输入三个浮点数: \n";
            cin >> d1 >> d2 >> d3;
            d_max = max(d1, d2, d3);
            cout << "d_max = " << d_max << endl;
            cout << "----------------------------------------------\n";
            return 0;
        }

        // 定义函数模板
        template<class T>   // 模板头，不能有分号
        T max(T a, T b, T c){  // 函数头
            T max_num = a;
            if( b > max_num)
                max_num = b;
            if(c > max_num)
                max_num = c;
            return max_num;
        }
    ```
- 函数模板实例3如下：
    ```
        #include <iostream>
        #include "string"

        using namespace std;


        // 函数模板实例3
        template<class T> inline T const& Max(T const &a, T const &b){
            return a < b ? b:a;
        }


        int main(){
            int i = 20, j = 30;
            cout << "Max(i, j) = " << Max(i, j) << endl;

            double db1 = 23.4, db2 = 44.9;
            cout << "Max(db1, db2) = " << Max(db1, db2) << endl;

            string s1 = "hello", s2 = "world";
            cout << "Max(s1, s2) = " << Max(s1, s2) << endl;
            return 0;
        }
    ```
### 3.类模板
- C++除了支持函数模板，还支持类模板（Class Template）。函数模板中定义的类型参数可以用在函数声明和函数定义中，**类模板中定义的类型参数可以用在类声明和类实现中,类模板的目的同样是将数据的类型参数化**。一但声明了类模板，就可以将类型参数用于类的成员函数和成员变量了。换句话说，原来使用int、float、char等内置类型的地方，都可以用类型参数来代替。
- 声明类模板的语法为:
    ```
        template <typename 类型参数1, typename 类型参数2,...> class 类名{
            //TODO;
        }
    ```
- 类模板中类的声明如下：
    ```
        template<typename T1, typename T2>  // 这里不能有分号！！！
        class Point{
            public:
                Point(T1 x, T2 y): m_x(x), m_y(y){
                    cout << "构造函数\n";
                }
            public:
                T1 getX() const;  // 常函数
                void setX(T1 x);  
                T2 getY() const;
                void setY(T2 y);
            private:
                T1 m_x;
                T2 m_y;
        };
    ```
- 上面的代码仅仅是类的声明，我们还需要在类外定义成员函数。**在类外定义成员函数时仍然需要带上模板头**，格式为：
    ```
        template<typename 类型参数1, typename 类型参数2,...> 返回值类型 类名<类型参数1, 类型参数2,...>::函数名(形参列表){
            TODO;
        }
    ```
- 类模板中的成员函数定义如下:
    ```
        // 类外成员函数的定义
        template<typename T1, typename T2>  // 模板头
        T1 Point<T1, T2>::getX() const{  // 函数头
            return m_x;
        } 

        template<typename T1, typename T2>
        void Point<T1, T2>::setX(T1 x){
            m_x = x;
        }

        template<typename T1, typename T2>
        T2 Point<T1, T2>::getY() const{
            return m_y;
        }

        template<typename T1, typename T2>
        void Point<T1, T2>::setY(T2 y){
            m_y = y;
        }
    ```
    - 仔细观察代码，除了 template 关键字后面要指明类型参数，类名Point后面也要带上类型参数，只是不加typename关键字了。另外需要注意的是，在类外定义成员函数时，template后面的类型参数要和类声明时的一致。
### 4.使用类模板创建对象
- 上面的两段代码完成了类的定义，接下来就可以使用该类创建对象了。使用类模板创建对象时，需要指明具体的数据类型。请看下面的代码：
    ```
        Point<int, int> p1(10, 20);
        Point<int, float> p2(10, 5.5);
        Point<float, char*> p3(4.3, "hello");
    ```
- **与函数模板不同的是，类模板在实例化时必须显式地指明数据类型，编译器不能根据给定的数据推演出数据类型**。
- 除了对象变量，我们也可以使用对象指针的方式来实例化：
    ```
        Point<float, float> *p1 = new Point<float, float>(10.6, 90.3);
        Point<char*, char*> *p2 = new Point<char*, char*>("hello", "world");
    ```
- **需要注意的是，赋值号两边都要指明具体的数据类型，且要保持一致**。下面的写法是错误的：
    ```
        // 赋值号两边的数据类型不一致
        Point<float, float> *p = new Point<float, int>(10.6, 109);
        // 赋值号右边没有指明数据类型
        Point<float, float> *p = new Point(10.6, 109);
    ```
- 综合实例1如下:
    ```
        #include <iostream>
        using namespace std;

        template<class T1, class T2>  //这里不能有分号
        class Point{
        public:
            Point(T1 x, T2 y): m_x(x), m_y(y){ }
        public:
            T1 getX() const;  //获取x坐标
            void setX(T1 x);  //设置x坐标
            T2 getY() const;  //获取y坐标
            void setY(T2 y);  //设置y坐标
        private:
            T1 m_x;  //x坐标
            T2 m_y;  //y坐标
        };

        template<class T1, class T2>  //模板头
        T1 Point<T1, T2>::getX() const /*函数头*/ {
            return m_x;
        }

        template<class T1, class T2>
        void Point<T1, T2>::setX(T1 x){
            m_x = x;
        }

        template<class T1, class T2>
        T2 Point<T1, T2>::getY() const{
            return m_y;
        }

        template<class T1, class T2>
        void Point<T1, T2>::setY(T2 y){
            m_y = y;
        }

        int main(){
            Point<int, int> p1(10, 20);
            cout<<"x="<<p1.getX()<<", y="<<p1.getY()<<endl;
        
            Point<int, char*> p2(10, "东经180度");
            cout<<"x="<<p2.getX()<<", y="<<p2.getY()<<endl;
        
            Point<char*, char*> *p3 = new Point<char*, char*>("东经180度", "北纬210度");
            cout<<"x="<<p3->getX()<<", y="<<p3->getY()<<endl;

            return 0;
        }
    ```
- 类模板综合实例2如下：
    ```
        template <class T>
        class CArray
        {
        private:
            int size; // 数组的大小
            T *ptr;   // 指向动态数组的指针
        public:
            CArray(int s = 0); // 构造函数
            CArray(CArray &a); // 拷贝构造函数
            ~CArray();         // 析构函数

            void push_back(const T &v);         //用于在数组的尾部添加一个元素
            CArray &operator=(const CArray &a); // 运算符重载，用于数组对象间的重载
            // 注意下面的两个函数已经定义过了
            T length()
            {
                return size;
            }

            T &operator[](int i)
            {
                return ptr[i]; // 用以支持根据下标访问数组元素
            }
        };
        // 类成员函数的定义
        template <class T>
        CArray<T>::CArray(int s) : size(s)
        {
            if (s == 0)
                ptr = NULL;
            else
                ptr = new T[s];
        }

        template <class T>
        CArray<T>::CArray(CArray &a)
        {
            if (!a.ptr)
            {
                ptr = NULL;
                size = 0;
                return;
            }
            ptr = new T[a.size];
            memcpy(ptr, a, ptr, sizeof(T) * a.size);
            size = a.size;
        }

        template<class T>
        CArray<T>::~CArray(){
            if(ptr)
                delete [] ptr;
        }

        template <class T>
        CArray<T> &CArray<T>::operator=(const CArray &a)
        {
            if (this == &a) //防止a=a这样的赋值导致出错, 赋值号的作用是使"="左边对象里存放的数组，大小和内容都和右边的对象一样
                return *this;
            if (a.ptr == NULL)
            { // 如果a里面的数组是空的
                if (ptr)
                    delete[] ptr;
                ptr = NULL;
                size = 0;
                return *this;
            }
            if (size < a.size)
            { // 如果原有空间够大，就不用分配新的空间
                if (ptr)
                    delete[] ptr;
                ptr = new T[a.size];
            }
            memcpy(ptr, a.ptr, sizeof(T) * a.size);
            return *this;
        }

        template <class T>
        void CArray<T>::push_back(const T &v)
        { //在数组尾部添加一个元素
            if (ptr)
            {
                T *tmpPtr = new T[size + 1];           // 重新分配空间
                memcpy(tmpPtr, ptr, sizeof(T) * size); // 拷贝原数组内容
                delete[] ptr;
                ptr = tmpPtr;
            }
            else // 数组本来是空的
                ptr = new T[1];
            ptr[size++] = v; // 加入新的数组元素
        }

        int main()
        {
            CArray<int> a;
            for(int i =0; i < 5;i++)
                a.push_back(i);
            for(int i=0; i < a.length(); i++)
                cout << "a[" << i << "] = " << a[i] << endl;
            return 0;
        }
    ```