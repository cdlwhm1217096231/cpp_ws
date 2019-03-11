#include "iostream"

using namespace std;

void swap_by_value(int a, int b);
void swap_by_pointer(int *p1, int *p2);
void swap_by_reference(int &a, int &b);
/*
C++的函数参数传递方式，可以是传值方式，也可以是传引用方式。
传值的本质是：形参是实参的一份复制。
传引用的本质是：形参和实参是同一个东西。
传值和传引用，对大多数常见类型都是适用的。指针、数组，它们都是数据类型的一种，没啥特殊的
因此,指针作为函数参数传递时，也区分为传值和传引用两种方式。
```
void fun_1(int a); int类型，传值(复制产生新的变量)
void fun_2(int &a); int类型，传引用(形参和实参是同一个东西)
void fun_3(int *pi); 指针类型，传值(复制产生新的变量)
void fun_4(int *&pi); 指针类型，传引用(形参和实参是同一个东西)
```
如果希望通过将参数传递到函数中，从而来改变变量的值（比如变量是T a，T表示类型)，
则可以有这2种方式选择：
    1.传a的引用： void my_fun(T &a);
    2.传a的地址： void my_fun(T *a);
*/

// 一、值传递
/*
形参意思是被调用函数的参数/变量，实参意思是主调函数中放到括号中的参数/变量。
传值方式下，形参是实参的拷贝：重新建立了变量，变量取值和实参一样。
即实参a和b的值为20和10,形参x和y的值都是20和10；而a与x的地址、b与y的地址并不相同
表明形参x和y是新建的变量，也即实参a, b是从形参复制了一份
*/

int main(){
    int a = 20, b = 10;
    cout << "交换前: " << endl; 
    cout << "a = " << a << " ,b = " << b << endl;
    swap_by_value(a, b); // 值传递
    cout << "交换后: " << endl;
    cout << "a = " << a << " ,b = " << b << endl;
    /*-------------------------分界线1------------------*/
    cout << "交换前: " << endl; 
    cout << "a = " << a << " ,b = " << b << endl;
    swap_by_pointer(&a, &b); // 值传递
    cout << "交换后: " << endl;
    cout << "a = " << a << " ,b = " << b << endl;
    /*-------------------------分界线2------------------*/
    cout << "交换前: " << endl; 
    cout << "a = " << a << " ,b = " << b << endl;
    swap_by_reference(a, b); // 引用传递
    cout << "交换后: " << endl;
    cout << "a = " << a << " ,b = " << b << endl;
    return 0;
}


void swap_by_value(int x, int y){
    int temp;
    temp = x;
    x = y;
    y = temp;
}

// 二、传指针(地址),实质还是传值
void swap_by_pointer(int *p1, int *p2){
    int t;
    t = *p1;
    *p1 = *p2;
    *p2 = t;
}

// 三、传引用
/*
传引用，传递的是实参本身，而不是实参的一个拷贝，形参的修改就是实参的修改,即值相同，地址也相同
相比于传值，传引用的好处是省去了复制，节约了空间和时间。
假如不希望修改变量的值，那么请选择传值而不是传引用。
*/

void swap_by_reference(int &x, int &y){
    int temp;
    temp = x;
    x = y;
    y = temp;
}

// 四、总结
/*
“引用”类型变量的声明方式：变量类型 &变量名;   int &b;
“指针”类型的声明方式：基类型 *变量名;  int *pi;
“指针的引用类型”应当这样声明：基类型 *&变量名   int *&pi;
指针类型，也是有传值、传引用两种函数传参方式的：
    1.指针的传值方式
        void my_fun(int *a, int n);
    2.指针的传引用方式
        void my_fun(int *&pi, int n);

```
// 普通类型，以int a为例
void myfun(int a)    //传值，产生复制
void myfun(int &a)   //传引用，不产生复制
void myfun(int *a)   //传地址，产生复制，本质上是一种传值，这个值是地址
// 指针类型，以int *a为例
void myfun(int *a)   //传值，产生复制
void myfun(int *&a)  //传引用，不产生复制
void myfun(int **a)   //传地址，产生复制，本质上是一种传值，这个值是指针的地址
// 数组类型，以int a[10]为例
void myfun(int a[], int n) //传值，产生复制
void myfun(int* a, int n) //传值，产生复制，传递的数组首地址
void myfun(int (&arr)[10]) //传引用，不产生复制。需要硬编码数组长度
template<size_t size> void myfun(int (&arr)[size]) //传引用，不产生复制。不需要硬编码数组长度
```
*/