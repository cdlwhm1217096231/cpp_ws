#include <iostream>
using namespace std;

class Clock{
public:
	void setTime(int newH, int newM, int newS);
	void showTime();
	Clock(int newH, int newM, int newS);  // 构造函数声明
	Clock();							 // 带默认参数的构造函数声明
private:
	int hour;
	int minute;
	int second;
};

void Clock::setTime(int newH, int newM, int newS){
	hour = newH;
	minute = newM;
	second = newS;
}

void Clock::showTime(){
	cout << "现在时间是: ";
	cout << hour << ":" << minute << ":" << second << endl;
}

// 构造函数实现1
Clock::Clock(int newH, int newM, int newS) : hour(newH), minute(newM), second(newS){ 
	cout << "构造函数的实现功能1" << endl;
}

// 构造函数实现2
Clock::Clock(): hour(0), minute(23), second(221){
	cout << "带默认参数的构造函数实现\n";
}

int main(){
	Clock myclock(10, 12, 0);
	myclock.showTime();

	Clock c;
	c.showTime();

	myclock.setTime(0, 0, 0);
	myclock.showTime();
	return 0;
}