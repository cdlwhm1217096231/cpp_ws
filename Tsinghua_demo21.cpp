#include <iostream>
// 类的组合
using namespace std;

enum CPU_Rank { P1 = 1, P2, P3, P4, P5, P6, P7 };
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
		cout << "构造了一个CPU！" << endl;
	}
	// 复制构造了一个CPU
	CPU(CPU &c){
		rank = c.rank;
		frequency = c.frequency;
		voltage = c.voltage;
		cout << "复制构造了一个CPU！" << endl;
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
	// 内联成员函数：在类中定义的成员函数
	void run() { cout << "CPU开始运行！" << endl; }
	void stop() { cout << "CPU停止运行！" << endl; }
};

enum RAM_TYPE { DDR2 = 2, DDR3, DDR4 };
class RAM{
private:
	RAM_TYPE type;
	unsigned int frequency;
	unsigned int size;
public:
	// 构造函数
	RAM(RAM_TYPE t, unsigned int f, unsigned int s){
		type = t;
		frequency = f;
		size = s;
		cout << "构造了一个RAM！" << endl;
	}
	// 复制构造了一个RAM
	RAM(RAM &r){
		type = r.type;
		frequency = r.frequency;
		size = r.size;
		cout << "复制构造了一个RAM！" << endl;
	}
	// 析构函数
	~RAM(){
		cout << "析构了一个RAM！" << endl;
	}
	// 外部接口函数----常函数
	RAM_TYPE getRAM_TYPE() const { return type; }//常函数
	unsigned int getFrequency() const { return frequency; }
	unsigned int getSize() const { return size; }

	void setRAM_TYPE(RAM_TYPE t) { type = t; }
	void setFrequency(unsigned int f) { frequency = f; }
	void setSize(unsigned int s) { size = s; }
	// 成员函数
	void run() { cout << "RAM开始运行！" << endl; }
	void stop() { cout << "RAM停止运行！" << endl; }
};

enum CDROM_interface { SATA, USB };
enum CDROM_install_type { external, built_in };
class CDROM{
private:
	CDROM_interface interface;
	unsigned int cache_size;
	CDROM_install_type install_type;
public:
	// 构造函数
	CDROM(CDROM_interface i, unsigned int c, CDROM_install_type it){
		interface = i;
		cache_size = c;
		install_type = it;
		cout << "构造了一个CDROM！" << endl;
	}
	// 复制构造了一个CDROM
	CDROM(CDROM &cd){
		interface = cd.interface;
		cache_size = cd.cache_size;
		install_type = cd.install_type;
		cout << "复制构造了一个CDROM！" << endl;
	}
	// 析构函数
	~CDROM(){
		cout << "析构了一个CDROM！" << endl;
	}
	// 外部接口函数
	CDROM_interface getInterface() const { return interface; }
	unsigned int getCache_size() const { return cache_size; }
	CDROM_install_type getInstall_type() const { return install_type; }

	void setInterface(CDROM_interface i){ interface = i; }
	void setCache_size(unsigned int c) { cache_size = c; }
	void setInstall_type(CDROM_install_type it) { install_type = it; }
	// 成员函数
	void run() { cout << "CDROM开始运行！" << endl; }
	void stop() { cout << "CDROM停止运行！" << endl; }
};

class Computer{
private:
	CPU my_cpu;
	RAM my_ram;
	CDROM my_cdrom;
	unsigned int storage_size;
	unsigned int bandwidth;
public:
	// 声明Computer的一个构造函数
	Computer(CPU c, RAM r, CDROM cd, unsigned int s, unsigned int b);
	// 析构函数
	~Computer(){
		cout << "析构了一个Computer！" << endl;
	}
	// 成员函数
	void run(){
		my_cpu.run();
		my_ram.run();
		my_cdrom.run();
		cout << "Computer正在运行！" << endl;
	}

	void stop(){
		my_cpu.stop();
		my_ram.stop();
		my_cdrom.stop();
		cout << "Computer停止工作！" << endl;
	}

};
// Computer类的构造函数实现
Computer::Computer(CPU c, RAM r, CDROM cd, unsigned int s, unsigned int b) : my_cpu(c), my_ram(r), my_cdrom(cd){
	storage_size = s;
	bandwidth = b;
	cout << "构造了一个Computer!" << endl;
}

// 主函数

int main(){
	CPU a(P6, 300, 2.8);
	a.run();
	a.stop();
	cout << "**********************\n";
	RAM b(DDR3, 1600, 8);
	b.run();
	b.stop();
	cout << "**********************\n";
	CDROM c(SATA, 2, built_in);
	c.run();
	c.stop();
	cout << "**********************\n";
	Computer my_computer(a, b, c, 128, 10);
	cout << "**********************\n";
	my_computer.run();
	my_computer.stop();
	cout << "**********************\n";
	return 0;
}