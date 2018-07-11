#include <iostream>

using namespace std;

int main()
{
	int x;
	unsigned int y = 100;
	unsigned int z = 50;
	x = y - z;
	cout << "Difference is " << x;
	x = z - y;
	cout << "\n Now difference is: " << x << endl;
	return 0;
}