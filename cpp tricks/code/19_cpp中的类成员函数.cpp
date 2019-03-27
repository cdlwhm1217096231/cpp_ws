#include "iostream"
#include "iomanip"
#include "string"
#include "cstdio"
#include "cstring"



using namespace std;



int month;  // 全局变量
int day;
int year;

void Set(int m, int d, int y){
    ::year = y;  // 给全局变量赋值
    ::day = d;
    ::month = m;
}

class Tdate{
public:
    void Set(int m, int d, int y){  // 成员函数
        ::Set(m, d, y);  // 非成员函数
    }
private:
    int month;
    int day;
    int year;
};


class Box{
public:
    double length;
    double breadth;
    double height;
    double getVolume(void){  // 内联的成员函数inline
        return length * breadth * height;
    }
    double getVolume1(void);
    // 成员函数的声明
    void setLength(double len);
    void setBreadth(double bre);
    void setHeight(double hei);
};

// 成员函数的定义
double Box::getVolume1(void){
    return length * breadth * height;
}

void Box::setLength(double len){
    length = len;
}

void Box::setBreadth(double bre){
    breadth = bre;
}

void Box::setHeight(double hei){
    height = hei;
}


class Student{
    public:
        char name[20];
        char sex[10];
        float math;
        float english;
        float program;
        void input_name();
        void input_sex();
        void input_math();
        void input_english();
        void input_program();
        void input(class Student *stu);
        void show_student_info(class Student *stu);
};

void Student::input_name(){
    cout << "请输入学生姓名: ";
    cin.getline(name, sizeof(name));
    cout << "学生姓名: "  << name << endl;
}

void Student::input_sex(){
    cout << "请输入学生性别: ";
    cin.getline(sex, sizeof(sex));
}

void Student::input_math(){
    cout << "请输入学生的数学成绩: ";
    cin >> math;
}

void Student::input_english(){
    cout << "请输入学生的英语成绩: ";
    cin >> english;
}

void Student::input_program(){
    cout << "请输入学生的编程课成绩: ";
    cin >> program;
}

void Student::show_student_info(class Student *stu){
    cout << "学生姓名: " << stu->name << endl;
    cout << "学生性别: "  << stu->sex <<endl;
    cout << "学生数学成绩: " << stu->math << endl;
    cout << "学生英语成绩: " << stu->english << endl;
    cout << "学生编程课成绩: " << stu->program << endl;
}

void Student::input(class Student *stu){
    stu->input_name();
    stu->input_sex();
    stu->input_english();
    stu->input_math();
    stu->input_program();
}

int main(){
    Box box1;
    Box box2;
    double volume = 0.0;
    

    // box1的详细信息
    box1.setLength(6.0);
    box1.setBreadth(7.0);
    box1.setHeight(8.0);
    // box1的体积
    volume = box1.length * box1.breadth * box1.height;
    cout << "Box1的体积是: " << volume << endl;

    // box2的详细信息
    box2.setLength(12.0);
    box2.setBreadth(13.0);
    box2.setHeight(10.0);
    // box2的体积
    volume = box2.length * box2.breadth * box2.height;
    cout << "Box2的体积是: " << volume << endl;
    // 1.类成员函数
    Student dana;
    Student *dana_pointer = &dana;
    dana.input(dana_pointer);
    dana.show_student_info(dana_pointer);
    return 0;
}


