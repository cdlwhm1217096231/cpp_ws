#include <iostream>
using namespace std;

/*void simon(int n); // 函数声明，且函数无返回值

int main()
{
	simon(3);
	cout << "Pick an integer: ";
	int count;
	cin >> count;
	simon(count);
	cout << "Done!" << endl;
	return 0;
}

void simon(int n)
{
	cout << "Simon says touch your toes " << n << " times ." << endl;
}
*/
// 函数有返回值情况
int stonelib(int n);

int main()
{
	int stone;
	cout << "Enter the weight in stone: ";
	cin >> stone;
	int pounds;
	pounds = stonelib(stone);
	cout << stone << " stone = ";
	cout << pounds << " pounds." << endl;
	return 0;
}

int stonelib(int n)
{
	int pounds;
	pounds = 14 * n;
	return pounds;
}
/*
总结：
声明语句：定义函数中使用的变量的名称和类型
赋值语句：使用赋值运算符=给变量赋值
消息语句：将消息发送给对象，激发某种行动
函数凋用：执行函数。被调用的函数执行完毕后，程序返回到函数调用语句后面的语句
函数原型：声明函数的返回类型、函数接受的参数数量和类型
返回语句：将一个值从被调用的函数那里返回到调用函数中
*/
