#include "iostream"

using namespace std;

/*--------------------将当前类的类型转换为其它类型--------------------------*/

class complex{
    public:
        complex():m_real(0.0), m_img(0.0){}
        complex(double real, double img):m_real(real), m_img(img){}
    public:
        friend complex operator+ (const complex &c1, const complex &c2);
        friend ostream & operator<< (ostream &out, const complex &c);
        operator double() const{return m_real;}  // 类型转换函数，将complex类转化为double类型

    private:
        double m_real;
        double m_img;  
};

complex operator+ (const complex &c1, const complex &c2){
    complex c;
    c.m_real = c1.m_real + c2.m_real;
    c.m_img = c1.m_img + c2.m_img;
    return c;
}

ostream & operator<< (ostream &out, const complex &c){
    out << c.m_real << " + " << c.m_img << "i";
    return out;
}


int main(){
    complex c1(24.6, 100);
    double f = c1;
    cout << "f = " << f << endl;

    f = 12.5 + c1 + 6;
    cout << "f = " << f << endl;

    int n = complex(46.5, 9.4);
    cout << "n = " << n << endl;

    return 0;
}