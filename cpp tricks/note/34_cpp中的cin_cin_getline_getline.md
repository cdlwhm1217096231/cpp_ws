### 1.cin用法
- 用法1：输入一个数字或字符
    ```
        // cin用法
        // 用法1：输入一个数字或字符
        int a, b;
        cin >> a >> b;
        cout << a + b << endl;
    ```
- 用法2：用于接收一个字符串，遇到空格，TAB键、回车就结束
    ```
            // 用于接收一个字符串，遇到空格，TAB键、回车就结束
            char aa[20];
            cin >> aa;
            cout << aa << endl;
    ```
### 2.cin.getline()用法
- 用法：接收一个字符串，可以接收空格并输出
    ```
        char bb[20];
        cin.getline(bb, 5);
        cout << bb << endl;   // 接收5个字符到bb中，其中最后一个为'\0'，所以只看到4个字符输出
    ```
- 延伸知识点：
    - cin.getline()实际上有三个参数，cin.getline(接收字符串的变量,接收字符个数,结束字符)
    - 当第三个参数省略时，系统默认为'\0'
    - 如果将例子中cin.getline()改为cin.getline(bb,5,'a');当输入jlkjkljkl时，输出jklj；输入jkaljkljkl时，输出jk
### 3.getline()用法
- 用法：接收一个字符串，可以接收空格并输出，需包含\#include<string>   
    ```
        string str;
        getline(cin, str);
        cout << str << endl;
    ```
### 4.注意的问题：
- cin.getline()属于istream流，而getline()属于string流，是不一样的两个函数
- 当同时使用cin >>,getline()时，需要注意的是，在cin >> 输入流完成之后，getline()之前，需要通过下面的两种方法作为输入流cin以清除缓存，如果不这样做的话，在控制台上就不会出现getline()的输入提示，而直接跳过，因为程序默认地将之前的变量作为输入流。
    - 方法一：str="\n"; getline(cin,str);
    - 方法二：cin.clear(); cin.sync();
    ```
            string s1;
            string s2;
            cin>>s1;
            cout << "s1 is :" << s1 << endl;
            cin.clear();
            cin.sync();
            getline(cin, s2);
            cout << "s2 is :" << s2 << endl;
    ```
### 5.参考博客
[博客链接](https://blog.csdn.net/liusicheng2008_liu/article/details/80324502)