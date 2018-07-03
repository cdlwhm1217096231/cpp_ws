#include <iostream>
#include <climits>  // 定义了INT_MAX等符号常量
#define ZERO 0

/*
c++中基本的整型数据：char short int long、 long long，每种类型又有有符号和无符号两个版本，所以一共有10中类型可以选择。
字节与位之间的关系：
1字节==8位，每个位有0、1两种情况，故8位共有256种情况。所以8位单元可以表示0-255或者-128-127之间的数
16位单元可以存储0-65535或者-32768-32767之间的数
sizeof()：返回变量/类型的长度，单位是字节;对类型名使用sizeof时，必须要有(),但对变量名使用sizeof时，()可以省略
*/
using namespace std;

int main()
{
	int n_int = INT_MAX;  // 将赋值和声明合并在一起称为初始化
	// 下面是利用3种不同方法进行变量初始化
	int emus{ 7 };
	int rheas = { 12 };
	int rocs = {};
	cout << "emus value is " << emus << endl;
	cout << "rocs value is " << rocs << endl;
	// 四种有符号数据类型
	short n_short = SHRT_MAX;
	long n_long = LONG_MAX;
	long long n_llong = LLONG_MAX;
	cout << "int is " << sizeof (int) << " bytes." << endl;   // 4字节
	cout << "short is " << sizeof n_short << " bytes." << endl; // 2字节
	cout << "long is " << sizeof(n_long) << " bytes." << endl;  // 4字节
	cout << "long long is " << sizeof(n_llong) << " bytes." << endl; // 8字节
	cout << endl;
	cout << "Max values: " << endl;
	cout << "int is: " << n_int << endl;
	cout << "short is: " << n_short << endl;
	cout << "long is: " << n_long << endl;
	cout << "long long is: " << n_llong << endl;
	// 下面是四种无符号数据类型情况
	unsigned short change;
	// unsigned change; 与上面语句是等价
	unsigned int rovert;
	unsigned long gone;
	unsigned long long lang_lang;
	short sam = SHRT_MAX; // 将会溢出
	unsigned short sue = sam; // 无法表示负数-1
	cout << "Sam has " << sam << " dollars and Sue has " << sue << " dollars deposited." << endl;
	sam += 1;
	sue += 1;
	cout << "Sam has " << sam << " dollars and Sue has " << sue << " dollars deposited." << endl;
	sam = ZERO;
	sue = ZERO;
	cout << "Sam has " << sam << " dollars and Sue has " << sue << " dollars deposited." << endl;
	sam -= 1;
	sue -= 1;
	cout << "Sam has " << sam << " dollars and Sue has " << sue << " dollars deposited." << endl;
	// 整型常量
	int chest = 42;  // 十进制
	int waist = 042; // 八进制
	int xwast = 0x42; // 十六进制
	cout << "chest value is " << chest << endl;
	cout << hex;
	cout << "chest value is " << chest << " 八进制表示" << endl;
	cout << oct;
	cout << "chest value is " << chest << " 十六进制表示" << endl;
	cout << "waist value is " << waist << endl;
	cout << "xwast value is " << xwast << endl;
	// 确定常量的类型------使用后缀L、U
	int curry = 2000LU;
	// 最后一种整型: char类型-------字符和小整数(占一个字节),一个字符用对应ASCII码来表示
	char chr1;
	cout << "Enter a char: " << endl;
	cin >> chr1;
	cout << "Thank you for the " << chr1 << " character." << endl;
	// c++中用单引号表示单个字符' ', 双引号表示字符串" "
	cout << endl;
	char ch = 'M';
	int i = ch;
	cout << "字符 " << ch << " 的ASCII码是 " << i << endl;
	ch += 1;
	i = ch;
	cout << "字符 " << ch << " 的ASCII码是 " << i << endl;
	// 转义字符：\n \t \v \b \r \\ \? \' \" \a
	// 字符型数据的修饰符
	char curry1;
	unsigned harden;  // 0-255
	signed durant;   // -128-127
	// wchar_t宽字符类型，使用wcin wcout来处理wchar_t流，加前缀L来表示宽字符常量/宽字符串
	wchar_t bob =  L'P';
	wcout << L"Hello" << endl;
	// 布尔类型
	bool is_ready = true;
	int boff = true;  // 相当于boff = 1
	int ddf = false;  // 相当于ddf = 0
	bool start = 100;
	bool ssh = 0;
	// const限定符
	const int Months = 12; // 首字母大写，提醒Months是一个常量，不能修改
	// 浮点数--------3种类型float 、double 、long double
	// 标准小数表法： 3.1415， 6798.55 8.0
	// E表示法：3.34E6 7E5 -12.8E6 9.11e-32
	// 浮点常量表示： float类型 1.234f double类型 1.234E5  long double 类型 1.234L
	// float 只保证6位有效位,占4个字节， double 占8个字节
	float a = 2.34E+22f;
	float b = a + 1.0f;
	cout << "a = " << a << endl;
	cout << "b-a " << b - a << endl;
	// c++算术运算符 %：求模运算符（两个操作数必须都是整型）
	cout.setf(ios_base::fixed, ios_base::floatfield); // 修正float输出的值
	float hats, heads;
	cout << "Enter a number: ";
	cin >> hats;
	cout << "Enter another number: ";
	cin >> heads;
	cout << "hats = " << hats << endl;
	cout << "heads = " << heads << endl;
	cout << "heads + hats " << heads + hats << endl;
	cout << "hats - heads " << hats - heads << endl;
	cout << "hats * heads " << hats * heads << endl;
	cout << "hats / heads " << hats / heads << endl;
	// 除法运算/: 两个操作数都是整数时，则会出现整数的结果；当两个/一个为小数时，结果是浮点数
	cout << "9 / 5 = " << 9 / 5 << endl;
	cout << "9.0 / 5 = " << 9.0 / 5 << endl;
	// 类型转换
	// 1.初始化和赋值进行类型转换
	cout.setf(ios_base::fixed, ios_base::floatfield);
	float tree = 3;
	int guess(3.9832); // 赋值语句guess = 3.9832;
	int debt = 7.3E12;
	cout << "tree = " << tree << endl;
	cout << "guess = " << guess << endl; //将浮点型赋值给整型，则会截取，丢弃小数部分
	cout << "debt = " << debt << endl;
	// 2.强制类型转换
	// int thron;
	// long (thron); // c++格式
	// (long) thron;  // c格式
	cout << int ('Q') << endl;
	// static_cast<> 可用于将值从一种数值类型转换为另一种数值类型 格式：static_cast<typename> (value)
	int auks, bats, coots;
	auks = 19.99 + 11.99;
	bats = (int) 19.99 + (int) 11.99;
	coots = int(19.99) + int(11.99);
	cout << "auks = " << auks << endl;
	cout << "bats = " << bats << endl;
	cout << "coots = " << coots << endl;
	char ch1 = 'Z';
	cout << "The code for " << ch1 << " is ";
	cout << int(ch1) << endl;
	cout << static_cast<int> (ch1) << endl;
	// auto声明：使用auto关键字，不用指定变量的类型
	auto n = 100;
	auto d = 1.2;
	auto x = 1.2e12L;
	return 0;

}
