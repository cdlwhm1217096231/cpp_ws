### 1.Cpp中的字符串
- C++提供了以下两种类型的字符串表示形式：
    - C风格字符串
    - C++引入的string类类型
#### 1.1 C风格字符串
- C风格的字符串起源于C语言，并在C++中继续得到支持。字符串实际上是使用null字符'\0'终止的一维字符数组。因此，**一个以null结尾的字符串，包含了组成字符串的字符**。
- 下面的声明和初始化创建了一个"Hello"字符串。由于在数组的末尾存储了空字符，**所以字符数组的大小比单词"Hello"的字符数多一个**。
    ```
        char greeting[6] = {'H', 'e', 'l', 'l', 'o', '\0'};
    ```
- 依据数组初始化规则，可以把上面的语句写成以下语句：
    ```
        char greeting[] = {'H', 'e', 'l', 'l', 'o', '\o'};
    ```
- 以下是C/C++中定义的字符串的内存表示：
![字符串的在内存中的表示.png](https://upload-images.jianshu.io/upload_images/13407176-78b755c938c235f5.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)
- 其实，不需要把null字符放在**字符串常量**的末尾。C++编译器会在初始化数组时，自动把'\0'放在字符串的末尾，如下面的例子:
    ```
        #include "iostream"

        using namespace std;

        int main(){
            char greeting[6] = {'H', 'e', 'l', 'l', 'o'};
            cout << "greeting: " << greeting << endl;
            return 0;
        }
    ```
- C++中有大量的函数用来操作以null结尾的字符串，见下表：
![常见字符串函数.png](https://upload-images.jianshu.io/upload_images/13407176-c8c24ff43b0e5f85.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

    ```
        // 字符串中的常见函数:
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
    ```
#### 1.2 C++中的字符串
- C++标准库提供了string类类型，支持上述所有的操作，另外还增加了其他更多的功能，见下面的实例:
    ```
        #include "string"
        // Cpp中的字符串
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
    ```
### 2.字符串中的细节知识
- string类提供了一系列针对字符串的操作，比如：
    - append() -- 在字符串的末尾添加字符
    - find() -- 在字符串中查找字符串
    - insert() -- 插入字符
    - length() -- 返回字符串的长度
    - replace() -- 替换字符串
    - substr() -- 返回某个子字符串
    ```
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
    ```
- C++中输入的方式很多，下面介绍与C语言中getchar()类似的函数cin.getline()函数,**cin.getline()是在输入一段字符完成后开始读取数据（注意，是输入完成后，以Enter为结束标志）**
    ```
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
    ```
- 字符串与vector
    - 字符串常量与标准库string不是同一种类型
        ```
            string s("hello");
            cout << "s.size() = " << s.size() << endl;  // 正确
            // cout << "hello".size() << endl;  错误
            cout << s + "world" << endl;  // 正确
            // cout << "hello" + "world" << endl;  错误
        ```
    - **strlen、sizeof与size()求字符串长度的区别:**
        ```
            cout << strlen("123") << endl;   //返回 3
            cout << sizeof("123") << endl;   //返回 4
            string s = "123";
            cout << s.size() << endl;        //返回 3
        ```
    -  **sizeof和strlen区分:**
        - sizeof操作符的结果类型是size_t，它在头文件中typedef为unsigned int类型。该类型保证能容纳实现所建立的最大对象的字节大小。
        - sizeof是运算符，strlen是函数
        - sizeof可以用类型做参数,如sizeof(int)，strlen只能用char*做参数，且必须是以'\0'结尾的。sizeof还可以用函数做参数，如short f();  cout << sizeof(f());
        - 数组做sizeof的参数不退化，传递给strlen就退化为指针了
        - 大部分编译程序在编译的时候就把sizeof计算过了，**是类型或是变量的长度**，这就是 sizeof(x)可以用来定义数组维数的原因。
            ```
                char str[20] = "0123456789";
                int a = strlen(str);  10
                int b = sizeof(str);  20
            ```
        - strlen的结果要在运行的时候才能计算出来，是用来计算字符串的长度，不是类型占内存的大小
        - **sizeof后如果是类型必须加括弧，如果是变量名可以不加括弧**。这是因为sizeof是个操作符不是个函数
        - 当适用一个结构类型或变量时，sizeof返回实际的大小；当适用一静态地空间数组，sizeof 返回全部数组的尺寸；sizeof操作符不能返回动态地被分派了的数组或外部的数组的尺寸。
    - 字符数组可以用数组名来输出数组内容，而普通数组不行
        - 原因:因为char型数组中的每一个元素都是1个字节，所以每一个字符之间的地址都是+1的，是连续的。所以当cou 输出时读到字符数组中的 '\0'便停止输出; 而int数组每个元素占4个字节，所以数组中每个元素地址的间隔是4，但其实它也是连续的，出现乱码是因没找到结束符。
            ```
                int aa[10] = {1, 2, 3, 4, 6, 7};
                char bb[6] = {'h', 'a', 'a', 'p', 'y', '\0'};
                char cc[] = "happy";
                cout << aa << endl;
                cout << bb << endl;
                cout << cc << endl;
            ```
- char数组的几种表示方法
    - C风格
        ```
            char greeting[6] = {'H', 'e', 'l', 'l', 'o', '\0'};
            char greeting[] = {'H', 'e', 'l', 'l', 'o', '\0'};
        ```
    - C++风格
        - string类
        - char*:指向字符串的指针，指向字符串的首个字母
        - const char*(常量指针)：指向的是一个const char类型，不能通过当前的指针对字符串的内容作修改
        - char * const(指针常量)：指针是一个常量，不能修改指针
        - char []：与char*有很多的相同点，代表字符数组，可以对应一个字符串；如char * a = "string1";  char b[] = "string2"; a是一个指向char类型的字符串的指针；b是一个字符数组
        - char *与char[]的不同：a是变量，指向可以改变；b是常量，是该字符数组的首地址，其值不能改变