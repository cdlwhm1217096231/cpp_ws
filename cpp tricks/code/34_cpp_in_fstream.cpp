#include "iostream"
#include "fstream"    // 文件的读取和写入标准库

using namespace std;

// 向文件中写入用户输入的数据，然后程序从文件读取信息，并将其输出到屏幕上
void file_wr(){
    char data[100];
    // 向文件写入用户输入的数据
    ofstream outfile;
    outfile.open("test.txt");
    cout << "write to the file......\n";
    cout << "Enter you name: ";
    cin.getline(data, 100);
    outfile << data << endl;
    cout << "Enter your name: ";
    cin >> data;
    cin.ignore();
    outfile << data << endl;
    outfile.close();
    cout << "----------------------------------------\n";
    // 从文件读取数据
    ifstream infile;
    infile.open("test.txt");
    cout << "Read from the file......\n";
    infile >> data;
    cout << data << endl;
    infile >> data;
    cout << data << endl; 
    infile.close();
}
// 将一个文件复制到另一个文件
void file_copy(){
    char data[100];
    ifstream infile;
    ofstream outfile;
    infile.open("test.txt");
    outfile.open("test_copy.txt");
    cout << "copy from test.txt to test_copy.txt" << endl;
    while(!infile.eof()){
        infile >> data;
        cout << data << endl;
        outfile << data << endl;
    }
    infile.close();
    outfile.close();
}



int main(){
    char data[100];
    // 以写模式打开文件
    ofstream outfile;
    outfile.open("afile.dat");  // 打开文件
    cout << "write to the file......" << endl;
    cout << "Enter your name: ";
    cin.getline(data, 100);  // getline()函数从外部读取一行
    // 向文件写入用户输入的数据
    outfile << data << endl;
    cout << "Enter your age: ";
    cin >> data;
    cin.ignore();   // 忽略掉之前读语句留下的多余字符
    // 再次向文件写入用户输入的数据
    outfile << data << endl;
    // 关闭文件
    outfile.close();
    cout << "----------------------------------------------------\n";
    // 以读的方式打开文件
    ifstream infile;
    infile.open("afile.dat");
    cout << "Reading from the file......" << endl;
    // 读出文件中的数据
    infile >> data;
    // 在屏幕上显示读出的数据
    cout << data << endl;
    // 再次从文件上读取数据，并显示处理
    infile >> data;
    cout << data << endl;
    // 关闭打开的文件
    infile.close();
    cout << "----------------------------------------------------\n";
    file_wr();
    file_copy();
    cout << "----------------------------------------------------\n";
    // cin.ignore()函数介绍
    int a, b, c;
    cout << "input a:";
    cin >> a;
    cin.ignore(1024, '\n');
    cout << "input b:";
    cin >> b;
    cin.ignore(1024, '\n');
    cout << "input c:";
    cin >> c;
    cin.ignore(1024, '\n');
    cout<< a << "\t" << b << "\t" << c << endl;
    cout << "----------------------------------------------------\n";
    char str1[30], str2[30], str3[30];
    cout << "请输入你的名字: ";
    cin >> str1;
    cout << "请输入你的住址: ";
    cin.ignore();
    cin.getline(str2, 30, 'a');
    cout << "请输入的籍贯: ";
    cin.ignore();
    cin.getline(str3, 30);
    cout << str3;
    return 0;
}