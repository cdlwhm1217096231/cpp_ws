#include "iostream"
#include "string"
#include "sstream"


using namespace std;

int main(){
    // cin用法
    // 用法1：输入一个数字或字符
    int a, b;
    cin >> a >> b;
    cout << a + b << endl;
    // 用于接收一个字符串，遇到空格，TAB键、回车就结束
    char aa[20];
    cin >> aa;
    cout << aa << endl;
    cout << "----------------------------------\n";
    // cin.getline()函数
    // 接收一个字符串，可以接收空格并输出
    char bb[20];
    cin.getline(bb, 5);
    cout << bb << endl;   // 接收5个字符到bb中，其中最后一个为'\0'，所以只看到4个字符输出
    // getline()函数
    // 接收一个字符串，可以接收空格并输出，需包含“#include<string>”
    string str;
    getline(cin, str);
    cout << str << endl;
    cout << "----------------------------------\n";
    string s1;
    string s2;
    cin >> s1;
    cout << "s1 = " << s1 << endl;
    cin.clear();
    cin.sync();
    getline(cin, s2);
    cout << "s2 = " << s2 << endl;
    return 0;
}
