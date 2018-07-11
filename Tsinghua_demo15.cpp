#include <iostream>
// 双向传递-------引用传递
using namespace std;
void swap(int &a, int &b);

int main(){
	int x = 1, y = 5;
	cout << "交换前的值: ";
	cout << "x = " << x << " y = " << y << endl;
	swap(x, y);
	cout << "交换后的值: ";
	cout << "x = " << x << " y = " << y << endl;
	return 0;
}

void swap(int &a, int &b){
	int t = a;
	a = b;
	b = t;
}