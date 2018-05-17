/*
#include <iostream>

using namespace std;

int main()
{
	int i = 5;
	double k = 4.5;
	cout << "i的值是：" << i << endl;
	cout << "i的地址是：" << &i << endl;
	cout << "k的值是：" << k << endl;
	cout << "k的地址是: " << &k << endl;
	return 0;

}
*/

// 指针的使用
/*
#include <iostream>

using namespace std;

int main()
{
int a = 6;
int *p;  // 指针变量的声明
p = &a;
cout << "a的值是：" << a ;
cout << ", *p的值是：" << *p << endl;
*p += 1;
cout << "*p的更新值是：" << *p << endl;
return 0;

}
// 指针变量*p与变量a等价，变量p表示变量a的地址，而*运算符来获得a变量的值
*/

#include <iostream>

using namespace std;
int main()
{
	int a[5] = { 1, 2, 3, 4, 5 };
	int *var = a;
	cout << "a[0]的值是：" << a[0] << endl;
	cout << "*var的值是: " << *var << endl;
	var = &a[2];
	cout << "*var的值是：" << *var << endl;
	var = var + 1;
	cout << "*var的值是：" << *var << endl;
	return 0;

}


