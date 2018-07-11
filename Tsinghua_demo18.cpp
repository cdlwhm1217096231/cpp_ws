#include <iostream>
// 构造函数：在对象被创建时，进行初始化对象
using namespace std;

class Clock{
public:
	Clock(int newH, int newM, int newS); //构造函数的声明
	Clock(); // 默认构造函数
	void setTime(int newH, int newM, int newS);
	void showTime();
private:
	int hour, minute, second;
};

int main(){
	Clock c(0, 0, 0); // 构造函数的调用
	Clock c1;   // 无参数的构造函数调用
	c.showTime();
	c1.showTime();
	return 0;
}

void Clock::setTime(int newH, int newM, int newS){
	hour = newH;
	minute = newM;
	second = newS;
}

void Clock::showTime(){
	cout << "现在时间是: ";
	cout << hour << ":" << minute << ":" << second << endl;
}

// 构造函数的实现
Clock::Clock(int newH, int newM, int newS): hour(newH), minute(newM), second(newS){
}

// 默认构造函数的实现
Clock::Clock() : hour(10), minute(10), second(10){
}