// c++判断


// if语句
/*
一个 if 语句 由一个布尔表达式后跟一个或多个语句组成。

#include <iostream>
using namespace std;
 
int main ()
{
   // 局部变量声明
   int a = 10;
 
   // 使用 if 语句检查布尔条件
   if( a < 20 )
   {
       // 如果条件为真，则输出下面的语句
       cout << "a 小于 20" << endl;
   }
   cout << "a 的值是 " << a << endl;
 
   return 0;
}
*/

// if...else 语句
/*
一个 if 语句 后可跟一个可选的 else 语句，else 语句在布尔表达式为假时执行。

#include <iostream>
using namespace std;
 
int main ()
{
   // 局部变量声明
   int a = 100;
 
   // 检查布尔条件
   if( a < 20 )
   {
       // 如果条件为真，则输出下面的语句
       cout << "a 小于 20" << endl;
   }
   else
   {
       // 如果条件为假，则输出下面的语句
       cout << "a 大于 20" << endl;
   }
   cout << "a 的值是 " << a << endl;
 
   return 0;
}
*/

// 嵌套 if 语句

/*
可以在一个 if 或 else if 语句内使用另一个 if 或 else if 语句

#include <iostream>
using namespace std;
 
int main ()
{
   // 局部变量声明
   int a = 100;
   int b = 200;
 
   // 检查布尔条件
   if( a == 100 )
   {
       // 如果条件为真，则检查下面的条件
       if( b == 200 )
       {
          // 如果条件为真，则输出下面的语句
          cout << "a 的值是 100，且 b 的值是 200" << endl;
       }
   }
   cout << "a 的准确值是 " << a << endl;
   cout << "b 的准确值是 " << b << endl;
 
   return 0;
}
*/

// switch语句
/*
一个 switch 语句允许测试一个变量等于多个值时的情况。每个值称为一个 case，且被测试的变量会对每个 switch case 进行检查。
#include <iostream>
using namespace std;
 
int main ()
{
   // 局部变量声明
   char grade = 'D';
 
   switch(grade)
   {
   case 'A' :
      cout << "很棒！" << endl; 
      break;
   case 'B' :
   case 'C' :
      cout << "做得好" << endl;
      break;
   case 'D' :
      cout << "您通过了" << endl;
      break;
   case 'F' :
      cout << "最好再试一下" << endl;
      break;
   default :
      cout << "无效的成绩" << endl;
   }
   cout << "您的成绩是 " << grade << endl;
 
   return 0;
}
*/

// switch语句嵌套
/*
可以在一个 switch 语句内使用另一个 switch 语句。即使内部和外部 switch 的 case 常量包含共同的值，也没有矛盾。
*/
#include <iostream>
using namespace std;

int main()
{
	// 局部变量声明
	int a = 100;
	int b = 200;

	switch (a) {
	case 100:
		cout << "这是外部 switch 的一部分" << endl;
		switch (b) {
		case 200:
			cout << "这是内部 switch 的一部分" << endl;
		}
	}
	cout << "a 的准确值是 " << a << endl;
	cout << "b 的准确值是 " << b << endl;

	return 0;
}

// ? : 运算符

/*
Exp1 ? Exp2 : Exp3;
? : 表达式的值取决于 Exp1 的计算结果。
如果 Exp1 为真，则计算 Exp2 的值，且 Exp2 的计算结果则为整个 ? : 表达式的值。
如果 Exp1 为假，则计算 Exp3 的值，且 Exp3 的计算结果则为整个 ? : 表达式的值。
#include <iostream>
using namespace std;
 
int main ()
{
   // 局部变量声明
   int x, y = 10;

   x = (y < 10) ? 30 : 40;

   cout << "value of x: " << x << endl;
 
   return 0;
}
*/
