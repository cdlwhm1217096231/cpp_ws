#include <iostream>
using namespace std;

class Point{
public:
	Point(int x = 0, int y = 0){ xx = x; yy = y; }; // 带默认参数的内联构造函数
	Point(const Point &p); // 复制构造函数的声明
	void setX(int x) { xx = x; } // 内联成员函数
	void setY(int y) { yy = y; }
	int getX() const { return xx; }  // 常函数
	int getY() const { return yy; }
private:
	int xx, yy;
};
// 复制构造函数实现
Point::Point(const Point &p){
	xx = p.xx;
	yy = p.yy;
	cout << "调用复制构造函数....\n";
}

// 情况2：形参为Point类的对象p
void fun1(Point p){
	cout << p.getX() << endl;
}

// 情况3：函数的返回值是Point类的对象a
Point fun2(){
	Point a(4, 5);
	return a;
}

int main(){
	Point a(1, 2);
	Point b(a); // 情况1：以本类的另一个对象a初始化对象b
	cout << b.getX() << endl;
	cout << b.getY() << endl;
	fun1(b);  // 情况2：使用对象b来作为fun1()函数的实参
	b = fun2(); // 情况3：函数的返回值是类的某个对象
	cout << b.getX() << endl;
	return 0;
}