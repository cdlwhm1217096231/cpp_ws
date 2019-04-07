#include <iostream>
#include "string"
#include "cstring"

using namespace std;

// 函数模板
template <typename T>
void Swap(T &a, T &b)
{ // 此处的tyname关键字可以改成class！
    T temp;
    temp = a;
    a = b;
    b = temp;
}

// 函数模板的声明
template <class T>
T max(T a, T b, T c);

// 函数模板实例3
template <class T>
inline T const &Max(T const &a, T const &b)
{
    return a < b ? b : a;
}

// 类模板中类的声明
template <typename T1, typename T2> // 这里不能有分号！！！
class Point
{
  public:
    Point(T1 x, T2 y) : m_x(x), m_y(y)
    {
        cout << "构造函数\n";
    }

  public:
    T1 getX() const; // 常函数
    void setX(T1 x);
    T2 getY() const;
    void setY(T2 y);

  private:
    T1 m_x;
    T2 m_y;
};

// 类外成员函数的定义
template <typename T1, typename T2> // 模板头
T1 Point<T1, T2>::getX() const
{ // 函数头
    return m_x;
}

template <typename T1, typename T2>
void Point<T1, T2>::setX(T1 x)
{
    m_x = x;
}

template <typename T1, typename T2>
T2 Point<T1, T2>::getY() const
{
    return m_y;
}

template <typename T1, typename T2>
void Point<T1, T2>::setY(T2 y)
{
    m_y = y;
}

// 类模板综合实例2如下：
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
    // int类型变量交换
    int n1 = 200, n2 = 100;
    Swap(n1, n2);
    cout << "n1 = " << n1 << ", n2 = " << n2 << endl;
    // float类型变量交换
    float f1 = 3.14, f2 = 5.99;
    Swap(f1, f2);
    cout << "f1 = " << f1 << ", f2 = " << f2 << endl;
    cout << "----------------------------------------------\n";
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
    int i = 20, j = 30;
    cout << "Max(i, j) = " << Max(i, j) << endl;

    double db1 = 23.4, db2 = 44.9;
    cout << "Max(db1, db2) = " << Max(db1, db2) << endl;

    string s1 = "hello", s2 = "world";
    cout << "Max(s1, s2) = " << Max(s1, s2) << endl;
    cout << "----------------------------------------------\n";
    // 使用类模板创建对象
    Point<int, int> p1(10, 20);
    cout << "x = " << p1.getX() << ", y = " << p1.getY() << endl;
    cout << "----------------------------------------------\n";
    Point<int, char *> p2(10, "dana");
    cout << "x = " << p2.getX() << ", y = " << p2.getY() << endl;
    cout << "----------------------------------------------\n";
    Point<char *, char *> *p3 = new Point<char *, char *>("hello", "world");
    cout << "x = " << p3->getX() << ", y = " << p3->getY() << endl;
    cout << "----------------------------------------------\n";
    CArray<int> a;
    for(int i =0; i < 5;i++)
        a.push_back(i);
    for(int i=0; i < a.length(); i++)
        cout << "a[" << i << "] = " << a[i] << endl;
    return 0;
}

// 定义函数模板
template <class T> // 模板头，不能有分号
T max(T a, T b, T c)
{ // 函数头
    T max_num = a;
    if (b > max_num)
        max_num = b;
    if (c > max_num)
        max_num = c;
    return max_num;
}
