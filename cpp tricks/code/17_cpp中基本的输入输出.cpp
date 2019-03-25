#include "iostream"
#include "iomanip"


using namespace std;



int main(){
    // 标准输出cout
    char str[] = {"Hello C++"};
    cout << "Value of str is: " << str << endl;
    // 标准输入cin
    cout << "请输入你的名字: ";
    char name[50];
    cin >> name;
    cout << "你的名字是: " << name << endl;
    // 标准错误cerr
    char error[] = "出现错误啦...";
    cerr << error << endl;
    // 标准日志流clog
    char logs[] = "记录日志...";
    clog << logs << endl;

    // 输入输出流中的函数
    cout << setiosflags(ios::left|ios::showpoint);  // 设置做对齐，一一般的实数方式显示
    cout.precision(5);  // 设置除小数点外有5位有效数字
    cout << 124.456789 << endl;
    cout.width(10);  // 设置显示域宽10
    cout.fill('*');  // 在显示区域空白处用*填充
    cout << resetiosflags(ios::left);  // 清楚状态左对齐
    cout << setiosflags(ios::right);  // 设置右对齐
    cout << 123.456789 << endl;
    cout << setiosflags(ios::left|ios::fixed);  // 设置左对齐，以固定小数位显示
    cout.precision(3);  // 设置实数显示3位小数
    cout << 999.123456 << endl;
    cout << resetiosflags(ios::left|ios::fixed);  // 清楚左对齐和定点格式
    cout << setiosflags(ios::left|ios::scientific);  // 设置左对齐，以科学技术法显示
    cout.precision(3);  // 设置保留3位小数
    cout << 123.456789 << endl;
    return 0;
}
