// 函数调用时，实参作为参数传递给形参有三种方法
/*
// 1、值传递
#include <iostream>
using namespace std;

int add(int x, int y);

int main()
{
	int a, b, c;
	cout << "请输入a,b的值：" << endl;
	cin >> a >> b;
	c = add(a, b);
	cout << "c的值是：" << c << endl;
	cout << "a的值是：" << a << endl;
	cout << "b的值是：" << b << endl;
	return 0;

}

int add(int x, int y)
{
	int z,t;
	t = x;
	x = y;
	y = t;
	z = x + y;
	return z;
}
*/

// 按地址方式传递（地址、指针、数组）
#include <iostream>

using namespace std;

int cst(char *p);

int main()
{
	char str[100];
	int z;
	cout << "数字字符串为：" << endl;
	cin >> str;
	z = cst(str);
	cout << "z的值是：" << z << endl;
	return 0;
}

int cst(char *p)
{
	int sum = 0;
	while (*p)
	{
		int t;
		sum = sum * 10;
		t = *p - '0';
		sum = sum + t;
		p++;
	}
	return sum;
}
// 3、引用方式传递参数
/*
#include <iostream>
using namespace std;

void swap(int &a, int &b);

int main()
{
int x, y;
cout << "x的初始值是：" << endl;
cin >> x;
cout << "y的初始值是：" << endl;
cin >> y;
swap(x, y);
cout << "x的初始值是：" << x << endl;
cout << "y的初始值是：" << y << endl;
return 0;

}

void swap(int &a, int &b)
{
int temp;
temp = a;
a = b;
b = temp;
}
*/