#include <iostream>
using namespace std;

// 变量声明
extern int a, b;
extern int c;
extern float f;

int main()
{
	// 变量定义
	int a, b;
	int c;
	float f;

	// 实际初始化
	a = 10;
	b = 20;
	c = a + b;

	cout << c << endl;

	f = 70.0 / 3.0;
	cout << f << endl;

	return 0;
}
/*
变量的名称可以由字母、数字和下划线字符组成。它必须以字母或下划线开头。大写字母和小写字母是不同的，因为 C++ 是大小写敏感的
变量定义: int    i, j, k;
变量初始化: int d = 3, f = 5; 
变量声明: extern int a, b;
*/

// 在函数声明时，提供一个函数名，而函数的实际定义则可以在任何地方进行
/*
函数声明
int func();

int main()
{
函数调用
int i = func();
}

函数定义
int func()
{
return 0;
}
*/