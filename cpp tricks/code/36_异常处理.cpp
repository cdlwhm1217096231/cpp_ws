#include "iostream"
#include "exception"
#include "string"

using namespace std;


double division(int a, int b){
    if(b == 0)
        throw "Division by zero condition!";
    return (a / b);
}


// 自定义新的异常
struct myException: public exception{
    const char * what() const throw(){  // what()是异常类提供的一个公共方法，它已被所有子异常类重载,这将返回异常产生的原因。
        return "C++ Exception!";
    }
};

// 基类
class MyException{
    public:
        MyException(const char * msg): message(msg){
            cout << "构造函数MyException类的对象.....\n";
        }
        MyException(const MyException &other): message(other.message){
            cout << "拷贝构造函数MyException类的对象......\n";
        }
        // 析构函数
        virtual ~MyException(){
            cout << "~MyException.....\n";
        }

        const char *what() const{
            return message.c_str();
        }
    private:
        string message;
};
// 派生类
class MyExceptionD: public MyException{
    public:
        MyExceptionD(const char *message): MyException(message){
            cout << "构造函数MyExceptionD类的对象......\n";
        }
        MyExceptionD(const MyExceptionD & other): MyException(other){
            cout << "拷贝构造函数MyExceptionD类的对象......\n";
        }
        // 析构函数
        ~MyExceptionD(){
            cout << "~MyExceptionD......\n";
        }
};

void fun(int n) throw(int,  MyException, MyExceptionD){
    if(n == 1)
        throw 1;
    else if(n == 2)
        throw MyException("Test Exception......");
    else if(n == 3)
        throw MyExceptionD("Test MyExceptionD......");
}   

void fun2() throw(){

}

int main(){
    int a = 3;
    int b = 0;
    double z = 0;
    // cout << "division(3, 0) = " << division(a, b) << endl;
    cout << "-------------------------------------------------\n";
    try{
        z = division(3, 0);
    }catch(const char* msg){  // 常指针，等价于 char const *msg;
        cerr << msg << endl;
    }
    cout << "-------------------------------------------------\n";
    try{
        throw myException();
    }catch(myException &e){
        cout << "myException caught: ";
        cout << e.what() << endl; 
    }
    cout << "-------------------------------------------------\n";
    try{
        fun(2);
    }catch(int n){
        cout << "catch int......\n";
        cout << "n = " << n << endl;
    }catch(MyExceptionD &e){
        cout << "catch MyExceptionD......\n";
        cout << e.what() << endl;
    }catch(MyException &e){
        cout << "catch MyException......\n";
        cout << e.what() << endl;
    }
    return 0;
}