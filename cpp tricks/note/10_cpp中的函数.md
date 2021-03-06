### 1.Cpp中的函数
- 函数是一组一起执行一个任务的语句。每个C++ 序都至少有一个函数，即主函数main() ，所有简单的程序都可以定义其他额外的函数。
- 函数声明告诉编译器函数的名称、返回类型和参数;函数定义提供了函数的实际主体
- C++标准库提供了大量的程序可以调用的内置函数。例如，函数strcat()用来连接两个字符串，函数 memcpy()用来复制内存到另一个位置。函数还有很多叫法，比如方法、子例程或程序，等等.
### 2.定义函数
- C++中定义函数的一般形式如下：
    ```
        返回值类型 函数名(形参列表){
            函数体
        }
    ```
- 在C++中，函数由一个函数头和一个函数主体组成。下面列出一个函数的所有组成部分：
    - 返回类型：一个函数可以返回一个值。返回值类型是函数返回的值的数据类型。有些函数执行所需的操作而不返回值，在这种情况下，返回值是关键字void。
    - 函数名称：这是函数的实际名称。函数名和形式参数列表一起构成了函数签名。
    - 参数：参数就像是占位符。当函数被调用时，可以向参数传递一个值，这个值被称为实际参数。形式参数列表包括函数形式参数的类型、顺序、数量。形式参数是可选的，也就是说，函数可能不包含形式参数。
    - 函数主体：函数主体包含一组定义函数执行任务的语句。
    ```
        int maxnum(int num1, int num2);  // 函数声明
        int main(){
            int num1 = 3, num2 = 6;
            int result;
            result = maxnum(num1, num2);  // 调用函数maxnum()
            cout << "两个数之间的最大数是: " << result << endl;
            return 0;
        }


        // 函数定义
        int maxnum(int num1, int  num2){
            if (num1 > num2)
                result = num1
            else
                result = num2;
            return result;
        }
    ```
### 3.函数声明
- 函数声明会告诉编译器函数名称及如何调用函数。函数的实际主体可以单独定义。函数声明包括以下几个部分：
    ```
        返回值类型 函数名(形参列表);
    ```
- 针对上面定义的函数maxnum()，以下是函数声明：
    ```
        int maxnum(int num1, int num2);
    ```
- **在函数声明中，参数的名称并不重要，只有参数的类型是必需的**，因此下面也是有效的声明：
    ```
        int maxnum(int, int);
    ```
- **当在一个源文件中定义函数且在另一个文件中调用此函数时，函数声明是必需的。在这种情况下，应该在调用函数的文件顶部声明函数。**
### 4.调用函数
- 创建C++函数时，会定义函数做什么，然后通过调用函数来完成已定义的任务。当程序调用函数时，程序控制权会转移给被调用的函数。被调用的函数执行已定义的任务，当函数的返回语句被执行时，或到达被调用函数的结束括号时，会把程序控制权交还给主程序。调用函数时，传递所需参数，如果函数返回一个值，则可以存储返回值，具体见上面的示例程序。
### 5.函数参数
- 如果函数要使用参数，则必须声明接受参数值的变量。这些变量称为函数的**形式参数**。形式参数就像函数内的其他局部变量，在进入函数时被创建，退出函数时被销毁。**默认情况下，C++使用传值调用来传递参数**。一般来说，这意味着被调用函数内的代码不能改变用于调用函数的实际参数。当调用函数时，有三种向被调用函数传递参数的方式：
![函数参数传递3种方式.png](https://upload-images.jianshu.io/upload_images/13407176-d233bdf69783b19a.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)
- 5.1 传值调用
- 传值调用:形参是实参的拷贝，改变形参的值并不会影响外部实参的值。从被调用函数的角度来说，值传递是单向的（实参->形参），参数的值只能传入，不能传出。当函数内部需要修改参数，并且不希望这个改变影响调用者时，采用值传递。**把实际参数的实际值复制一份再传给被调用函数的形式参数**。在这种情况下，修改被调用函数内的形式参数不会影响实际参数。默认情况下，C++使用传值调用方法来传递参数。一般来说，这意味着被调用函数内的代码不会改变用于调用函数的实际参数。函数 swap() 定义如下：
    ```
        // 传值调用方式
        void swap(int a, int b){
            int temp;
            temp = a;
            a = b;
            b = temp;
        }
        // 1 传值调用
        int a = 4, b = 40;
        cout << "交换前的a, b值: " << "a = " << a << ",b = " << b << endl;
        swap(a, b);  // 传值调用只是形参从实参那复制了一份实参的值，被调用函数内的代码不会改变用于调用函数的实际参数
        cout << "交换后的a, b值: " << "a = " << a << ",b = " << b << endl;
    ```
- 5.2 指针调用
- 指针调用:形参为指向实参地址的指针，当对形参的指向操作时，就相当于对实参本身进行的操作。**把实际参数的地址复制给被调用函数中的形式参数**。在被调用函数中，从实际参数那复制过来的地址可以用于访问调用中要用到的实际参数。这意味着，**修改形式参数会影响实际参数**。
- 按指针传递值，参数指针被传递给函数，就像传值给函数一样。因此相应地，在下面的函数swap1()中，需要声明函数形式参数为指针类型，该被调用函数用于交换参数所指向的两个整数变量的值。
    ```
        // 指针传递方式
        void swap1(int *a, int *b){
            int temp;
            temp = *a;
            *a = *b;
            *b = temp;
        }
         // 2 指针调用
        int x = 4, y = 40;
        cout << "交换前的x, y值: " << "x = " << x << ",y = " << y << endl;
        swap1(&x, &y); // 实际参数将实际值的地址复制后再传给形式参数，形式参数获得地址后，在被调用函数的内部可以通过传进来的地址访问调用中用到的实际参数，修改形式参数会影响实际参数！
        cout << "交换后的x, y值: " << "x = " << x << ",y = " << y << endl;
    ```
- 5.3 引用调用
- 引用调用: 形参相当于是实参的"别名"，对形参的操作其实就是对实参的操作，在引用传递过程中，被调函数的形式参数虽然也作为局部变量在栈中开辟了内存空间，但是这时存放的是由主调函数放进来的实参变量的地址。被调函数对形参的任何操作都被处理成间接寻址，即通过栈中存放的地址访问主调函数中的实参变量。正因为如此，被调函数对形参做的任何操作都影响了主调函数中的实参变量。**把实际参数的引用的地址复制给形式参数**。在被调用函数内，该引用用于访问调用中要用到的实际参数。这意味着，**修改形式参数会影响实际参数**。
- 按引用传递值，即实际参数的引用被传递给被调用函数，就像传递其他值给被调用函数一样。因此，在下面的函数swap2()中，需要声明函数参数为引用类型，该函数用于交换参数所指向的两个整数变量的值。
    ```
        // 引用传递方式
        void swap2(int &a, int &b){
            int temp;
            temp = a;
            a = b;
            b = temp;
        }
        // 3 引用调用
        int m = 4, n = 40;
        cout << "交换前的m, n值: " << "m = " << m << ",n = " << n << endl;
        swap2(m, n); // 将实参的引用的地址复制了一份传给形参,形式参数获得实际参数引用的地址后，在被调用函数的内部可以通过传进来的实际参数的引用的地址访问调用中用到的实际参数，修改形式参数会影响实际参数！
        cout << "交换后的m, n值: " << "m = " << m << ",n = " << n << endl;
    ```
