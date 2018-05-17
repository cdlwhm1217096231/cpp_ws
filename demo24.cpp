// C++ 指向指针的指针
/*
指向指针的指针是一种多级间接寻址的形式，或者说是一个指针链。通常，一个指针包含一个变量的地址。
当我们定义一个指向指针的指针时，第一个指针包含了第二个指针的地址，第二个指针指向包含实际值的位置。
//一个指向指针的指针变量必须如下声明，即在变量名前放置两个星号。例如，下面声明了一个指向 int 类型指针的指针：
int **var;
*/
#include <iostream>

using namespace std;

int main()
{
	int  var;
	int  *ptr;
	int  **pptr;  // 指向指针的指针

	var = 3000;

	// 获取 var 的地址
	ptr = &var;

	// 使用运算符 & 获取 ptr 的地址
	pptr = &ptr;

	// 使用 pptr 获取值
	cout << "var的值是 :" << var << endl;
	cout << "*ptr的值是 :" << *ptr << endl;
	cout << "**pptr的值是 :" << **pptr << endl;

	return 0;
}