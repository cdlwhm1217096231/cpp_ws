#include "iostream"

using namespace std;

class Line{
    public:
        void setLength(double len);
        double getLength();
        Line(double len);   // 带参数的构造函数
        ~Line();  // 析构函数不能带有任何参数
    private:
        double length;
};

class Box{
    public:
        void setLength(double len);
        double getLength();
        void setWidth(double wid);
        double getWidth();
        void setHeight(double hei);
        double getHeight();

        // 使用初始化列表来初始化字段----构造函数
        Box(double len, double wid, double hei): length(len), width(wid), height(hei){
            cout << "Box的对象box正在被创建,length = " << len << " width = " << wid << " height = " << hei << endl; 
        }
        // 析构函数
        ~Box(){
            cout << "对象box正在被删除...\n";
        }
    private:
        double length;
        double width;
        double height;
};

class Student1{
    public:
        int a;
        int b;
        // 普通成员函数
        void fprint(){
            cout << "a = " << a << ",b = " << b << endl;
        }
        // Student1(int i): b(i), a(b){} 异常顺序：发现a的值是0，b的值是2；说明初始化仅仅对b有效，对a没有起到初始化的作用
        Student1(int i): a(i), b(a){} // 正常顺序:a = b = 2
        // 默认构造函数
        Student1(){
            cout << "默认构造函数Student1\n";
        }
        // 拷贝构造函数
        Student1(const Student1& t1){
            cout << "拷贝构造函数Student1\n";
            this->a = t1.a;
        }
};

// 构造函数的定义
Line::Line(double len){
    cout << "Line的对象line正在被创建, lenght = " << len << endl;
    length = len;
}

// 析构函数定义
Line::~Line(){
    cout << "Line的对象正在被删除..." << endl;
}
// // 使用初始化列表来初始化字段
// Line::Line(double len): length(len){
//     cout << "Line的对象line正在被创建, lenght = " << len << endl;    
// }


// 成员函数的定义
void Line::setLength(double len){
    length = len;
}

double Line::getLength(){
    return length;
}
// Box类的成员函数定义
void Box::setLength(double len){
    length = len;
}

double Box::getLength(){
    return length;
}

void Box::setWidth(double wid){
    width = wid;
}

double Box::getWidth(){
    return width;
}

void Box::setHeight(double hei){
    height = hei;
}

double Box::getHeight(){
    return height;
}


int main(){
    // 获取默认设置的长度
    Line line(10.0);  // 创建一个line对象，此时会去执行带参数的构造函数
    line.setLength(4.0);
    cout << "Line的长度是: " << line.getLength() << endl;
    cout << "-------------------------------------------\n";
    Box box(3.0, 4.0, 5.0);
    box.setLength(33.0);
    cout << "Box的长度是: " << box.getLength() << endl;
    box.setWidth(44.0);
    cout << "Box的宽度是: " << box.getWidth() << endl;
    box.setHeight(55.0);
    cout << "Box的高度是: " << box.getHeight() << endl;
    cout << "-------------------------------------------\n";
    Student1 A(2);        //进入默认构造函数 
    A.fprint();            //输出前面初始化的结果
    return 0;
}