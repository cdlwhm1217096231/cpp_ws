#include<iostream>
#include "client.h"
using namespace std;
// 使用Client类
int Client::clientNum = 0; // 静态数据成员不属于任何类的对象，所以要在类外进行单独初始化
char Client::serverName = 'a';
int main(){
	Client c1;
	c1.changeServerName('a');
	cout << "当前客户机数量: " << c1.getClientNum() << endl;
	Client c2;
	c2.changeServerName('b');
	cout << "当前客户机数量: " << c2.getClientNum() << endl;
	return 0;
}