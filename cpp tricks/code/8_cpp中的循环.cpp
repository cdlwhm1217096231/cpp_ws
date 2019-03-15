#include "iostream"
#include "math.h"
#include "stdlib.h"

using namespace std;

int main(){

    // while循环
    int a = 10;  // 局部变量声明
    while (a < 20){
        cout << "a = " << a << endl;
        a++;
    }
    cout << endl;
    // for循环
    for (int i = 10; i < 20; i++){
        cout << "i = " << i << endl;
    }
    cout << endl;
    // do-while循环
    int j = 10;
    do{
        cout << "j = " << j << endl;
        j++;
    }while(j < 20);
    // 嵌套循环(找出2-100内的质数)
    int m, n;
    for(m = 2; m < 100; m++) {
        for(n=2; n <= (m / n); n++) {
            if(!(m % n)) {
                break; // 如果找到即m%n等于0也就是说m能整除n，所以m不是质数
            }
        }
        if(n > (m / n)) {
            cout << m << " 是质数\n";
        }
    }
    cout << endl;
    // break语句
    int aa = 10;
    do{
        cout << "aa = " << aa << endl;
        aa++;
        if (aa > 15)
            break;
    }while(aa < 20);
    cout << endl;
    // continue语句
    int bb;
    for(bb = 1; bb <= 20; bb++){
        if(bb % 2 != 0)
            continue;
        cout << "bb = "  << bb << endl; // 找出1-20内的偶数
    }
    // 输出乘法表
    int i1, j1;
    for (i1 = 1; i1 < 10; i1++){
        for (j1 = 1; j1 <= i1; j1++){
            cout << j1 << "×" << i1 << "=" << i1 * j1 << "  ";
        }
        cout << endl << endl;
    }
    // 输出菱形
    cout << "请输入半菱形高度n = ";
    int n1 = 0;
    cin >> n1;
    for (int i2 = 0; i2 < 2 * n1 + 1; i2++) {
        for (int j2 = 0; j2 < 2 * n1 + 1; j2++) {
            if (abs(i2 - n1) + abs(j2 - n1) == n1) {
                cout << "*";
            } else {
                cout << " ";
            }
        }
        cout << endl;
    }
    return 0;
}