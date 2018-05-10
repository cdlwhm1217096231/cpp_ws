// c++数组3
/*
// 指向数组的指针
可以通过指定不带索引的数组名称来生成一个指向数组中第一个元素的指针
数组名是一个指向数组中第一个元素的常量指针 如：double balance[50]; balance 是一个指向 &balance[0] 的指针，即数组 balance 的第一个元素的地址

下面的程序段把 p 赋值为 balance 的第一个元素的地址：
double *p;
double balance[10];
p = balance;
*/
#include <iostream>
using namespace std;

int main()
{
	int a[5] = { 1, 2, 3, 4, 5 };
	int *p;
	p = a;
	// 输出数组中每个元素的值
	cout << "使用指针的数组值: " << endl;
	for (int i = 0; i < 5; i++)
	{
		cout << "*(p + " << i << "): " << *(p + i) << endl;
	}
	cout << "使用a的数组值：" << endl;
	for (int i = 0; i < 5; i++)
	{
		cout << "*(a + " << i << "): " << *(a + i) << endl;
	}
	return 0;
}