#include <iostream>
using namespace std;
// 类的静态数据成员
/*当我们声明类的成员为静态时，这意味着无论创建多少个类的对象，静态成员都只有一个副本。*/
class Box{
public:
	static int count;  // 定义一个静态数据成员
	Box(double l = 2.0, double w = 2.0, double h = 2.0):length(l), width(w), height(h){
		cout << "调用构造函数...." << endl;
		count++;
	}
	double volume();
private:
	double length;
	double width;
	double height;
};
// 类外初始化静态数据成员
int Box::count = 0;

int main(){
	Box box1(1.5, 2.0, 3.0);
	Box box2(2.0, 3.0, 10.2);
	cout << "输出对象的个数:" << Box::count << endl;
	return 0;
}

double Box::volume(){
	return length * width * height;
}


