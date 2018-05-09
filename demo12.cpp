// c++函数

/*
函数是一组一起执行一个任务的语句。每个 C++ 程序都至少有一个函数，即主函数 main()
函数声明: 告诉编译器函数的名称、返回类型和参数。
函数定义: 提供了函数的实际主体。
C++ 标准库提供了大量的程序可以调用的内置函数。例如，函数 strcat() 用来连接两个字符串，函数 memcpy() 用来复制内存到另一个位置。
*/

// 定义函数
/*
返回值类型 函数名( 参数列表 )
{
   函数体
}

int max(int num1, int num2) 
{
   // 局部变量声明
   int result;
 
   if (num1 > num2)
      result = num1;
   else
      result = num2;
 
   return result; 
}
*/

// 函数声明
/*
函数声明: 会告诉编译器函数名称及如何调用函数。函数的实际主体可以单独定义。
函数声明包括以下几个部分： 返回值类型 函数名( 参数列表 );

当您在一个源文件中定义函数且在另一个文件中调用函数时，函数声明是必需的。
在这种情况下，您应该在调用函数的文件顶部声明函数。
*/

// 调用函数
/*
#include <iostream>
using namespace std;
 
// 函数声明
int max(int num1, int num2);
 
int main ()
{
   // 局部变量声明
   int a = 100;
   int b = 200;
   int ret;
 
   // 调用函数来获取最大值
   ret = max(a, b);
 
   cout << "Max value is : " << ret << endl;
 
   return 0;
}
 
// 函数返回两个数中较大的那个数
int max(int num1, int num2) 
{
   // 局部变量声明
   int result;
 
   if (num1 > num2)
      result = num1;
   else
      result = num2;
 
   return result; 
}
*/

// 函数参数
/*
形式参数就像函数内的其他局部变量，在进入函数时被创建，退出函数时被销毁。
*/

// 传值调用
// 该方法把参数的实际值复制给函数的形式参数。在这种情况下，修改函数内的形式参数对实际参数没有影响。
#include <iostream>
using namespace std;

// 函数声明
void swap(int x, int y);

int main()
{
	// 局部变量声明
	int a = 100;
	int b = 200;

	cout << "交换前，a 的值：" << a << endl;
	cout << "交换前，b 的值：" << b << endl;

	// 调用函数来交换值
	swap(a, b);

	cout << "交换后，a 的值：" << a << endl;
	cout << "交换后，b 的值：" << b << endl;

	return 0;
}

// 函数定义
void swap(int x, int y)
{
	int temp;

	temp = x; /* 保存 x 的值 */
	x = y;    /* 把 y 赋值给 x */
	y = temp; /* 把 x 赋值给 y */

	return;
}
