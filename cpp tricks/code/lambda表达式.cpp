#include "iostream"

using namespace std;



class Test{
public:
	void hello(){
		cout << "test hello!\n";
	};
	void lambda(){
		auto fun = [this]{ // 捕获了 this 指针
		this->hello(); 
		}; // 这里 this 调用的就是 class Test 的对象了
		fun();
	}
};


int main(){
	// 定义一个简单的lambda表达式
	auto basicLamda = [] {cout << "hello world!" << endl; };
	basicLamda();  // 调用
	// 如果需要参数，那么就要像函数那样，放在圆括号里面，如果有返回值，返回类型要放在->后面，即拖尾返回类型
	// 当然你也可以忽略返回类型，lambda会帮你自动推断出返回类型
	auto add = [](int a, int b) -> int {return a + b; };
	int result = add(4, 5);
	cout << "result = " << result << endl;
	// 自动推断出返回类型
	auto multiply = [](int a, int b) {return a * b; };
	int result1 = multiply(5, 6);
	cout << "result1 = " << result1 << endl;
	// 1、什么也不捕获，或者是故意不用 Lambda 函数外部的变量
	int  i = 1024;
	// auto f = []{cout << "i = " << i << endl; }; 报错!应该使用了lambda函数外部的变量
	auto f = [=] { cout << "i = " << i << endl; };  // 使用传值的方式使用外lambda函数外部的变量i
	f();  // 调用函数
	// 2、引用捕捉
	int i1 = 666;
	cout << "变量i1的引用: " << &i1 << endl;
	auto f1 = [&] { cout << "变量i1的引用: " << &i1 << endl; };
	f1();
	// 3、复制并引用捕获
	int i2 = 777, j2 = 888;
	cout << "i2 = " << i2 << endl;
	cout << "j2 = " << j2 << endl;
	auto f2 = [=, &i2] { cout << "i2 = " << &i2 << " ,j2 = " << &j2 << endl; };  // 默认拷贝外部所有变量，但引用变量i2
	f2();
	// 4、指定引用或复制
	int i3 = 444, j3 = 555;
	cout << "外部变量i3 = " << i3 << " i3的地址是: " << &i3 << endl;
	auto f3 = [i3] { cout << "内部变量i3 = " << i3 << " i3的地址是: " << &i3 << endl; };
	f3();
	// 5、捕获this指针
	Test t;
	t.lambda();
	return 0;
}