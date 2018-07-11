#include <iostream>
// 复制构造函数举例
using namespace std;

class Point{
public:
	Point(int xx = 0, int yy = 0);  // 构造函数声明
	Point(const Point &p);  // 复制构造函数声明
	int getX() const { return x; } //常函数
	int getY() const { return y; }
private:
	int x, y;
};

// 构造函数实现
Point::Point(int xx, int yy) :x(xx), y(yy){}

// 情况1：复制构造函数实现
Point::Point(const Point &p){
	x = p.x;
	y = p.y;
	cout << "正在调用复制构造函数..." << endl;
}

//情况2： 形参为Point类对象的函数
void fun1(Point p){
	cout << p.getX() << endl;
}

//情况3： 返回值是Point类对象的函数
Point fun2(){
	Point a(1, 2);
	return a;
}

int main(){
	Point a(4, 5);  // 第一个对象a
	Point b(a);  // 情况一：用a初始化b，第一次调用复制构造函数
	cout << b.getX() << endl;
	fun1(b);  // 情况二：对象b作为fun1的实参，第二次调用复制构造函数
	b = fun2(); // 情况三：函数的返回值是类对象，函数返回时，第三次调用复制构造函数
	cout << b.getX() << endl;
	return 0;
}