#include "iostream"


using namespace std;

class String{
    public:
        String(char *str);
        String operator+(const String &A);  // 成员函数进行重载
        friend String & operator+(const String &A, const String &B); // 友元函数进行运算符重载
        friend String & operator+(const String &A, char *str);
        friend String & operator+(char *str, const String &A);

    private:
        char *ptr;
};

// <<只能使用友元函数进行运算符重载
class complex{
    public:
        complex(double a = 0.0, double b = 0.0){};
        complex(double a, double b):real(a),img(b){};

        // ostream只能使用友元函数进行运算符重载
        friend ostream & operator <<(ostream &os, const complex &c);
    private:
        double real;
        double img;
};

ostream & operator << (ostream &os, const complex &c){
    cout << c.real << "+" << c.img << "i" << endl;
    return os;
}
