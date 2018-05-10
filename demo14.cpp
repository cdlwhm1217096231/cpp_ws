// c++数字
/*
#include <iostream>
using namespace std;
 
int main ()
{
   // 数字定义
   short  s;
   int    i;
   long   l;
   float  f;
   double d;
   
   // 数字赋值
   s = 10;      
   i = 1000;    
   l = 1000000; 
   f = 230.47;  
   d = 30949.374;
   
   // 数字输出
   cout << "short  s :" << s << endl;
   cout << "int    i :" << i << endl;
   cout << "long   l :" << l << endl;
   cout << "float  f :" << f << endl;
   cout << "double d :" << d << endl;
 
   return 0;
}
*/

// C++ 数学运算
/*
在 C++ 中，除了可以创建各种函数，还包含了各种有用的函数供您使用。这些函数写在标准 C 和 C++ 库中，叫做内置函数。
为了利用这些函数，您需要引用数学头文件 <cmath>
double floor(double);   该函数返回一个小于或等于传入参数的最大整数
double ceil(double);   该函数返回一个大于或等于传入参数的最大整数
double fabs(double);    该函数返回任意一个十进制数的绝对值。
double cos(double);     该函数返回弧度角（double 型）的余弦。
double hypot(double, double);   该函数返回两个参数的平方总和的平方根，也就是说，参数为一个直角三角形的两个直角边，函数会返回斜边的长度
*/
#include <iostream>
#include <cmath>

using namespace std;
int main()
{
	// 数字定义
	short i = 10;
	int j = -1000;
	long k = 100000;
	float l = 234.5;
	double m = -35.678;
	// 数学运算
	cout << "sin(m)的值是：" << sin(m) << endl;
	cout << "floor(m)的值是：" << floor(m) << endl;
	cout << "ceil(l)的值是：" << ceil(l) << endl;
	cout << "abs(m)的值是：" << abs(m) << endl;
	cout << "pow(i,2)的值是：" << pow(i,2) << endl;
}
// C++ 随机数
/*
关于随机数生成器，有两个相关的函数。一个是 rand()，该函数只返回一个伪随机数。生成随机数之前必须先调用 srand() 函数。
#include <iostream>
#include <ctime>   // 用到了time函数，所以要有这个头文件
#include <cstdlib>
 
using namespace std;
 
int main ()
{
   int i,j;
 
   // 设置种子
   srand( (unsigned)time( NULL ) );
 
   // 生成 10 个随机数 
   for( i = 0; i < 10; i++ )
   {
      // 生成实际的随机数
      j= rand();
      cout <<"随机数： " << j << endl;
   }
 
   return 0;
}
*/