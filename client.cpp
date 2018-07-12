#include "client.h"
// Client类的实现
void Client::changeServerName(char name){
	Client::serverName = name; // 访问静态数据成员时，要加上类名
	Client::clientNum++;      // 访问静态数据成员时，要加上类名
}

int Client::getClientNum(){
	return Client::clientNum;
}