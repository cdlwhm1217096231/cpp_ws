#include <iostream>

using namespace std;
unsigned int fac(int n);

int main()
{
	unsigned int m;
	cout << "请输入一个整数：" << "m = ";
	cin >> m;
	cout << "一个整数的阶乘: " << fac(m) << endl;
	return 0;
}

// 计算n的阶乘
unsigned int fac(int n)
{
	unsigned f;
	if (n == 0)
		f = 1;
	else
		f = n * fac(n - 1);
	return f;
}