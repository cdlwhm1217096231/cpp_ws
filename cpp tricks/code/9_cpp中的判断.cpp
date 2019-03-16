#include "iostream"

using namespace std;

int main(){
    // if语句
    int a = 20;
    if (a < 10)
        cout << "a的值小于20\n";
    cout << "a = " << a << endl;
    // if-else语句
    int aa = 100;
    if(aa < 20)
        cout << "aa的值小于20\n";
    else    
        cout << "aa的值大于20\n";
    cout << "aa = " << aa << endl;
    // if else  if else语句
    int a1 = 100;
    if (a1 == 10)
        cout << "a1的值是10\n";
    
    else if (a1 == 20)
    {
        cout << "a1的值是20\n";
    }
    else if (a1 == 30)
    {
        cout << "a1的值是30\n";
    }else{
        cout << "以上条件都不满足\n";
    }
    cout << "a1 = " << a1 << endl;
    // 嵌套if语句
    int a2 = 100;
    int b2 = 200;
    if (a2 == 100){
        if (b2 == 200){
            cout << "a2的值是100,b2的值是200\n";
        }
    }
    cout << "a2 = " << a2 << endl;
    cout << "b2 = " << b2 << endl;
    // switch语句
    char grade = 'D';
    switch(grade){
        case 'A':
            cout << "优秀\n";
            break;
        case 'B':
            cout << "良好\n";
            break;
        case 'C':
            cout << "及格\n";
            break;
        case 'D':
            cout << "不及格\n";
            break;
        default:
            cout << "成绩无效\n";
            break;
    }
    cout << "你的成绩是: " << grade << endl;
    // switch语句嵌套
    int a3 = 100;
    int b3 = 200;
    switch(a3){
        case 100:
            cout << "这是外部的switch的一部分\n";
        switch (b3){
            case 200:
                cout << "这是内部的switch的一部分\n";
        }
    }
    cout << "a3 = " << a3 << endl;
    cout << "b3 = " << b3 << endl;
    // ?:运算符
    int a4, b4, c4, d4, m, n, z;
    a4 = 10;
    b4 = 20; 
    c4 = 30;
    d4 = 40;
    m = a4 > b4 ? a4 : b4;
    n = c4 > d4 ? c4 : d4;
    z = m > n ? m:n;
    cout << "四个数中的最大值是: " << z << endl;
    return 0;
}