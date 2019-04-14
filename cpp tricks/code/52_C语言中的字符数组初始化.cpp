#include "iostream"
#include "cstring"


using namespace std;



int main(){
    /*字符数组初始化*/
    // 第一种初始化的方法
    char str[10] = {'I',' ','a','m',' ','h','a','p','p','y'};  // 少了\0,输出会出现问题
    cout << "str=" << str << ",sizeof(str)=" << sizeof(str) << endl;
    // 第二种初始化的方法
    char str1[] = "I am happy";  // 等价于char str1[] = {"I am happy"};
    char str2[] = "python";
    // char str2[] = {'p', 'y', 't','h','o','n'}与char str2[] = "python"不等价
    // char str2[] = {'p', 'y', 't','h','o','n', '\0'}与char str2="python"等价
    char str3[] = {'p', 'y', 't','h','o','n'};
    char str4[] = {'p', 'y', 't','h','o','n', '\0'};
    
    int num_str2 = sizeof(str2);
    int num_str3 = sizeof(str3);
    int num_str4 = sizeof(str4);
    
    cout << "str2与str3不等价\n";
    cout << "str2 = " << str2 << ",sizeof(str2) = " << num_str2 << endl;
    cout << "str3 = " << str3 << ",sizeof(str3) = " << num_str3 << endl;
    cout << "str2与str4等价\n";
    cout << "str2 = " << str2 << ",sizeof(str2) = " << num_str2 << endl;
    cout << "str4 = " << str4 << ",sizeof(str4) = " << num_str4 << endl;
    // 字符指针初始化
    char *str5 = "python";
    cout << "str5 = " << str5 << endl;
    cout << "*str5 = " << *str5 << endl;
    cout << "sizeof(str5) = " << sizeof(str5) << endl;
    cout << "sizeof(*str5) = " << sizeof(*str5) << endl;
    return 0;
}