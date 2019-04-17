#include "iostream"

using namespace std;

/*---------------------------将其它类型转换为当前类的类型-------------------------------*/

// 如果编译器不知道转换规则就不能转换，使用强制类型也无用
class complex{
    public:
        complex():m_real(0.0), m_img(0.0){}
        complex(double real, double img):m_real(real), m_img(img){}
        complex(double real): m_real(real), m_img(0.0){}  // 转换构造函数
    public:
        friend ostream & operator<< (ostream &out, const complex &c); // 友元函数
    private:
        double m_real;
        double m_img;
};

ostream & operator << (ostream &out, const complex &c){
    out << c.m_real << " + " << c.m_img << "i";
    return out;
}

int main(){
    complex a(10.0, 20.0);
    cout << "a = " << a << endl;
    a = 25.5;
    cout << "a = " << a << endl;
    return 0;
}