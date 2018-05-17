// C++ 字符串
/*
字符串实际上是使用 null 字符 '\0' 终止的一维字符数组。因此，一个以 null 结尾的字符串，包含了组成字符串的字符。

char greeting[6] = {'H', 'e', 'l', 'l', 'o', '\0'};
由于在数组的末尾存储了空字符，所以字符数组的大小比单词 "Hello" 的字符数多一个
#include <iostream>

using namespace std;

int main()
{
char a[6] = { 'H', 'e', 'l', 'l', 'o', '\0' };
cout << "a的值是：";
cout << a << endl;
return 0;
}

// C++ 中有大量的函数用来操作以 null 结尾的字符串
strcpy(s1, s2);  复制字符串 s2 到字符串 s1
strcat(s1, s2);  连接字符串 s2 到字符串 s1 的末尾。
strlen(s1);		 返回字符串 s1 的长度。
strcmp(s1, s2);  如果 s1 和 s2 是相同的，则返回 0；如果 s1<s2 则返回值小于 0；如果 s1>s2 则返回值大于 0。
strchr(s1, ch);  返回一个指针，指向字符串 s1 中字符 ch 的第一次出现的位置。
strstr(s1, s2);  返回一个指针，指向字符串 s1 中字符串 s2 的第一次出现的位置

#include <iostream>
#include <cstring>
 
using namespace std;
 
int main ()
{
   char str1[11] = "Hello";
   char str2[11] = "World";
   char str3[11];
   int  len ;
 
   // 复制 str1 到 str3
   strcpy( str3, str1);
   cout << "strcpy( str3, str1) : " << str3 << endl;
 
   // 连接 str1 和 str2
   strcat( str1, str2);
   cout << "strcat( str1, str2): " << str1 << endl;
 
   // 连接后，str1 的总长度
   len = strlen(str1);
   cout << "strlen(str1) : " << len << endl;
 
   return 0;
}

*/
// C++ 中的 String 类
#include <iostream>
#include <string>

using namespace std;

int main()
{
	string str1 = "Hello";
	string str2 = " World";
	string str3;
	int  len;
	// append()在字符串的末尾添加字符
	str1.append(" xxoo");
	cout << "str1: " << str1;
	// 复制 str1 到 str3
	str3 = str1;
	cout << "str3 : " << str3 << endl;

	// 连接 str1 和 str2
	str3 = str1 + str2;
	cout << "str1 + str2 : " << str3 << endl;

	// 连接后，str3 的总长度
	len = str3.size();
	cout << "str3.size() :  " << len << endl;
	return 0;
}

