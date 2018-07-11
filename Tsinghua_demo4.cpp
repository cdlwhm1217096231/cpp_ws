#include <iostream>

using namespace std;

int main()
{
	int a, b;
	cout << "Entet a and b: ";
	cin >> a >> b;
	if (a != b)
	{
		if (a > b)
			cout << "a > b " << endl;
		else
			cout << "a < b " << endl;
	}
	else
		cout << "a = b" << endl;
	return 0;
}