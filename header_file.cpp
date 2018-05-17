#include <iostream>
#include "header_file.h"
using namespace std;

int main()
{
	Rec A;
	A.rec_init(3, 6);
	A.show();
}
// 类定义文件放在头文件中，cpp文件放入主函数