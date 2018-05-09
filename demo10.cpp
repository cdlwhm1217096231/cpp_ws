// c++循环
/*
// while循环

只要给定的条件为真，while 循环语句会重复执行一个目标语句。
#include <iostream>
using namespace std;

int main ()
{
// 局部变量声明
int a = 10;

// while 循环执行
while( a < 20 )
{
cout << "a 的值：" << a << endl;
a++;
}

return 0;
}
*/

// for 循环
/*
#include <iostream>
using namespace std;

int main ()
{
// for 循环执行
for( int a = 10; a < 20; a++)
{
cout << "a 的值：" << a << endl;
}

return 0;
}
*/

// do...while 循环
/*
不像 for 和 while 循环，它们是在循环头部测试循环条件。do...while 循环是在循环的尾部检查它的条件
do...while 循环会确保至少执行一次循环

#include <iostream>
using namespace std;

int main ()
{
// 局部变量声明
int a = 10;

// do 循环执行
do
{
cout << "a 的值：" << a << endl;
a = a++;
}while( a < 20 );

return 0;
}
*/

// 嵌套循环
/*
#include <iostream>
using namespace std;
 
int main ()
{
    int i, j;
    for(i=2; i<100; i++) {
        for(j=2; j <= (i/j); j++) {
            if(!(i%j)) {
                break; // 如果找到，则不是质数
            }
        }
        if(j > (i/j)) {
            cout << i << " 是质数\n";
        }
    }
    return 0;
}
*/
#include <iostream>
using namespace std;

int main()
{
	int i, j;
	for (i = 2; i<100; i++) {
		for (j = 2; j <= (i / j); j++) {
			if (!(i%j)) {
				break; // 如果找到，则不是质数
			}
		}
		if (j >(i / j)) {
			cout << i << " 是质数\n";
		}
	}
	return 0;
}

// 循环控制语句
/*
break 语句             

当 break 语句出现在一个循环内时，循环会立即终止，且程序流将继续执行紧接着循环的下一条语句
它可用于终止 switch 语句中的一个 case
#include <iostream>
using namespace std;
 
int main ()
{
   // 局部变量声明
   int a = 10;

   // do 循环执行
   do
   {
       cout << "a 的值：" << a << endl;
       a = a + 1;
       if( a > 15)
       {
          // 终止循环
          break;
       }
   }while( a < 20 );
 
   return 0;
}
continue 语句

continue 会跳过当前循环中的代码，强迫开始下一次循环。

#include <iostream>
using namespace std;
 
int main ()
{
   // 局部变量声明
   int a = 10;

   // do 循环执行
   do
   {
       if( a == 15)
       {
          // 跳过迭代
          a = a + 1;
          continue;
       }
       cout << "a 的值：" << a << endl;
       a = a + 1;
   }while( a < 20 );
 
   return 0;
}
goto 语句
goto 语句允许把控制无条件转移到同一函数内的被标记的语句。
*/
