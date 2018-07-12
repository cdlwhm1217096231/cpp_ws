#ifndef CLIENT_H_ //为了避免重复包含头文件，需要使用编译预处理指令
#define CLIENT_H_
// Client类的定义
class Client{
	static char serverName; // 静态数据成员
	static int clientNum;  //静态数据成员
public:
	static void changeServerName(char name);
	static int getClientNum();
};

#endif // CLIENT_H_