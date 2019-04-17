### 1.拷贝控制操作(三五法则)
- 当定义一个类时，我们显式地或隐式地指定了此类型的对象在拷贝、赋值和销毁时做什么。一个类通过定义三种特殊的成员函数来控制这些操作，分别是拷贝构造函数、赋值运算符和析构函数。
- **拷贝构造函数定义了当用同类型的另一个对象初始化新对象时做什么，赋值运算符定义了将一个对象赋予同类型的另一个对象时做什么，析构函数定义了此类型的对象销毁时做什么。我们将这些操作称为拷贝控制操作**。
- 由于拷贝控制操作是由三个特殊的成员函数来完成的，所以我们称此为“C++三法则”。在较新的C++11标准中，为了支持移动语义，又增加了移动构造函数和移动赋值运算符，这样共有五个特殊的成员函数，所以又称为“C++五法则”。也就是说，“三法则”是针对较旧的C++89标准说的，“五法则”是针对较新的C++11标准说的。为了统一称呼，后来人们干把它叫做“C++ 三/五法则”。
### 2.实例如下:
    ```
        #include "iostream"
        #include "cstdlib"
        #include "cstring"

        using namespace std;



        class Array{
            public:
                Array(int len);
                Array(const Array &arr);   // 拷贝构造函数
                ~Array();
            public:
                int operator[](int i) const {return m_p[i];}  // 以常成员函数(只读)形式重载[]运算符
                int & operator[](int i) {return m_p[i];}  // 获取元素(写入)
                Array & operator=(const Array &arr);  // 重载赋值运算符！！！operator=()的形参类型是const Array &,这样不但能够避免在传参时调用拷贝构造函数，还能够同时接收const类型和非const类型的实参
                int length() const {return m_len;}
                void show();
            private:
                int m_len;
                int *m_p;
        };
        // 构造函数的定义
        Array::Array(int len):m_len(len){
            m_p = (int *)calloc(len, sizeof(int));  // 动态分配内存空间，使得指针m_p指向新分配的内存空间
        }
        // 拷贝构造函数的定义
        Array::Array(const Array &arr){
            this->m_len = arr.m_len;
            this->m_p = (int *)calloc(this->m_len, sizeof(int));
            memcpy( this->m_p, arr.m_p, m_len * sizeof(int));
        }

        Array::~Array(){
            free(m_p);
        }
        // 重载赋值运算符
        Array & Array::operator=(const Array &arr){ // operator=()的返回值类型是Array &,这样不但能够避免在返回数据时调用拷贝构造函数，还能够达到连续赋值的目的
            if(this != &arr){  // 判断是否是给同一个对象赋值
                this->m_len = arr.m_len;
                free(this->m_p);
                this->m_p = (int*)calloc(this->m_len, sizeof(int));
                memcpy(this->m_p, arr.m_p, m_len * sizeof(int));
            }
            return *this;  // 表示返回当前对象
        }

        // 普通成员函数的定义
        void Array::show(){
            cout << "我是普通成员函数....\n";
        }

        // 打印数组元素
        void printArray(const Array &arr){
            int len = arr.length();
            for(int i=0; i<len; i++){
                if(i == len-1){
                    cout<<arr[i]<<endl;
                }else{
                    cout<<arr[i]<<", ";
                }
            }
        }
        int main(){
            Array arr1(10);
            for(int i=0; i<10; i++){
                arr1[i] = i;
            }
            cout << "arr1:";
            printArray(arr1);
        
            Array arr2(5);
            for(int i=0; i<5; i++){
                arr2[i] = i;
            }
            cout << "arr2:";
            printArray(arr2);
            cout << "------------------------------------\n";
            arr2 = arr1;  // 调用operator=()
            cout << "将arr1赋值给arr2:";
            printArray(arr2);
            arr2[3] = 234;  // 修改arr2的数据不会影响arr1,如果把operator=()注释掉,修改arr2的值就会影响arr1的值
            arr2[7] = 920;
            cout << "修改arr2的值不会影响arr1:";
            printArray(arr1);
            return 0;
        }
    ```
### 3.参考博客
- [博客链接](https://www.cnblogs.com/yongdaimi/p/7121151.html)