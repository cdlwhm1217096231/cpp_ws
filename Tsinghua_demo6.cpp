#include <iostream>

using namespace std;

int main()
{
	int n, right_digit, newnum = 0;
	cout << "请输入一个数字: ";
	cin >> n;
	cout << "数字方向颠倒输出: ";
	do
	{
		right_digit = n % 10;
		cout << right_digit;
		n /= 10;
	} while (n != 0);
	cout << endl;
	return 0;
}