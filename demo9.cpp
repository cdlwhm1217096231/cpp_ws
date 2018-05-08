// c++运算符:  算术运算符 关系运算符 逻辑运算符 位运算符 赋值运算符 杂项运算符



// 算术运算符

/* 
#include <iostream>

int main()
{
	int a = 21;
	int b = 10;
	int c;

	c = a + b;
	std::cout << "Line 1 - c 的值是 " << c << std::endl;
	c = a - b;
	std::cout << "Line 2 - c 的值是 " << c << std::endl;
	c = a * b;
	std::cout << "Line 3 - c 的值是 " << c << std::endl;
	c = a / b;
	std::cout << "Line 4 - c 的值是 " << c << std::endl;
	c = a % b;
	std::cout << "Line 5 - c 的值是 " << c << std::endl;

	int d = 10;   //  测试自增、自减
	c = d++;
	std::cout << "Line 6 - c 的值是 " << c << std::endl;
	std::cout << "Line 6 - d 的值是 " << d << std::endl;

	d = 10;    // 重新赋值
	c = --d;
	std::cout << "Line 7 - c 的值是 " << c << std::endl;
	std::cout << "Line 7 - d 的值是 " << d << std::endl;
	return 0;
}
*/

// 关系运算符
/*
== != >= <= > < 
*/

// 逻辑运算符
/*
&& || !
*/

// 位运算符
/*
& | ^  ~(取反) <<  >>
*/

// 赋值运算符

/*
= += -= *= /= %=
*/

// 杂项运算符
/*
sizeof  sizeof(a) 将返回 4，其中 a 是整数

#include <iostream>
using namespace std;
int main()
{
	int b;
	int a = 2;
	b = sizeof(a);
	cout << "b的值是：" << b << endl;
	
	return 0;
}

Condition ? X : Y     条件运算符  如果 Condition 为真 ? 则值为 X : 否则值为 Y

,                     逗号运算符会顺序执行一系列运算。整个逗号表达式的值是以逗号分隔的列表中的最后一个表达式的值。
#include <iostream>
using namespace std;

int main()
{
int i, j;

j = 10;
i = (j++, j+100, 999+j);

cout << i;

return 0;
}

.（点）和 ->（箭头）  成员运算符用于引用类、结构和共用体的成员
struct Employee {
char first_name[16];
int  age;
} emp;
点运算符应用于实际的对象,下面的代码把值 "zara" 赋给对象 emp 的 first_name 成员
strcpy(emp.first_name, "zara");

箭头运算符与一个指向对象的指针一起使用
如果 p_emp 是一个指针，指向类型为 Employee 的对象，则要把值 "zara" 赋给对象 emp 的 first_name 成员
strcpy(p_emp->first_name, "zara");

注：访问结构体的成员时使用点运算符，而通过指针访问结构体的成员时，则使用箭头运算符

Cast  	              强制转换运算符把一种数据类型转换为另一种数据类型。例如，int(2.2000) 将返回 2。

&        	          指针运算符 & 返回变量的地址。例如 &a; 将给出变量的实际地址。
C++ 提供了两种指针运算符，一种是取地址运算符 &，一种是间接寻址运算符 *
指针是一个存储了另一个变量地址的变量，& 是一元运算符，返回操作数的内存地址，如果 var 是一个整型变量，则 &var 是它的地址，&var 读作"var 的地址"

*                     指针运算符 * 指向一个变量。例如，*var; 将指向变量 var。
* 是一元运算符，返回操作数所指定地址的变量的值

*/
#include <iostream>

using namespace std;

int main()
{
	int  var;
	int  *ptr;
	int  val;

	var = 3000;

	// 获取 var 的地址
	ptr = &var;

	// 获取 ptr 的值
	val = *ptr;

	cout << "Value of var :" << var << endl;
	cout << "Value of ptr :" << ptr << endl;
	cout << "Value of val :" << val << endl;

	return 0;
}