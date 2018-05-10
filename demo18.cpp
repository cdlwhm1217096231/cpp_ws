// c++数组4
// 传递数组给函数
/*
可以通过指定不带索引的数组名称来给函数传递一个指向数组的指针
C++ 传一个数组给函数，数组类型自动转换为指针类型，因而传的实际是地址

如果想要在函数中传递一个一维数组作为参数，您必须以下面三种方式来声明函数形式参数
这三种声明方式的结果是一样的，因为每种方式都会告诉编译器将要接收一个整型指针。
同样地，您也可以传递一个多维数组作为形式参数

// 方式1
形式参数是一个指针：
void myFunction(int *param)
{
.
.
.
}

// 方式2
形式参数是一个已定义大小的数组：
void myFunction(int param[10])
{
.
.
.
}

//方式3
形式参数是一个未定义大小的数组：
void myFunction(int param[])
{
.
.
.
}
*/
#include <iostream>
using namespace std;

// 函数声明
double getAverage(int arr[], int size);

int main()
{
	// 带有 5 个元素的整型数组
	int balance[5] = { 1000, 2, 3, 17, 50 };
	double avg;

	// 传递一个指向数组的指针作为参数
	avg = getAverage(balance, 5);

	// 输出返回值
	cout << "平均值是：" << avg << endl;

	return 0;
}

// 函数定义
double getAverage(int arr[], int size)
{
	int    i, sum = 0;
	double avg;

	for (i = 0; i < size; ++i)
	{
		sum += arr[i];
	}

	avg = double(sum) / size;

	return avg;
}
