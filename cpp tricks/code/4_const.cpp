#include "iostream"

using namespace std;

// 定义常量之宏定义
#define LENGTH 4
#define WIDTH 3
#define NEWLINE '\n'
#define N 5
#undef N 

int main(){
    // 整型常量
    /*
    85         // 十进制
    0213       // 八进制 
    0x4b       // 十六进制 
    30         // 整数 
    30u        // 无符号整数 
    30l        // 长整数 
    30ul       // 无符号长整数
    */

    // 浮点常量
    /*
    3.14159       // 合法的 
    314159E-5L    // 合法的 
    510E          // 非法的：不完整的指数
    210f          // 非法的：没有小数或指数
    .e55          // 非法的：缺少整数或分数
    */

    // 字符常量之转义字符
    cout << "hello\tworld\a\n";

    //  字符串常量
    // "hello dear！"
    int area;
    area = LENGTH * WIDTH;
    cout << "area = " << area << endl;
    cout << NEWLINE;
    // 定义常量之const修饰符
    const int WIDTH1 = 10;
    const int LENGTH1 = 20;
    return 0;
}