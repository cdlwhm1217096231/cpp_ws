// C++ 数组指针
// 一个指向数组开头的指针，可以通过使用指针的算术运算或数组索引来访问数组。请看下面的程序：
/*
#include <iostream>
 
using namespace std;
const int MAX = 3;
 
int main ()
{
   int  var[MAX] = {10, 100, 200};
   int  *ptr;
 
   // 指针中的数组地址
   ptr = var;
   for (int i = 0; i < MAX; i++)
   {
      cout << "var[" << i << "]的内存地址为 ";
      cout << ptr << endl;
 
      cout << "var[" << i << "] 的值为 ";
      cout << *ptr << endl;
 
      // 移动到下一个位置
      ptr++;
   }
   return 0;
}
*/
// 然而，指针和数组并不是完全互换的
#include <iostream>

using namespace std;
const int MAX = 3;

int main()
{
	int  var[MAX] = { 10, 100, 200 };

	for (int i = 0; i < MAX; i++)
	{
		*(var+2) = 600;
		cout << var[i] << endl;
     // 这是不正确的 var++;     
	}
	return 0;
}

