### 1.Cpp中的数字
- 当需要用到数字时，我们会使用原始的数据类型，如int、short、long、float和double等等。这些用于数字的数据类型，其可能的值和数值范围，已经在C++数据类型中讨论过。
- 1.1 定义数字
```
int main(){
    // 数字定义
    short s;
    int i;
    long l;
    float f;
    double d;
    // 数字赋值
    s = 10;
    i = 1000;
    l = 1000000;
    f = 230.45;
    d = 4545.398;
    cout << "s = " << s << endl;
    cout << "i = " << i << endl;
    cout << "l = " << l << endl;
    cout << "f = " << f << endl;
    cout << "d = " << d << endl;
    return 0;
}
```
### 2.Cpp中的数学运算
- 在C++中，除了可以创建各种函数，还包含了各种有用的函数供你使用。**这些函数写在标准C和C++库中，叫做内置函数**，可以在程序中引用这些函数。C++内置了丰富的数学函数，可对各种数字进行运算。下表列出了C++中一些有用的内置的数学函数，**为了利用这些函数，需要引用数学头文件 \<cmath\>**。
![内置数学函数.png](https://upload-images.jianshu.io/upload_images/13407176-5e4401880a02ca90.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)
```
int main(){
    // 数字定义
    short s;
    int i;
    long l;
    float f;
    double d;
    // 数字赋值
    s = 10;
    i = - 1000;
    l = 1000000;
    f = 230.45;
    d = 4545.398;
    cout << "s = " << s << endl;
    cout << "i = " << i << endl;
    cout << "l = " << l << endl;
    cout << "f = " << f << endl;
    cout << "d = " << d << endl;
    // 数学运算
    cout << "sin(d) = " << sin(d) << endl;
    cout << "abs(i) = " << abs(i) << endl;
    cout << "floor(d) = " << floor(d) << endl;
    cout << "sqrt(f) = " << sqrt(f) << endl;
    cout << "pow(d, 2) = " << pow(d, 2) << endl;
    return 0;
}
```
### 3.Cpp中的随机数
- 在许多情况下，需要生成随机数。关于随机数生成器，有两个相关的函数。一个是rand()，该函数只返回一个伪随机数。**生成随机数之前必须先调用srand()函数**。
```
 // 随机数
    int m, n;
    // 设置随机数种子
    srand((unsigned)time(NULL)); // time()用来获取系统时间的秒数，通过调用rand()函数来生成随机数
    // 生成10个随机数
    for(m = 0; m < 10; m++){
        // 生成实际的随机数
        n = rand();
        cout << "随机数: " << n << endl;
    }
```
- srand()函数是随机数生成器的初始化函数,详细介绍如下：
    - 函数原型:  void srand(unsigned seed);
    - 用法: 它需要提供一个种子，这个种子会对应一个随机数，如果使用相同的种子，后面的rand()函数会出现一样的随机数。如：srand(1);直接使用1来初始化种子。为了防止随机数每次重复，常常使用系统时间来初始化，即用time函数来获得系统时间，它的返回值为从 00:00:00 GMT, January 1, 1970 到现在所持续的秒数，然后将time_t型数据转化为(unsigned)型再传给 srand 函数，即：srand((unsigned) time(&t)); 还有常用的方法：不需要定义time_t型的t变量,即：srand((unsigned) time(NULL)); 直接传入一个空指针，因为你的程序中往往并不需要经过参数获得的t数据。
    ```
        const int MAX = 10;
        int number[MAX] = {0};
        int k;
        srand((unsigned) time(NULL));  // 播种子
        for (k = 0; k < MAX; k++){
            number[k] = rand() % 100;  // 产生0-100内的随机数
            cout << "number[" << k << "] = " << number[k] << endl;
        }
    ```
- 补充说明：
    - rand随机数产生的范围:在标准C库中函数rand()可以生成0~RAND_MAX之间的一个随机数，其中RAND_MAX是stdlib.h中定义的一个整数，它与系统有关，至少是32767。
    - 使用rand()和srand()产生指定范围内的随机整数的方法: 模除+加法,如果要产生[m,n]范围内的随机数num，可用,int num = rand() % (n-m+1)+m;即(rand()%[区间内数的个数]+区间的起点值)
    ```
        #define random(x) (rand() % x)
        srand((int)time(0));
        for (int a = 0; a < 10; a++){
            cout << random(100) << endl; // 输出0-100内的随机数
        }
    ```