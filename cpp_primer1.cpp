#include <iostream>  // 预处理器编译指令 #include

using namespace std;
int main()
{
	cout << "Come up and c++ me some time."; // 使用cin 和cout进行输入和输出的程序必须包含文件 iostream 
	cout << endl;
	cout << "You won't regret it!" << endl;
	return 0; // 结束 main() 函数的 return 语句
}

// 不推荐写法
/*
没有using namespace std;这条语句时

int main()
{
	std::cout << "Come up and c++ me some time.";
	std::endl;
	std::cout << "You won't regret it!" << endl;
	return 0;
}



*/