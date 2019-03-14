### 1.Cpp修饰符类型
- C++允许在char、int 和double数据类型前放置修饰符。修饰符用于改变基本类型的含义，所以它更能满足各种情境的需求。下面列出了数据类型修饰符：
    - signed
    - unsigned
    - long
    - short
- 修饰符signed、unsigned、long 和 short 可应用于整型；signed和unsigned可应用于字符型，long可应用于双精度型；修饰符signed和unsigned也可以作为long或short修饰符的前缀。例如：unsigned long int
- C++允许使用速记符号来声明无符号短整数或无符号长整数。可以不写int，只写单词unsigned、short或 unsigned、long,int是隐含的。例如，下面的两个语句都声明了无符号整型变量：
```
unsigned int x;
unsigned y;
```
- 为了理解 C++ 解释有符号整数和无符号整数修饰符之间的差别，我们来运行一下下面这个短程序：
```
int main(){
    short int i;  // 有符号短整型
    short unsigned int j;  // 无符号短整型
    j = 50000;
    i = j;
    cout << i << " " << j << endl;
    return 0;
}
```
- 对于无符号化为有符号的位数运算，采取 N-2^n 的计算方法，n 取决于定义的数据类型 int、short、char、long int 等等，N 为无符号数的数值，例如文中的 N=5000，short 为 16 位，计算方法为 5000-2^16 得到 -15536。
### 2.Cpp中的类型限定符
- 类型限定符提供了变量的额外信息,见下表:
![Cpp中的类型限定符.png](https://upload-images.jianshu.io/upload_images/13407176-fb657ee74609d85e.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)
### 3.Cpp中的关键字explicit介绍
- 声明为explicit的构造函数不能在隐式转换中使用。C++中，一个参数的构造函数(或者除了第一个参数外其余参数都有默认值的多参构造函数)，承担了两个角色。一、是个构造器；二、是个默认且隐含的类型转换操作符。所以，有时候在我们写下如 AAA = XXX这样的代码时，且恰好XXX的类型正好是AAA单参数构造器的参数类型，这时候编译器就自动调用这个构造器，创建一个AAA的对象。
```
class Test1
{
public:
    Test1(int n)
    {
        num=n;
    }//普通构造函数
private:
    int num;
};
class Test2
{
public:
    explicit Test2(int n)
    {
        num=n;
    }//explicit(显式)构造函数
private:
    int num;
};
int main()
{
    Test1 t1=12;//隐式调用其构造函数,成功
    Test2 t2=12;//编译错误,不能隐式调用其构造函数
    Test2 t2(12);//显式调用成功
    return 0;
}
```
- volatile 往往会用于多线程的修饰，比如：
```
volatile boolean isNext = false;

Thread A（） {
    // 第一个工作
    // isNext = true;
}

Thread B （）{
    if (isNext) {
        // 第二个工作
    }
}
```
