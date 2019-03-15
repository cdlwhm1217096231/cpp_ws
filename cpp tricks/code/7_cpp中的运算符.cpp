#include "iostream"

using namespace std;


int main(){

    // 算术运算符
    int a = 21;
    int b = 10;
    int c;
    c = a + b;
    cout << "c = " << c << endl;
    c =  a - b;
    cout << "c = " << c << endl;
    c = a * b;
    cout << "c = " << c << endl;
    c = a / b;
    cout << "c = " << c << endl;
    c = a % b;  // 取余运算符
    cout << "c = " << c << endl;

    int d = 10;
    c = d++; // 自加
    cout << "c = " << c << endl;

    d = 10;
    c = d--; // 自减
    cout << "c = " << c << endl;
    // 关系运算符
    int aa = 21, bb = 10;
    int cc;
    if (aa == bb)
        cout << "aa == bb\n";
    else    
        cout << "aa != bb\n";
    if (aa > bb)
        cout << "aa > bb\n";
    else    
        cout << "aa < bb\n";
    if (aa < bb)
        cout << "aa < bb\n";
    else    
        cout << "aa > bb\n";
    if (aa != bb)
        cout << "aa != bb\n";
    else
        cout << "aa == bb\n"; 
    aa = 5;
    bb = 20;
    if ( aa <= bb )
        cout << "aa小于或等于bb" << endl ;
    if ( bb >= aa )
        cout << "bb大于或等于aa" << endl ;
    // 逻辑运算符
    int a1 = 5, b1 = 20, c1;
    if (a1 && b1)
        cout << "条件为真\n";
    if (a1 || b1)
        cout << "条件位真\n";
    a1 = 0;
    b1 = 10;
    if (a1 && b1)
        cout << "条件为真\n";
    else    
        cout << "条件为假\n";
    if (!(a1 && b1))
        cout << "条件为真\n";
    // 位运算符
    unsigned int a2 = 60;
    unsigned int b2 = 13;
    int c2 = 0;
    c2 = a2 & b2;
    cout << "a2 & b2: " << c2 << endl;
    c2 = a2 | b2;
    cout << "a2 | b2: " << c2 << endl;
    c2 = a2 ^ b2;
    cout << "a2 ^ b2: " << c2 << endl;
    c2 = ~a2;
    cout << "~a2: " << c2 << endl;
    c2 = a2 << 2;
    cout << "a2 << 2: " << c2 << endl;
    c2 = a2 >> 2;
    cout << "a2 >> 2: " << c2 << endl;
    // 赋值运算符
    int a3 = 21;
    int c3;
    c3 = a3;
    cout << "c3 = " << c3 << endl;
    c3 += a3;
    cout << "c3 = " << c3 << endl;
    c3 -= a3;
    cout << "c3 = " << c3 << endl;
    c3 *= a3;
    cout << "c3 = " << c3 << endl;
    c3 /= a3;
    cout << "c3 = " << c3 << endl;
    c3 = 200;
    c3 %= a3;
    cout << "c3 = " << c3 << endl;
    c3 <<= 2;
    cout << "c3 = " << c3 << endl;
    c3 >>= 2;
    cout << "c3 = " << c3 << endl;
    c3 &= 2;
    cout << "c3 = " << c3 << endl;
    c3 ^= 2;
    cout << "c3 = " << c3 << endl;
    c |= 2;
    cout << "c3 = " << c3 << endl;
    // 运算符优先级
    int a4 = 20;
    int b4 = 10;
    int c4 = 15;
    int d4 = 5;
    int e4;
    
    e4 = (a4 + b4) * c4 / d4;      // ( 30 * 15 ) / 5
    cout << "(a4 + b4) * c4 / d4 的值是 " << e4 << endl ;
    
    e4 = ((a4 + b4) * c4) / d4;    // (30 * 15 ) / 5
    cout << "((a4 + b4) * c4) / d4 的值是 " << e4 << endl ;
    
    e4 = (a4 + b4) * (c4 / d4);   // (30) * (15/5)
    cout << "(a4 + b4) * (c4 / d4) 的值是 " << e4 << endl ;
    
    e4= a4 + (b4 * c4) / d4;     //  20 + (150/5)
    cout << "a4 + (b4 * c4) / d4 的值是 " << e4 << endl ;
    // 指针运算符
    int var;
    int *ptr;
    int val;
    var = 200;
    // 获取var的地址
    ptr = &var;
    cout << "指针变量所占字节空间大小: " << sizeof(*ptr) << endl;
    val = *ptr;  // 获取ptr的值
    cout << "var = " << var << endl;
    cout << "ptr = " << ptr << endl;
    cout << "val = " << val << endl;
    return 0;
}