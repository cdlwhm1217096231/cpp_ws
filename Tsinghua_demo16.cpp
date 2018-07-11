#include <iostream>
#include <iomanip>
// 带默认参数值的函数
using namespace std;
int getVolume(int length, int width = 3, int height = 4);
int main(){
	const int X = 10, Y = 20, Z = 30;
	cout << "长方体的体积1: " << endl;
	cout << getVolume(X, Y, Z) << endl;
	cout << "长方体的体积2: " << endl;
	cout << getVolume(X, Y) << endl;
	cout << "长方体的体积3: " << endl;
	cout << getVolume(X) << endl;
}

int getVolume(int length, int width, int height){
	cout << length << setw(5) << width << setw(5) << height << endl;
	return length * width * height;
}
