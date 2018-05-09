// 指针调用

/*
该方法把参数的地址复制给形式参数。在函数内，该地址用于访问调用中要用到的实际参数。
这意味着，修改形式参数会影响实际参数。
*/
#include <iostream>
using namespace std;

// 函数声明
void swap(int *x, int *y);

int main ()
{
   // 局部变量声明
   int a = 100;
   int b = 200;
 
   cout << "交换前，a 的值：" << a << endl;
   cout << "交换前，b 的值：" << b << endl;

   /* 调用函数来交换值
    * &a 表示指向 a 的指针，即变量 a 的地址 
    * &b 表示指向 b 的指针，即变量 b 的地址 
    */
   swap(&a, &b);

   cout << "交换后，a 的值：" << a << endl;
   cout << "交换后，b 的值：" << b << endl;
 
   return 0;
}
// 函数定义
void swap(int *x, int *y)
{
	int temp;
	temp = *x;    /* 保存地址 x 的值 */
	*x = *y;        /* 把 y 赋值给 x */
	*y = temp;    /* 把 x 赋值给 y */

	return;
}
// 引用调用
/*
该方法把参数的引用复制给形式参数。在函数内，该引用用于访问调用中要用到的实际参数。
这意味着，修改形式参数会影响实际参数。
#include <iostream>
using namespace std;

// 函数声明
void swap(int &x, int &y);

int main ()
{
   // 局部变量声明
   int a = 100;
   int b = 200;
 
   cout << "交换前，a 的值：" << a << endl;
   cout << "交换前，b 的值：" << b << endl;

   // 调用函数来交换值 
   swap(a, b);

   cout << "交换后，a 的值：" << a << endl;
   cout << "交换后，b 的值：" << b << endl;
 
   return 0;
}
// 函数定义
void swap(int &x, int &y)
{
   int temp;
   temp = x; // 保存地址 x 的值 
   x = y;    // 把 y 赋值给 x 
   y = temp; // 把 x 赋值给 y  
  
   return;
}
*/
// 参数的默认值
/*
调用函数时，如果未传递参数的值，则会使用默认值，如果指定了值，则会忽略默认值，使用传递的值
#include <iostream>
using namespace std;

int sum(int a, int b);

int main()
{
	int a = 200;
	int b = 300;
	int result;
	result = sum(a, b);
	cout << "result的值是：" << result << endl;
	result = sum(a);   // 使用默认参数
	cout << "result的值是：" << result << endl;

	return 0;
}
// 函数定义
int sum(int a, int b =20)
{
	int result;
	result = a + b;
	return result;
}
*/

// Lambda 函数与表达式
/*
Lambda 表达式具体形式： [capture](参数列表)->返回类型{函数体}
[](int x, int y) -> int { int z = x + y; return z + x; }

[]      // 沒有定义任何变量。使用未定义变量会引发错误。
[x, &y] // x以传值方式传入（默认），y以引用方式传入。
[&]     // 任何被使用到的外部变量都隐式地以引用方式加以引用。
[=]     // 任何被使用到的外部变量都隐式地以传值方式加以引用。
[&, x]  // x显式地以传值方式加以引用。其余变量以引用方式加以引用。
[=, &z] // z显式地以引用方式加以引用。其余变量以传值方式加以引用。
*/