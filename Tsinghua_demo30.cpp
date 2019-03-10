#include <iostream>
using namespace std;
// 静态函数成员:如果把函数成员声明为静态的，就可以把函数与类的任何特定对象独立开来。
/*
静态成员函数即使在类的对象不存在的情况下也能被调用，静态函数只要使用类名加范围解析运算符::就可以访问。
静态成员函数只能访问静态成员数据、其他静态成员函数和类外部的其他函数。
*/
class Box{
public:
	static int count;
	Box(double l = 2.0, double w = 2.0, double h = 2.0):length(l), width(w), height(h){
		cout << "调用构造函数...." << endl;
		count++;
	}
	double volume(){
		return length*width*height;
	}
	// 静态成员函数定义
	static int getCount(){
		return count;
	}
private:
	double length, width, height;
};

int Box::count = 0; // 静态数据成员初始化

int main(){
	// 在创建对象之前输出对象的总数
	cout << "对象的初始个数:" << Box::getCount() << endl;
	Box box1(1.0, 2.0, 3.0),box2(3.0, 4.0, 5.0);
	cout << "类中对象的个数:" << Box::getCount() << endl;
	return 0;
}

