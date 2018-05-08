// c++修饰符
/*
C++ 允许在 char、int 和 double 数据类型前放置修饰符。修饰符用于改变基本类型的含义
signed  unsigned long short
修饰符 signed、unsigned、long 和 short 可应用于整型
signed 和 unsigned 可应用于字符型
long 可应用于双精度型
修饰符 signed 和 unsigned 也可以作为 long 或 short 修饰符的前缀。例如：unsigned long int
C++ 允许使用速记符号来声明无符号短整数或无符号长整数。可以不写 int，只写单词 unsigned、short 或 unsigned、long，int 是隐含的
unsigned x;
unsigned int y;
*/
#include <iostream>
using namespace std;

/*
* 这个程序演示了有符号整数和无符号整数之间的差别
*/
int main()
{
	short int i;                  // 有符号短整数
	unsigned short int j;        // 无符号短整数

	j = 50000;

	i = j;
	cout << "i = " << i << endl;
	cout << "j = " << j << endl;

	return 0;
}
