#include <iostream>
using namespace std;

class Box{
public:
	double length;
	double width;
	double height;
public:
	void getVolume(double a, double b, double c);
	void printVolume();
	// 内联成员函数
	double getVolume1(){return length * width * height;}

};

int main(){
	Box box1, box2; // 创建一个Box类的对象box1
	/*box1.length = 3;
	box1.width = 4;
	box1.height = 5;*/
	box1.getVolume(3.0, 4.0, 5.0); // 调用该对象的成员函数
	box1.printVolume();

	box2.getVolume(30.0, 4.0, 5.0);
	box2.printVolume();
	return 0;
}

void Box::getVolume(double a, double b, double c){
	length = a;
	width = b;
	height = c;
}

void Box::printVolume(){
	double volume = 0.0;
	volume = length * width * height;
	cout << "长方体的体积是: " << volume << endl;
}
