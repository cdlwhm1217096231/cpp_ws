#include <iostream>

using namespace std;

int main()
{
	int a, b, x;
	cout << "input value of a: \n";
	cin >> a;
	cout << "input value of b: \n";
	cin >> b;

	x = a - b > 0 ? a - b : b - a;
	cout << "The difference of a and b is: " << x << endl;
	return 0;
}