#include <iostream>
using namespace std;

struct MyTimeDate
{
	unsigned int year;
	unsigned int month;
	unsigned int day;

	unsigned int hour;
	unsigned int min;
	unsigned int sec;
};

int main()
{
	MyTimeDate mytime = { 2018, 7, 8, 16, 06, 57 };  // 结构体变量初始化
	cout << "请输入年份: " << endl;
	cin >> mytime.year;
	cout << "请输入月份: " << endl;
	cin >> mytime.month;
	cout << "请输入哪一天: " << endl;
	cin >> mytime.day;


	cout << "请输入小时: " << endl;
	cin >> mytime.hour;
	cout << "请输入分钟: " << endl;
	cin >> mytime.min;
	cout << "请输入秒数: " << endl;
	cin >> mytime.sec;

	cout << "最后的时间显示：";
	cout << mytime.year << "-"
		<< mytime.month << "-"
		<< mytime.day << " "
		<< mytime.hour << ":"
		<< mytime.min << ":"
		<< mytime.sec << endl;
	return 0;
}