### 1.Cpp中基本的输入输出
- C++标准库提供了一组丰富的输入/输出功能，将在后续的章节进行介绍。本章将讨论C++编程中最基本和最常见的I/O操作。C++的I/O发生在流中，流是字节序列。如果字节流是从设备（如键盘、磁盘驱动器、网络连接等）流向内存，这叫做**输入操作**。如果字节流是从内存流向设备（如显示屏、打印机、磁盘驱动器、网络连接等），这叫做**输出操作**。
### 2.I/O库文件介绍
![I_O库头文件.png](https://upload-images.jianshu.io/upload_images/13407176-f0830fb0e8c49fa1.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)
#### 2.1 标准输出流cout
- 预定义的对象cout是iostream类的一个实例。cout对象"连接"到标准输出设备，通常是显示屏。cout是与流插入运算符<<结合使用的，如下所示：
    ```
        // 标准输出cout
        char str[] = {"Hello C++"};
        cout << "Value of str is: " << str << endl;
    ```
- C++编译器根据要输出变量的数据类型，选择合适的流插入运算符来显示值。<<运算符被重载来输出内置类型（整型、浮点型、double型、字符串和指针）的数据项。流插入运算符<<在一个语句中可以多次使用，如上面实例中所示，endl用于在行末添加一个换行符。
#### 2.2 标准输入流cin
- 预定义的对象cin是iostream类的一个实例。cin对象附属到标准输入设备，通常是键盘。cin是与流提取运算符>>结合使用的，如下所示：
    ```
        // 标准输入cin
        cout << "请输入你的名字: ";
        char name[50];
        cin >> name;
        cout << "你的名字是: " << name << endl;
    ```
- C++编译器根据要输入值的数据类型，选择合适的流提取运算符来提取值，并把它存储在给定的变量中。流提取运算符>>在一个语句中可以多次使用，如果要求输入多个数据，可以使用如下语句：
    ```
        cin >> name >> age;   等价于cin >> name ; cin >> name;
    ```
#### 2.3 标准错误流cerr
- 预定义的对象cerr是iostream类的一个实例。cerr对象附属到标准错误设备，通常也是显示屏，但是 cerr对象是非缓冲的，且每个流插入到cerr都会立即输出。cerr也是与流插入运算符<<结合使用的，如下所示：
    ```
        // 标准错误cerr
        char error[] = "出现错误啦...";
        cerr << error << endl;
    ```
#### 2.4 标准日志流clog
- 预定义的对象clog是iostream类的一个实例。clog对象附属到标准错误设备，通常也是显示屏，但是 clog 对象是缓冲的。这意味着每个流插入到clog都会先存储在缓冲在，直到缓冲填满或者缓冲区刷新时才会输出。clog也是与流插入运算符<<结合使用的，如下所示：
    ```
        // 标准日志流clog
        char logs[] = "记录日志...";
        clog << logs << endl;
    ```

### 3.输入输出流中的函数(模板)
    ```
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
    ```
- 其中cout.setf跟setiosflags一样，cout.precision跟setprecision一样，cout.unsetf跟 resetiosflags一样。
```
    setiosflags(ios::fixed)      固定的浮点显示 
    setiosflags(ios::scientific) 指数表示 
    setiosflags(ios::left)       左对齐 
    setiosflags(ios::right)      右对齐 
    setiosflags(ios::skipws)      忽略前导空白 
    setiosflags(ios::uppercase)   16进制数大写输出 
    setiosflags(ios::lowercase)    16进制小写输出 
    setiosflags(ios::showpoint)    强制显示小数点 
    setiosflags(ios::showpos)      强制显示符号 
```
![cout.setf常用标志.png](https://upload-images.jianshu.io/upload_images/13407176-315896fb90c9b012.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)
![iostream中定义的操作符1.png](https://upload-images.jianshu.io/upload_images/13407176-954c88eba62ebdf4.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)
![iostream中定义的操作符2.png](https://upload-images.jianshu.io/upload_images/13407176-07c0b7150b04aeed.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)
![iomanip中的操作符.png](https://upload-images.jianshu.io/upload_images/13407176-cd6ece5cfcdd8cee.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)