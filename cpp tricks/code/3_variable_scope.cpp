#include "iostream"

using namespace std;

int func();  // 子函数声明
int func1();
int func2(int a, int b);
int func3();
// 全局变量的声明
int g = 233;
int count = 1;
int gg = 34;

int main(){
    // 局部变量声明，没有为其分配内存空间
    int a, b, kk;
    int c;
    int gg = 88;
    // 实际初始化
    a = 10;
    b = 20;
    c = a + b;
    cout << "c = " << c << endl;
    // 全局变量与局部变量同名时，局部变量会覆盖全局变量的值
    int g = 666;
    cout << "g = " << g << endl;
    //-----------------------------------------------------//
    // 在程序中，全局变量与局部变量的名称可以相同，但是在子函数内的局部变量与全局变量是两个独立的变量，互不影响
    kk = func();
    cout << "kk = " << kk << endl;
    // 在一个函数体内可以存在重名的变量，前提是它们的作用域不同
    int aa = 22;
    {
        int aa = 77;
        cout << "inner aa = " << aa << endl;
    }
    cout << "outer aa = " << aa << endl;
    // 全局变量的值可以在局部函数内重新赋值
    func1();
    func2(10, 20);
    func1();
    // 若要想让main函数也使用全局变量f，可以用 extern 对全局变量进行声明，就可以合法使用
    extern int f;
    cout << "f = " << f << endl;
    //  静态局部变量
    cout << "global " << "  local static" << endl;
    for(int i = 1; i <=10;++i)
        cout << i << "         " << func3() << endl;
    // 全局变量和和局部变量同名时，可通过域名在函数中引用到全局变量，不加域名解析则引用局部变量
    cout << "通过域名在函数中得到全局变量g的值: " << ::gg << endl;
    cout << "不加域名解析得到的是局部变量的值: " << gg << endl;
    return 0;
}


int func3(){
    static int count = 10;  
    // 在第一次进入这个函数的时候，变量count被初始化为10！并接着自减 1，以后每次进入该函数,count的值是上一次函数运行之后的值
    return count--;
    // 就不会被再次初始化了，仅进行自减 1 的操作；在 static 发明前，要达到同样的功能，则只能使用全局变量
}

int f = 10;  // 全局变量f从此处定义
// 子函数定义
int func(){
    return g;
}

int func1(){
    cout << "未改变前的全局变量, g = " << g << endl;
    return 0;
}

int func2(int a, int b){
    g = a + b;
    cout << "已改变后的全局变量, g = " << g << endl;
    return 0;
}