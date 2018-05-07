/*
C++ 常量
常量是固定值，在程序执行期间不会改变。这些固定的值，又叫做字面量
常量可以是任何的基本数据类型，可分为整型数字、浮点数字、字符、字符串和布尔值
*/

// 整数常量
/*
整数常量可以是十进制、八进制或十六进制的常量。前缀指定基数：0x 或 0X 表示十六进制，0 表示八进制，不带前缀则默认表示十进制。
整数常量也可以带一个后缀，后缀是 U 和 L 的组合，U 表示无符号整数（unsigned），L 表示长整数（long）。
后缀可以是大写，也可以是小写，U 和 L 的顺序任意。
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
浮点常量由整数部分、小数点、小数部分和指数部分组成。您可以使用小数形式或者指数形式来表示浮点常量
当使用小数形式表示时，必须包含整数部分、小数部分
当使用指数形式表示时， 必须包含小数点、指数。带符号的指数是用 e 或 E 引入的
3.14159       // 合法的
314159E-5L    // 合法的
510E          // 非法的：不完整的指数
210f          // 非法的：没有小数或指数
.e55          // 非法的：缺少整数或分数
*/

// 布尔常量
/*
true 值代表真
false 值代表假
*/

// 字符常量
/*
字符常量是括在单引号中。如果常量以 L（仅当大写时）开头，则表示它是一个宽字符常量（例如 L'x'），此时它必须存储在 wchar_t 类型的变量中。
否则，它就是一个窄字符常量（例如 'x'），此时它可以存储在 char 类型的简单变量中.

#include <iostream>
using namespace std;

int main()
{
cout << "Hello\tWorld\n\n";
return 0;
}
*/

// 字符串常量
/*
字符串字面值或常量是括在双引号 "" 中的。一个字符串包含类似于字符常量的字符：普通的字符、转义序列和通用的字符
*/

// 定义常量
/*
在 C++ 中，有两种简单的定义常量的方式：
使用 #define 预处理器。
使用 const 关键字。
*/
// #define 预处理器  宏定义不能作为参数传递给函数,宏定义可以通过#undef来使之前的宏定义失效
#include <iostream>
using namespace std;

#define LENGTH 10   
#define WIDTH  5
#define NEWLINE '\n'

int main()
{

	int area;

	area = LENGTH * WIDTH;
	cout << "area的值是: " << area;
	cout << NEWLINE;
	return 0;
}

// const 关键字: const限定符定以后是不可以改变的，所以在定义时必须赋初始值，要不然是错误的。const常量可以在函数的参数列表中出现
/*
#include <iostream>
using namespace std;

int main()
{
const int  LENGTH = 10;
const int  WIDTH  = 5;
const char NEWLINE = '\n';
int area;

area = LENGTH * WIDTH;
cout << area;
cout << NEWLINE;
return 0;
}
*/
// 请注意，把常量定义为大写字母形式，是一个很好的编程实践
