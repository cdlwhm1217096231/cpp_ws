// c++数组5
/*
// 从函数返回数组
C++ 不允许返回一个完整的数组作为函数的参数。但是，您可以通过指定不带索引的数组名来返回一个指向数组的指针。
如果您想要从函数返回一个一维数组，您必须声明一个返回指针的函数
int * myFunction()
{
.
.
.
}
*/
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// 要生成和返回随机数的函数
int * getRandom()
{
	static int  r[10];

	// 设置种子
	srand((unsigned)time(NULL));
	for (int i = 0; i < 10; ++i)
	{
		r[i] = rand();
		cout << r[i] << endl;
	}

	return r;
}

// 要调用上面定义函数的主函数
int main()
{
	// 一个指向整数的指针
	int *p;

	p = getRandom();
	for (int i = 0; i < 10; i++)
	{
		cout << "*(p + " << i << ") : ";
		cout << *(p + i) << endl;
	}

	return 0;
}