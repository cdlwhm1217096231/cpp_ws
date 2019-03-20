#include "iostream"
#include "cstring"
#include "string"

#define N 100

using namespace std;

int main(){
    // 1 在字符串常量中，可以在初始化时不写\0，这一步可以由编译器自动完成
    char greeting[6] = {'H', 'e', 'l', 'l', 'o'};
    cout << "greeting: " << greeting << endl;
    // 2 字符串中的常见函数:
    char str1[11] = "hello";
    char str2[11] = "world";
    char str3[11];
    int len, result;
    // 复制str1到str3
    strcpy(str3, str1);
    cout << "strcpy(str1, str3):" << str3 << endl;
    // 连接str1和str2
    strcat(str1, str2);
    cout << "strcat(str1, str2):" << str1 << endl;
    // 连接后，str1的总长度
    len = strlen(str1);
    cout << "strlen(str1):" << len << endl;
    // str1与str2比较
    result = strcmp(str1, str2);
    cout << "strcmp(str1, str2):" << result << endl;
    cout << "-------------------------分隔线-------------------------\n";
    // 3 Cpp中的字符串
    string s1 = "abandon";
    string s2 = "banana";
    string s3;
    // 复制s1到s3
    s3 = s1;
    cout << "s3:" << s3 << endl;
    // 连接s1和s2
    s3 = s1 + s2;
    cout << "s1 + s2:" << s3 << endl;
    // 连接后的s3总长度
    int len1, result1;
    len1 = s3.size();
    cout << "s3.size():" << len1 << endl;
    // 比较s1和s2
    result1 = s1 > s2;
    cout << "s1 > s2:" << result1 << endl;
    // 4 string类中的其他函数
    string name = "Curry";
    cout << "The length of string is:" << name.length() << endl;
    // 拼接
    name.append("Coder");
    cout << "name:" << name << endl;
    // 删除
    int pos;
    pos = name.find("Coder");  // 查找Coder在字符串中的位置
    cout << "pos = " << pos << endl;
    name.replace(pos, 4, "");  // 从位置pos开始,后面的连续4个字符都将被替换为空格
    cout << "name = " << name << endl;
    // 找子串
    int first = name.find_first_of("r");  // 从头找到字符r的位置
    int last = name.find_last_of("r");   // 从尾部找字符的位置
    cout << name.substr(first + 1, last - first -1) << endl; // 提取两个r之间的字符子串
    // 5 cin.getline()函数
    char X[N];
    cin.getline(X,N);
    int a = 0, b = 0;
    for (int i=0; i < N;i++){
        if (X[i] == '#')  // #是结尾标志
            break;
        if (X[i] >= '0' && X[i] <= '9')  // 统计数字个数
            a++;
        if ((X[i] >= 'a' && X[i] <= 'z') || (X[i] >= 'A' && X[i] <= 'Z')) // 统计字母个数
            b++;
    }
    cout << "a = " << a << " b = " << b << endl;
    // 字符串字面值与标准库string不是同一种类型
    string s("hello");
    cout << "s.size() = " << s.size() << endl;  // 正确
    // cout << "hello".size() << endl;  错误
    cout << s + "world" << endl;  // 正确
    // cout << "hello" + "world" << endl;  错误
    // 字符数组可以用数组名输出数组的内容，但是普通数组不可以
    int aa[10] = {1, 2, 3, 4, 6, 7};
    char bb[6] = {'h', 'a', 'a', 'p', 'y', '\0'};
    char cc[] = "happy";
    cout << "aa = " << aa << endl;
    cout << "bb = " << bb << endl;
    cout << "cc = " << cc << endl;
    return 0;
}