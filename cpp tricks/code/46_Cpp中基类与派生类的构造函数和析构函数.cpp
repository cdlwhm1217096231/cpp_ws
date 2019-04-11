#include "iostream"

using namespace std;

// 基类people
class People{
    protected:
        char *m_name;
        int m_age;
    public:
        People(char *name, int age);
};
People::People(char *name, int age):m_name(name),m_age(age){}

// 派生类student·
class Student:public People{
    private:
        float m_score;
    public: 
        Student(char *name, int age, float score);
        void show();
};
// People(name, age)就是调用基类的构造函数
Student::Student(char *name, int age, float score):People(name, age),m_score(score){}
void Student::show(){
    cout << "m_name = " << m_name << ",m_age = " << m_age << ",m_score = " << m_score << endl;
}

// 基类构造函数调用规则

// 基类A
class A{
    public:
        A();  // 基类默认构造函数
        A(char *name, int age);
    protected:
        char *m_name;
        int m_age;
};

A::A():m_name("xxx"), m_age(30){}
A::A(char *name, int age):m_name(name), m_age(age){}

// 派生类B
class B: public A{
    public:
        B();
        B(char *name, int age, float score);
        void show();
    private:
        float m_score;
};

B::B():m_score(0.0){}  // 派生类默认构造函数
B::B(char *name, int age, float score):A(name, age), m_score(score){}
void B::show(){
    cout << "m_name = " << m_name << ",m_age = " << m_age << ",m_score = " << m_score << endl;
}

// 基类和派生类的析构函数
class C{
    public:
        C(){
            cout << "C constructor\n";
        }
        ~C(){
            cout << "C deconstructor\n";
        }
};

class D: public C{
    public:
        D(){
            cout << "D constructor\n";
        }
        ~D(){
            cout << "D deconstructor\n";
        }
};

class E:public D{
    public:
        E(){
            cout << "E constructor\n";
        }
        ~E(){
            cout << "E deconstructor\n";
        }
};

int main(){
    Student stu("curry", 30, 91.4);
    stu.show();

    B b1;
    b1.show();
    cout << "-------------------------------\n";

    B b2("Curry", 30, 91.3);
    b2.show();
    cout << "-------------------------------\n";
    E test;
    return 0;
}