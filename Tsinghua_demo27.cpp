#include <iostream>

using namespace std;

// 变量的作用域
void fun1();
int x = 1, y = 2;  // 全局作用域,全局变量

int main(){
	cout << "开始...." << endl;
	cout << "x = " << x << endl;
	cout << "y = " << y << endl;
	cout << "打印main()函数中的x,y的值: " << endl;
	int x = 10, y = 20;  // 变量的可见性:局部变量与全部变量同名，内层局部变量将屏蔽全局变量
	cout << "x = " << x << endl;
	cout << "y = " << y << endl;
	cout << "进入fun1()函数..." << endl;
	fun1();
	cout << "返回main()函数..." << endl;
	cout << "x = " << x << endl;
	cout << "y = " << y << endl;
	return 0;
}

void fun1(){
	int y = 200;  // 局部变量y与全局变量y同名，将会隐藏全局变量y的值
	cout << "x = " << x << endl;  // 输出全局变量中的x
	cout << "y = " << y << endl;
}