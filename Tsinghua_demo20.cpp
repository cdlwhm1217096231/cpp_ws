#include <iostream>

using namespace std;

// 声明枚举类型
enum CPU_Rank {P1=1,P2,P3,P4,P5,P6,P7};
class CPU{
private:
	CPU_Rank rank;
	int frequency;
	float voltage;
public:
	// 构造函数
	CPU(CPU_Rank r, int f, float v){
		rank = r;
		frequency = f;
		voltage = v;
		cout << "构造一个CPU！" << endl;
	}
	// 析构函数
	~CPU(){
		cout << "析构了一个CPU！" << endl;
	}
	// 外部接口函数
	CPU_Rank getRank() const { return rank; }//常函数
	int getFrequency() const { return frequency; }
	float getVoltage() const { return voltage; }

	void setRank(CPU_Rank r) { rank = r; }
	void setFrequency(int f) { frequency = f; }
	void setVoltage(float v) { voltage = v; }
	// 成员函数
	void run() { cout << "CPU开始运行！" << endl; }
	void stop() { cout << "CPU停止运行！" << endl; }
};
int main(){
	CPU a(P6, 300, 2.8); // 声明一个CPU类的对象a，并对其初始化
	a.run();
	a.stop();
	return 0;
}