#include "iostream"

using namespace std;


class Line{
    public:
        int getLength();
        Line(int len);  // 普通的构造函数
        Line(const Line &obj); // 拷贝构造函数
        ~Line();  // 析构函数
    private:
        int *ptr;
};
// 构造函数定义 
Line::Line(int len){
    cout << "调用构造函数..." << endl;
    ptr = new int;  // 为指针分配内存
    *ptr = len;
}
// 拷贝构造函数定义
Line::Line(const Line &obj){  // &obj是对象line的一个引用，用这个对象的引用来初始化另一个对象
    cout << "调用拷贝构造函数，并为指针ptr分配内存" << endl;
    ptr = new int;
    *ptr = *obj.ptr;  // 拷贝值
}
// 析构函数定义
Line::~Line(){
    cout << "释放内存\n";
    delete ptr;
}
// 普通成员函数定义
int Line::getLength(){
    return *ptr;
}

void display(Line obj){
    cout << "line大小: " << obj.getLength() << endl;
}

// 类的对象拷贝的简单例子
class C{
    private:    
        int a;
    public:
    // 构造函数
        C(int b): a(b){
            cout << "这是C的构造函数....\n";
        }
    // 拷贝构造函数:一种特殊的构造的函数，函数的名称必须与类名一样，它必须的一个参数是本类类型的一个引用变量
        C(const C &C_rename){
            a = C_rename.a;
            cout << "这是C的拷贝构造函数......\n";
        }
        // 一般的成员函数
        void show(){
            cout << "a = " << a << endl;
        }
};

// 1.对象以值传递的方式传入函数作为参数
class D{
    private:
        int a;
    public:
        // 构造函数
        D(int b): a(b){
            cout << "这是D的构造函数...\n";
        }
        // 拷贝构造函数
        D(const D& D_reference){
            a = D_reference.a;
            cout << "这是D拷贝构造函数...\n";
        }
        // 析构函数
        ~D(){
            cout << "这是D析构函数,删除a = " << a << endl;
        }  
        // 普通成员函数
        void show(){
            cout << "a = " << a << endl;
        }
};

// 全局函数，传入的函数参数是D的某个对象
void d_Fun(D d_obj){
    cout << "test D\n";
}

class E{
    private:
        int a;
    public:
        // 构造函数
        E(int b): a(b){
            cout << "这是E的构造函数\n";
        }
        // 拷贝构造函数
        E(const E& e_reference){
            a = e_reference.a;
            cout << "这是E的拷贝构造函数\n";
        }
        // 析构函数
        ~E(){
            cout << "这个是E的析构函数，删掉 a = " << a << endl;
        }
        // 普通成员函数
        void show(){
            cout << "a = " << a << endl;
        }
};

// 全局函数,函数的返回值是E的某个对象
E e_Fun(){
    E temp(20);
    return temp;
}

class Rect{
    public:
        Rect(){
            count++;
        }
        // 自定义拷贝构造函数
        Rect(const Rect& r){
            width = r.width;
            length = r.length;
            count++;
        }
        ~Rect(){
            count--;
        }
        static int getCount(){  // 静态成员函数
            return count;
        }
    private:
        int width;
        int length;
        static int count;  // 静态成员变量count来计数
};

// 静态成员变量初始化
int Rect::count = 0;

// 浅拷贝
class BB{
    public:
        BB(){  // 构造函数，p指向堆中分配的一空间
            p = new int(100);
            cout << "这是BB的构造函数\n";
        }
        ~BB(){  // 析构函数，释放动态分配的空间
            if(p!=NULL)
                delete p;
                cout << "这是BB的析构函数\n";
        }
    private:
        int width;
        int length;
        int *p;  // 指针成员
};
// 深拷贝
class DD{
    public:
        DD(){
            p = new int (100);
            cout << "这是DD的构造函数\n";
        }
        // 自定义默认拷贝构造函数
        DD (const DD& dd){
            width = dd.width;
            length = dd.length;
            p = new int;  // 为新对象重新动态分配空间
            *p = *(dd.p);
            cout << "这是DD的拷贝构造函数\n";
        }
        ~DD(){
            if (p!=NULL)
                delete p;
                cout << "这是DD的析构函数\n";
        }
    private:
        int width;
        int length;
        int *p;
};


// 防止默认拷贝的发生
class FF{
    private:
        int a;
    public:
        FF(int b): a(b){
            cout << "这是FF的构造函数\n";
        }
    private:
        FF(const FF& ff){
            a = ff.a;
            cout << "这是FF的拷贝构造函数\n";
        }
    public:
        ~FF(){
            cout << "这是FF的析构函数,删除a = " << a << endl;
        }
        // 普通成员函数
        void show(){
            cout << "a = " << a << endl;
        }
};

// 全局函数
void ff_fun(FF ff_param){
    cout << "test\n";
}

int main(){
    Line line(10);
    display(line);
    cout << "-------------------------------\n";
    Line line2 = line;  // 调用拷贝构造函数
    display(line2);
    cout << "-------------------------------\n";
    C c1_obj(666);
    C c2_obj = c1_obj; // 等价于C c2_obj(c1_obj);
    c2_obj.show();
    cout << "-------------------------------\n";
    D d_obj1(999);
    d_Fun(d_obj1);
    cout << "-------------------------------\n";
    e_Fun();
    cout << "-------------------------------\n";
    Rect rect1;
    cout << "The count of Rect: " << Rect::getCount() << endl;

    Rect rect2(rect1);  // 新的对象需要使用老的对象来进行初始化
    cout << "The count of Rect: " << Rect::getCount() << endl;
    cout << "-------------------------------\n";
    BB bb1;
    BB bb2 = bb1;  // 复制对象
    cout << "-------------------------------\n";
    DD dd1;
    DD dd2(dd1);
    cout << "-------------------------------\n";
    FF test(1);
    // ff_fun(test);  按值传递将会报错!
    return 0;
}