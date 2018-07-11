#include <iostream>
using namespace std;
// 带多个参数的构造函数
class Volume{
public:
	void setVolume(double len, double wid, double hei);
	double getVolume();
	Volume(double len, double wid, double hei); // 带参数的构造函数声明
	~Volume(); // 析构函数声明
private:
	double length;
	double width;
	double height;
};

void Volume::setVolume(double len, double wid, double hei){
	length = len;
	width = wid;
	height = hei;
}

double Volume::getVolume(){
	return length * width * height;
}

// 构造函数实现
Volume::Volume(double len, double wid, double hei): length(len), width(wid), height(hei){
	cout << "对象已创建好!\n" ;
}

// 析构函数实现
Volume::~Volume(){
	cout << "对象已被删除!\n";
}

int main(){
	Volume vol(3, 4, 5);
	cout << "默认长方体的体积：" << vol.getVolume() << endl;
	vol.setVolume(1, 2, 3);
	cout << "自定义的长方体的体积: " << vol.getVolume() << endl;
	return 0;
}