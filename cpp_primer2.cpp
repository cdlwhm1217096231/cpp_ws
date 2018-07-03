#include <iostream>
#include <cmath>
using namespace std;
/*
int main()
{
	int carrots;  // 指明需要的内存大小和指定内存单元的名称
	carrots = 25;
	cout << "I have ";
	cout << carrots;
	cout << " carrots.";
	cout << endl;
	carrots -= 1;
	cout << "Crunch, Now I have " << carrots << " carrots." << endl;
	return 0;

}
*/
int main()
{
	int carrots;
	double area, side;
	cout << "How many carrots do you have?" << endl;
	cin >> carrots;
	cout << "Here two more. ";
	carrots += 2;
	cout << "Crunch, Now I have " << carrots << " carrots." << endl;

	cout << "Enter your home area." << endl;
	cin >> area;
	side = sqrt(area);
	cout << "T hat's the equivalent of a square " << side << " feet to the side." << endl;
	return 0;
}


