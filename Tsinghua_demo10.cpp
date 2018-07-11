#include <iostream>
#include <cmath>
using namespace std;
double tsin(double x);
const double Error = 1e-10;

int main()
{
	double r, s, k;
	cout << "请输入r的值: " << "r = ";
	cin >> r;
	cout << "请输入s的值：" << "s = ";
	cin >> s;
	if ((r*r) <= (s*s))
		k = sqrt(tsin(r)*tsin(r) + tsin(s)*tsin(s));
	else
		k = 1 / 2 * tsin(r*s);
	cout << " k = " << k << endl;
	return 0;

}


double tsin(double x)
{
	double g = 0.0;
	double t = x;
	int n = 1;
	do{
		g += t;
		n++;
		t = -t*x*x / (2 * n - 1) / (2 * n - 2);
	} while (fabs(t) >= Error);
	return g;
}