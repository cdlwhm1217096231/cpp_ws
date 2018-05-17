// 数组指针
/*
#include <iostream>

using namespace std;

const int MAX = 3;
int main()
{
	int var[MAX] = { 10, 100, 1000 };
	int *ptr;
	ptr = var;
	for (int i = 0; i < MAX; i++)
	{
		cout << "var[" << i << "]的值是：" << *ptr << endl;
		ptr++;
	}
	return 0;
}
*/
// 指针数组
/*
可能有一种情况，我们想要让数组存储指向 int 或 char 或其他数据类型的指针。下面是一个指向整数的指针数组的声明：
int *ptr[MAX];
在这里，把 ptr 声明为一个数组，由 MAX 个整数指针组成。因此，ptr 中的每个元素，都是一个指向 int 值的指针。
下面的实例用到了三个整数，它们将存储在一个指针数组中，如下所示：
*/
#include <iostream>

using namespace std;

const int MAX = 3;
int main()
{
	int var[MAX] = { 10, 100, 2000 };
	int *ptr[MAX]; // 指针数组
	for (int i = 0; i < MAX; i++)
	{
		ptr[i] = &var[i];  // 赋值为整数的地址
	}
	for (int i = 0; i < MAX; i++)
	{
		cout << "var[" << i << "]的值是：";
		cout << *ptr[i] << endl;

	}
	return 0;
}
/*
您也可以用一个指向字符的指针数组来存储一个字符串列表
#include <iostream>
 
using namespace std;
const int MAX = 4;
 
int main ()
{
 const char *names[MAX] = {
                   "Zara Ali",
                   "Hina Ali",
                   "Nuha Ali",
                   "Sara Ali",
   };
 
   for (int i = 0; i < MAX; i++)
   {
      cout << "Value of names[" << i << "] = ";
      cout << names[i] << endl;
   }
   return 0;
}
*/