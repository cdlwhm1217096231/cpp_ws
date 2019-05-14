#include <iostream>

using namespace std;


int main(){
    /*1.无符号数转为有符号数*/
    // 因为short int 在32位机器上占2个字节，即16位。故无符号数unsigned short int表示范围是0到65535
    // 而有符号数signed int可表示的范围是-32768-32767
    // 无符号数转为有符号数的转换方法是:假设无符号数是N，无符号数的数据基本类型所占的位数是B位，则有符号数的表示是：N - 2^B
    unsigned short int a = 50000;
    signed short int b = 0;
    b = a;
    cout << "无符号数转为有符号数: " << b << endl;
    /*2.有符号数转为无符号数*/
    unsigned int u = 10;
    int i = -42;
    cout << "有符号数转为无符号数:" << u+i << endl;
    // 当有符号数和无符号数相加时，首先将有符号数变为无符号数，然后执行加法操作。有符号数转为无符号数的方法：有符号数+无符号数的模
    // 例如上例中，int i = -42;i是一个有符号数，unsigned int u是一个无符号数，u在32位机器上占4个字节，即32位，故无符号数u的模是2^32
    // 所以，最后的结果是u+i =-42+2^32+10
    /*3.两个无符号数之间的运算*/
    unsigned int u1 = 42, u2 = 10;
    cout << "u1 - u2 = " << u1 - u2 << endl;  // 正常运算
    cout << "u2 - u1 = " << u2 - u1 << endl;  // u1-u2 = -32,因为无符号数不会小于0，然所以将使用上面2中的方法，故最后的结果是-32+2^32
    /*4.无符号数用于循环*/
    // for(unsigned int i = 10; i >=0;i--)  陷入死循环，原因是当执行到最后一次循环时,输出i = 0,i--后i变成-1，根据上面3的分析，所以被自动转成无符号数2^32-1,再继续进行循环
    //     cout << "i = " << i << endl;
    unsigned int u3 = 11;
    while(u3 > 0){  // 改用fwhile循环将不会陷入死循环
        --u3;
        cout << "u3 = " << u3 << endl;
    }
    return 0;
    
}