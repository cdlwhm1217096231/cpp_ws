#include <iostream>
// 汉诺塔程序
using namespace std;

void move(char src, char dest);
void hanoi(int n, char src, char medium, char dest);

int main()
{
	int m;
	cout << "输入盘子数目：";
	cin >> m;
	cout << "移动 " << m << " 个盘子的次数" << endl;
	hanoi(m, 'A', 'B', 'C');
	return 0;
}

void move(char src, char dest)
{
	cout << src << "-->" << dest << endl;
}

void hanoi(int n, char src, char medium, char dest){
	if (n == 1)
		move(src, dest);
	else{
		hanoi(n - 1, src, dest, medium);
		move(src, dest);
		hanoi(n - 1, medium, src, dest);
	}		
}