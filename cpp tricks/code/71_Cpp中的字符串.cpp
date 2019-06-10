#include <iostream>

using namespace std;


int main(){
    // str1与str2是两个字符串数组，我们会为它们分配长度为12字节的空间，因为是两个初始地址不同的数组，故str1!=str2
    char str1[] = "hello world";
    char str2[] = "hello world";
    if(str1 == str2)
        cout << "str1与str2相同\n";
    else
        cout << "str1与str2不同\n";
    
    // str3 与 str4是两个指针，无须为它们分配内存来存储字符串的内容，只需要把它们指向"hello world"在内存中的地址就可以了。
    // 由于"hello world"是字符串常量，它在内存中只有一个拷贝，因此str3与str4指向同一个地址
    char *str3 = "hello world";
    char *str4 = "hello world";
    if(str3 == str4)
        cout << "str3与str4相同\n";
    else    
        cout << "str3与str4不同\n";
    return 0;
}