### 1.Cpp中的文件和流
- 到目前为止，已经使用了iostream标准库，它提供了cin和cout方法分别用于**从标准输入读取流**和**向标准输出写入流**。下面将介绍如何从文件读取流和向文件写入流。这就需要用到C++中另一个标准库**fstream**，它定义了三个新的数据类型：
![fstream中的三种数据类型.png](https://upload-images.jianshu.io/upload_images/13407176-b7945b185f2872e5.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)
### 2.打开文件ofstream和fstream
- 在从文件读取信息或者向文件写入信息之前，必须先打开文件。**ofstream和fstream对象都可以用来打开文件进行写操作，如果只需要打开文件进行读操作，则使用ifstream对象**。下面是open()函数的标准语法，open()函数是fstream、ifstream和ofstream对象的一个成员函数:
    ```
        void open(const char *filename, ios::openmode mode);
    ```
- open()成员函数的**第一参数指定要打开的文件的名称和位置，第二个参数定义文件被打开的模式**。
![文件打开的模式.png](https://upload-images.jianshu.io/upload_images/13407176-b694fff741bbc062.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)
- 也可以把以上两种或两种以上的模式结合使用。例如，如果想要以写入模式打开文件，并希望截断文件，以防文件已存在，那么可以使用下面的语法：
    ```
        ofstream outfile;
        outfile.open("file.dat", ios::out||ios::trunc);
    ```
- 同样地，如果想要打开一个文件用于读写，可以使用下面的语法：
    ```
        ifstream inputfile;
        inputfile.open("file.dat", ios::out||ios::in);
    ```
### 3.关闭文件
- 当C++程序终止时，它会自动关闭刷新所有流，释放所有分配的内存，并关闭所有打开的文件。但程序员应该养成一个好习惯，在程序终止前关闭所有打开的文件。下面是close()函数的标准语法，close()函数是fstream、ifstream和ofstream对象的一个成员。
    ```
        viod close();
    ```
### 4.写入文件
- 在C++编程中，使用流插入运算符<<向文件写入信息，**就像使用<<运算符输出信息到屏幕上一样。唯一不同的是，在这里使用的是ofstream或fstream对象，而不是cout对象**。
### 5.读取文件
- 在C++编程中，使用流插入运算符>>向文件写入信息，**就像使用>>运算符从键盘输入信息一样。唯一不同的是，在这里使用的是ifstream或fstream对象，而不是cint对象**。
### 6.读取和写入实例
    ```
        #include "iostream"
        #include "fstream"    // 文件的读取和写入标准库

        using namespace std;

        int main(){
            char data[100];
            // 以写模式打开文件
            ofstream outfile;
            outfile.open("afile.dat");  // 打开文件
            cout << "write to the file......" << endl;
            cout << "Enter your name: ";
            cin.getline(data, 100);   // getline()函数从外部读取一行
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
            return 0;
        }
    ```
### 7.文件位置指针
- istream和ostream都提供了用于重新定位文件位置指针的成员函数。**这些成员函数包括关于istream的seekg("seek get")和关于ostream的seekp("seek put")**。seekg和seekp的参数通常是一个长整型!第二个参数可以用于指定查找方向;查找方向可以是ios::beg(默认的，从流的开头开始定位)，也可以是ios::cur(从流的当前位置开始定位)，也可以是ios::end(从流的末尾开始定位)。文件位置指针是一个整数值，指定了从文件的起始位置到指针所在位置的字节数。下面是关于定位"get"文件位置指针的实例：
    ```
        // 定位到fileObject的第n个字节(假设是 ios::beg)
        fileObject.seekg(n);
        
        // 把文件的读指针从fileObject当前位置向后移n个字节
        fileObject.seekg(n, ios::cur);
        
        // 把文件的读指针从fileObject末尾往回移n个字节
        fileObject.seekg(n, ios::end);
        
        // 定位到fileObject的末尾
        fileObject.seekg(0, ios::end);
    ```
### 8.文件读写中的细节知识点
- 读写和复制文件实例如下:
    ```
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
        file_wr();
        file_copy();
    ```
- cin.ignore()函数介绍
    - 关于cin.ignore(),完整版本是cin.ignore(int n, char a), 从输入流(cin)中提取字符，提取的字符被忽略(ignore)，不被使用。每抛弃一个字符，它都要计数和比较字符：如果计数值达到n或者被抛弃的字符是a，则cin.ignore()函数执行终止；否则，它继续等待。**它的一个常用功能就是用来清除以回车结束的输入缓冲区的内容，消除上一次输入对下一次输入的影响**。比如可以这么用：cin.ignore(1024,'\n')，通常把第一个参数设置得足够大，这样实际上总是只有第二个参数\n起作用，所以这一句就是把回车(包括回车)之前的所以字符从输入缓冲(流)中清除出去。
        ```
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
        ```
    - 如果cin.ignore()不给参数,则默认参数为cin.ignore(1,EOF).其中EOF是end of file的缩写，表示"文字流"(stream)的结尾。如果在住址那里输入bcdabcd,那么此时流里面剩的是bcd\n,此时cin.ignore(); 吃掉的就是b了,这是流里还剩下cd\n直接交给cin.getline(str3,30); 因为有个\n所以这里getline就直接返回。
        ```
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
        ```