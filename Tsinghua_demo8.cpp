#include <iostream>
using namespace std;

double power(double x, int n);

int main()
{
	int value = 0;
	cout << "请输入一个8位二进制数: ";
	for (int i = 7; i >= 0; i--)
	{
		char ch;
		cin >> ch;
		if (ch == '1')
			value += static_cast<int> (power(2, i));
	}
	cout << "转化为十进制数的结果: " << value << endl;
	return 0;
}

double power(double x, int n)
{
	double val = 1.0;
	while (n--)
		val *= x;
	return val;
}