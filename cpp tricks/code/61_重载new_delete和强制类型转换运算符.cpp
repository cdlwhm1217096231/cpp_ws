#include "iostream"

using namespace std;


// 强制类型转换运算符重载()
class complex{
    public:
        complex(double real=0.0, double img=0.0):m_real(real), m_img(img){};
        operator double (){return m_real;}  // 重载强制类型转换运算符double
    
    private:
        double m_real;
        double m_img;
};

int main(){
    complex c(1.2, 3.4);
    cout << (double)c << endl;  // 输出 1.2
    double n = 2 + c;  // 等价于 double n = 2 + c. operator double()
    cout << n;  // 输出 3.2
    return 0;
}