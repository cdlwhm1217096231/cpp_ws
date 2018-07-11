#include <iostream>

using namespace std;

int fun1(int x, int y);
int fun2(int x1);

int main()
{
	int a, b;
	cout << "请输入第一个整数：" << "a = ";
	cin >> a;
	cout << "请输入第二个整数：" << "b = ";
	cin >> b;
	cout << "两个整数的平方和: " << fun1(a, b) << endl;
	return 0;
}

int fun1(int x, int y)
{
	return fun2(x) + fun2(y);
}

int fun2(int m)
{
	return m * m;
}