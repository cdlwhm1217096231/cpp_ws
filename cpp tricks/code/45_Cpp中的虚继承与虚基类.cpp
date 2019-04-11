#include "iostream"

using namespace std;

// 间接基类
class A
{
  protected:
    int m_a;
};
// 直接基类B
class B : virtual public A
{
  protected:
    int m_b;
};

// 直接基类C
class C : virtual public A
{
  protected:
    int m_c;
};

// 派生类D
class D : public B, public C
{
  public:
    void seta(int a) { m_a = a; }   // 正确！
    void setb(int b) { m_b = b; }
    void setc(int c) { m_c = c; }

  private:
    int m_d;
};

// 虚基类AA
class AA{
  protected:
    int m_a;
  public:
    AA(int a);
};
// 类外定义虚基类AA的构造函数
AA::AA(int a):m_a(a){}
// 直接派生类BB
class BB: virtual public AA{
  protected:
    int m_b;
  public:
    BB(int a, int b);
    void show();
};
BB::BB(int a, int b): AA(a), m_b(b){}
void BB::show(){
  cout << "m_a = " << m_a << ",m_b = " << m_b << endl;
}

// 直接派生类CC
class CC: virtual public AA{
  public:
    CC(int a, int c);
    void show();
  protected:
    int m_c;
};
CC::CC(int a, int c):AA(a), m_c(c){}
void CC::show(){
  cout << "m_a = " << m_a << ",m_c = " << m_c << endl;
}

// 间接派生类DD
class DD: public BB, public CC{
  protected:
    int m_d;
  public:
    DD(int a, int b, int c, int d);
    void show();
};
DD::DD(int a, int b, int c, int d):AA(a), BB(90, b), CC(100, c), m_d(d){}
void DD::show(){
  cout <<"m_a = " << m_a << ",m_b = " << m_b << ",m_c = " << m_c << ",m_d = " << m_d << endl;
}

int main()
{
    D d;
    BB bb(10, 20);
    bb.show();
    CC cc(30, 40);
    cc.show();
    DD dd(50, 60, 70, 80);
    dd.show();
    return 0;
}