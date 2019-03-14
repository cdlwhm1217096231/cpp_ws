#include "iostream"

using namespace std;


// static存储类实例
static int count = 10;  // 静态全局变量
void fun(void);

class Data{
public:
    Data(){}
    ~Data(){}
    void show(){
        cout << this->data << " " << number << endl;
    }

    static void showData(){  // 先于类的对象而存在
        cout << " " << number << endl;  // 这个方法调用的时候不包含this指针
    }
private:
    int data;
public:
    static int number;  //  静态数据在声明时候类外初始化
};


class Foo{
public:
    Foo(): i(100){}
private:
    // const int i = 10;  // 错误!!!   const修饰成员变量, const 修饰的成员变量不能被修改
    int i;
};
// Foo::Foo():i(100){} 或者通过这样的方式来进行初始化

int Data::number = 0;  // 静态成员初始化

int main(){
    // static存储类
    while(count--){
        fun();
    }
    // 静态成员变量举例
    Data::showData(); // 通过类名直接调用

    Data::number = 100; // 通过类名直接调用

    Data d;
    d.show();
    d.showData();   // 通过对象调用

    cout << "hello world..." << endl; 
    
    return 0;
}

void fun(void){
    static int i = 5;   // 静态局部变量
    i++;
    cout << "变量i为：" << i << endl;
    cout << "变量count为: " << count << endl;
}