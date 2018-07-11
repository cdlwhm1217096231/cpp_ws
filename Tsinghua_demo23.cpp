#include <iostream>
using namespace std;
// 构造函数:在每次创建类的对象时执行，构造函数名与类名相同，不返回任何数据，用来对成员变量设置初始值
class Line{
public:
	void setLine(double len);
	double getLine();
	Line(); //构造函数声明
private:
	double length;
};
// 构造函数的实现
Line::Line(){
	cout << "对象已经被创建!" << endl;
}

void Line::setLine(double len){
	length = len;
}

double Line::getLine(){
	return length;
}

int main(){
	Line line;  // 创建一个新的对象line时，将会执行Line()的构造函数
	line.setLine(6.0);
	cout << "线段的长度是: " << line.getLine() << endl;
	return 0;
}
// 上例是不带参数的构造函数