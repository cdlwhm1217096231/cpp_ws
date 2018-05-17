// C++ 指针
/*
每一个变量都有一个内存位置，每一个内存位置都可使用连字号（&）运算符访问的地址，它表示变量在内存中的一个地址

#include <iostream>
using namespace std;

int main()
{
	int var = 3;
	int vb[3] = { 1, 2, 3 };
	cout << "变量var的地址：" << &var << endl;
	cout << "数组vb的地址：" << &vb << endl;
	return 0;
}
*/
// 什么是指针？
/*
指针是一个变量，其值为另一个变量的地址
指针变量声明的一般形式为：指针的基类型 *变量名
int    *ip; //  一个整型的指针
double *dp; //  一个 double 型的指针
char   *ch; //  一个字符型的指针
*/

// C++ 中使用指针
/*
使用指针时会频繁进行以下几个操作：定义一个指针变量、把变量地址赋值给指针、访问指针变量中可用地址的值。
这些是通过使用一元运算符 * 来返回位于操作数所指定地址的变量的值
#include <iostream>
using namespace std;
int main()
{
	int var = 10;
	int *p;
	p = &var;
	cout << "var的值是：" << var << endl;
	cout << "指针变量p中存储var的地址是：" << p << endl;
	cout << "访问指针变量p中存储的地址的值：" << *p << endl;
	return 0;
}
*/
// C++ 指针详解
/*
1.C++ Null 指针
在变量声明的时候，如果没有确切的地址可以赋值，为指针变量赋一个 NULL 值是一个良好的编程习惯。赋为 NULL 值的指针被称为空指针。
#include <iostream>
using namespace std;
int main()
{
	int *p = NULL;
	cout << "变量p的值：" << p << endl;
	return 0;
}
2.C++ 指针的算术运算
指针是一个用数值表示的地址。因此，您可以对指针执行算术运算。可以对指针进行四种算术运算：++、--、+、-
// 递增一个指针
#include <iostream>

using namespace std;

int main()
{
	int a[3] = { 1, 10, 100 };
	int *ptr;
	ptr = a;  // 将数组的首地址即数组名赋值给ptr
	for (int i = 0; i < 3; i++)
	{
		cout << "a[" << i << "]" << "的地址是：" << ptr << endl;
		cout << "a[" << i << "]" << "的值是：" << *ptr << endl;
		ptr++;  // 移动到下一个位置
	}
	return 0;
}
// 递减一个指针
#include <iostream>

using namespace std;
const int MAX = 3;

int main ()
{
   int  var[MAX] = {10, 100, 200};
   int  *ptr;

   // 指针中最后一个元素的地址
   ptr = &var[MAX-1];
   for (int i = MAX; i > 0; i--)
   {
      cout << "Address of var[" << i << "] = ";
      cout << ptr << endl;

      cout << "Value of var[" << i << "] = ";
      cout << *ptr << endl;

      // 移动到下一个位置
      ptr--;
   }
   return 0;
}
*/

// 指针的比较
/*
指针可以用关系运算符进行比较，如 ==、< 和 >。
如果 p1 和 p2 指向两个相关的变量，比如同一个数组中的不同元素，则可对 p1 和 p2 进行大小比较。
数组的最后一个元素的地址 &var[MAX - 1]
*/
#include <iostream>

using namespace std;
const int MAX = 3;

int main()
{
	int var[MAX] = { 10, 100, 1000 };
	int *ptr;
	ptr = var;
	int i = 0;
	while (ptr <= &var[MAX - 1]) // 指针的比较
	{
		cout << "var[" << i << "]的地址是：" << ptr << endl;
		cout << "var[" << i << "]的值是：" << *ptr << endl;
		ptr++;
		i++;
	}
	return 0;
}

