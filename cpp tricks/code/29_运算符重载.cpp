#include "iostream"
#include "cstring"
#include "cstdlib"
#include "cstdio"
#include <vector>

using namespace std;

// 函数重载
class A{
    public: 
        void print(int i){
            cout << "整数为: " << i << endl;
        }
        void print(double d){
            cout << "浮点数为: " << d << endl;
        }
        void print(char c[]){
            cout << "字符串为: " << c << endl;
        }
};

// 运算符重载
class Box{
    public:
        double getVolume(){
            return length * width * height;
        }
        void setLength(int len){
            length = len;
        }
        void setWidth(int wid){
            width = wid;
        }
        void setHeight(int hei){
            height = hei;
        }
    // 运算符重载：用于把两个box对象相加
        Box operator+(const Box& b){
            Box box;
            box.length = this->length + b.length;
            box.width = this->width + b.width;
            box.height = this->height + b.height;
            return box;
        }
    private:
        int length;
        int width;
        int height;
};

// 一元运算符重载

// ++与--运算符重载
class Time{
    private:
        int hours;
        int minutes;
    public:
        Time(){
            hours = 0;
            minutes = 0;
        }
        Time(int h, int m): hours(h), minutes(m){
            cout << "Time类对象的构造函数\n";
        }
        void display(){
            cout << "H:" << hours << " M:" << minutes << endl;
        }
        // 重载前缀递增++运算符
        Time operator++(){
            ++minutes;  // 对象加 1
            if(minutes >= 60){
                ++hours;
                minutes-= 60;
            }
            return Time(hours, minutes);
        }
        // 重载后缀递增++运算符
        Time operator++(int){
            Time T(hours, minutes);  // 保存原始值
            ++minutes;  // 对象加 1
            if(minutes >= 60){
                ++hours;
                minutes-= 60;
            }
            return T;  // 返回旧的原始值
        }

};
// ++与--运算符重载注意的点
class CA{
    public:
        int pos;
        // 前置++就是增加当前对象的pos的值，并返回当前对象
        CA operator++(){
            pos++;
            return *this;
        }
        // 后置++就是增加当前对象的pos的值，并返回增加pos之前的对象
        CA operator++(int){
            CA temp = *this;
            ++*this;
            return temp;
        }
};

// 重载一元减运算符-
class Distance{
    private:
        int feet;
        int inches;
    public:
        Distance(){
            feet = 0;
            inches = 0;
        }
        Distance(int f, int i): feet(f), inches(i){
            cout << "Distance类对象的构造函数\n";
        }
        void displayDistance(){
            cout << "F = " << feet << " I = " << inches << endl;
        }
        // 重载运算符-
        Distance operator-(){
            feet = -feet;
            inches = -inches;
            return Distance(feet, inches);
        }
        // 重载关系运算符<
        bool operator < (const Distance& d){
            if(feet < d.feet)
                return true;
            if(feet == d.feet && inches < d.inches)
                return true;
            return false;
        }
        // 重载输入输出运算符
        friend ostream &operator<<(ostream &output, const Distance& D){
            output << "F = " << D.feet << " I = " << D.inches << endl;
            return output;
        }
        friend istream &operator>>(istream &input, Distance &D){
            input >> D.feet >> D.inches;
            return input;
        }
        // 赋值运算符重载
        void operator=(const Distance& D){
            feet = D.feet;
            inches = D.inches;
        }
        // 重载函数调用运算符
        Distance operator()(int a, int b, int c){
            Distance D;
            // 进行随机计算
            D.feet = a + c + 10;
            D.inches = b + c + 100;
            return D;
        }
};

// 当用用户自定义类型变量向内置类型变量赋值时，可以使用自定义类型的隐式转换
class Int{
    private:
        int n;
    public:
        Int(int i){
            cout << "Int对象的构造函数\n";
        };
        operator int(){  // 这里就是隐式转换声明，应注意到它与运算符重载的不同之处
            return n;
        }
};
// 下标运算符重载
const int SIZE = 10;
class safearray{
    private:
        int arr[SIZE];
    public:
        safearray(){
            register int i;
            for(i = 0; i < SIZE; i++)
                arr[i] = i;
        }
        // 下标运算符重载
        int & operator[](int i){
            if(i > SIZE){
                cout << "索引超过最大值: ";
                return arr[0];
            }
            return arr[i];
        }      
};

// 类成员访问运算符->
class OO{
    static int i,j;
    public:
        void f() const{  // 常函数
            cout << i++ << endl;
        }
        void g() const{
            cout << j++ << endl;
        }
};
// 静态成员定义
int OO::i = 10;
int OO::j = 12;
// 为上面的类实现一个容器
class ObjContainer {
   vector<OO*> a;
public:
   void add(OO* obj)
   { 
      a.push_back(obj);  // 调用向量的标准方法
   }
   friend class SmartPointer;
};
// 实现智能指针，用于访问类 Obj 的成员
class SmartPointer {
   ObjContainer oc;
   int index;
public:
   SmartPointer(ObjContainer& objc)
   { 
       oc = objc;
       index = 0;
   }
   // 返回值表示列表结束
   bool operator++() // 前缀版本
   { 
     if(index >= oc.a.size() - 1) return false;
     if(oc.a[++index] == 0) return false;
     return true;
   }
   bool operator++(int) // 后缀版本
   { 
      return operator++();
   }
   // 重载运算符 ->
   OO* operator->() const 
   {
     if(!oc.a[index])
     {
        cout << "Zero value";
        return (OO*)0;
     }
     return oc.a[index];
   }
};
 

int main(){
    A a;
    // 输出整数
    a.print(2);
    // 输出浮点数
    a.print(3.14);
    // 输出字符串
    char c[] = "Hello Curry";
    a.print(c);
    cout << "----------------------------------------------\n";
    Box box1;
    Box box2;
    Box box3;
    double volume = 0.0;
    box1.setLength(6.0);
    box1.setWidth(7.0);
    box1.setHeight(5.0);

    box2.setLength(12.0);
    box2.setWidth(13.0);
    box2.setHeight(10.0);

    volume = box1.getVolume();
    cout << "box1的体积是: " << volume << endl;
    volume = box2.getVolume();
    cout << "box2的体积是: " << volume << endl;

    box3 = box1 + box2;
    volume = box3.getVolume();
    cout << "box3的体积是: " << volume << endl;
    cout << "----------------------------------------------\n";
    Time T1(11, 59), T2(10, 40);
    ++T1;
    T1.display();
    ++T1;
    T1.display();

    T2++;
    T2.display();
    T2++;
    T2.display();
    cout << "----------------------------------------------\n";
    CA ca,cb;
    ca.pos = 1;
    cb = ca++;
    cout << "cb = " << cb.pos << endl;
    cb = ++ca;
    cout << "cb = " << cb.pos << endl;
    cout << "----------------------------------------------\n";
    Distance D1(10, 11), D2(5, 11);
    -D1;
    D1.displayDistance();
    -D2;
    D2.displayDistance();
    cout << "----------------------------------------------\n";
    if (D1 < D2)
        cout << "D1 < D2\n";
    else    
        cout << "D1 > D2\n";
    cout << "----------------------------------------------\n";
    Distance D3(11, 10), D4(3, 2), D5;
    cout << "请输入目标值D5 = ";
    cin >> D5;
    cout << "D3 = " << D3 << endl;
    cout << "D4 = " << D4 << endl;
    cout << "D5 = " << D5 << endl; 
    cout << "----------------------------------------------\n";
    D1 = D2;
    cout << "D1: " << D1 << endl;
    D1.displayDistance();
    cout << "----------------------------------------------\n";
    Int int_obj(3);
    int i = int_obj;  // 隐式调用转换函数
    cout << "i = " << i << endl;
    cout << "int_obj = " << int_obj << endl;  // 由于未重载Int的<<操作符，将隐式调用转换函数
    cout << "----------------------------------------------\n";
    Distance D6;
    D6 = D1(10, 10, 10);
    cout << "D6: " << D6 << endl;
    cout << "----------------------------------------------\n";
    safearray sa;
    cout << "sa[2] = " << sa[2] << endl;
    cout << "sa[5] = " << sa[5] << endl;
    cout << "sa[12] = " << sa[12] << endl;
    cout << "----------------------------------------------\n";
    const int sz = 10;
    OO o[sz];
    ObjContainer oc;
    for(int i = 0; i < sz; i++)
    {
        oc.add(&o[i]);
    }
    SmartPointer sp(oc); // 创建一个迭代器
    do {
        sp->f(); // 智能指针调用
        sp->g();
    } while(sp++);
    return 0;
}