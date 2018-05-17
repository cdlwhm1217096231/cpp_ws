#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	for (int m = 1; m < 10; m++)
	{
		for (int n = 1; n < 10; n++)
			cout << setw(4) << m*n;
		cout << endl;
	}
	return 0;
}