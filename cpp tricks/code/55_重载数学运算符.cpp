#include "iostream"
#include "cmath"

using namespace std;


/*

四则运算符（+、-、*、/、+=、-=、*=、/=）和关系运算符（>、<、<=、>=、==、!=）都是数学运算符，
它们在实际开发中非常常见，被重载的几率也很高，并且有着相似的重载格式。
下面以复数类Complex为例对它们进行重载，演示运算符重载的语法以及规范。
*/

class complex{
    public:
        complex(double a = 0.0, double b=0.0):real(a),img(b){};  // 构造函数
    public:
        // 运算符重载---以全局函数的形式重载
        friend complex operator+(const complex &c1, const complex &c2);
        friend complex operator-(const complex &c1, const complex &c2);
        friend complex operator*(const complex &c1, const complex &c2);
        friend complex operator/(const complex &c1, const complex &c2);
        friend bool operator==(const complex &c1, const complex &c2);
        friend bool operator!=(const complex &c1, const complex &c2);
        // 运算符重载---以成员函数的形式重载
        complex & operator+=(const complex &c);
        complex & operator-=(const complex &c);
        complex & operator*=(const complex &c);
        complex & operator/=(const complex &c);
    public:
        // 常成员函数
        double freal() const{return real;}
        double fimg() const{return img;}
    private:
        double real;
        double img;
};

//重载+运算符
complex operator+(const complex &c1, const complex &c2){
    complex c;
    c.real = c1.real + c2.real;
    c.img = c1.img + c2.img;
    return c;
}
//重载-运算符
complex operator-(const complex &c1, const complex &c2){
    complex c;
    c.real = c1.real - c2.real;
    c.img = c1.img - c2.img;
    return c;
}
//重载*运算符  (a+bi) * (c+di) = (ac-bd) + (bc+ad)i
complex operator*(const complex &c1, const complex &c2){
    complex c;
    c.real = c1.real * c2.real - c1.img * c2.img;
    c.img = c1.img * c2.real + c1.real * c2.img;
    return c;
}
//重载/运算符  (a+bi) / (c+di) = [(ac+bd) / (c?+d?)] + [(bc-ad) / (c?+d?)]i
complex operator/(const complex &c1, const complex &c2){
    complex c;
    c.real = (c1.real*c2.real + c1.img*c2.img) / (pow(c2.real, 2) + pow(c2.img, 2));
    c.img = (c1.img*c2.real - c1.real*c2.img) / (pow(c2.real, 2) + pow(c2.img, 2));
    return c;
}
//重载==运算符
bool operator==(const complex &c1, const complex &c2){
    if( c1.real == c2.real && c1.img == c2.img ){
        return true;
    }else{
        return false;
    }
}
//重载!=运算符
bool operator!=(const complex &c1, const complex &c2){
    if( c1.real != c2.real || c1.img != c2.img ){
        return true;
    }else{
        return false;
    }
}
//重载+=运算符
complex & complex::operator+=(const complex &c){
    this->real += c.real;
    this->img += c.img;
    return *this;
}
//重载-=运算符
complex & complex::operator-=(const complex &c){
    this->real -= c.real;
    this->img -= c.img;
    return *this;
}
//重载*=运算符
complex & complex::operator*=(const complex &c){
    this->real = this->real * c.real - this->img * c.img;
    this->img = this->img * c.real + this->real * c.img;
    return *this;
}
//重载/=运算符
complex & complex::operator/=(const complex &c){
    this->real = (this->real*c.real + this->img*c.img) / (pow(c.real, 2) + pow(c.img, 2));
    this->img = (this->img*c.real - this->real*c.img) / (pow(c.real, 2) + pow(c.img, 2));
    return *this;
}
int main(){
    complex c1(25, 35);
    complex c2(10, 20);
    complex c3(1, 2);
    complex c4(4, 9);
    complex c5(34, 6);
    complex c6(80, 90);
   
    complex c7 = c1 + c2;
    complex c8 = c1 - c2;
    complex c9 = c1 * c2;
    complex c10 = c1 / c2;
    cout<<"c7 = "<<c7.freal()<<" + "<<c7.fimg()<<"i"<<endl;
    cout<<"c8 = "<<c8.freal()<<" + "<<c8.fimg()<<"i"<<endl;
    cout<<"c9 = "<<c9.freal()<<" + "<<c9.fimg()<<"i"<<endl;
    cout<<"c10 = "<<c10.freal()<<" + "<<c10.fimg()<<"i"<<endl;
   
    c3 += c1;
    c4 -= c2;
    c5 *= c2;
    c6 /= c2;
    cout<<"c3 = "<<c3.freal()<<" + "<<c3.fimg()<<"i"<<endl;
    cout<<"c4 = "<<c4.freal()<<" + "<<c4.fimg()<<"i"<<endl;
    cout<<"c5 = "<<c5.freal()<<" + "<<c5.fimg()<<"i"<<endl;
    cout<<"c6 = "<<c6.freal()<<" + "<<c6.fimg()<<"i"<<endl;
   
    if(c1 == c2){
        cout<<"c1 == c2"<<endl;
    }
    if(c1 != c2){
        cout<<"c1 != c2"<<endl;
    }
   
    return 0;
}

