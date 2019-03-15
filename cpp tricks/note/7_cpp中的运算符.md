### 1.Cpp运算符
- 运算符是一种告诉编译器执行特定的数学或逻辑操作的符号。C++ 内置了丰富的运算符，并提供了以下类型的运算符：
    - 算术运算符
    - 关系运算符
    - 逻辑运算符
    - 位运算符
    - 赋值运算符
    - 杂项运算符
### 2.算术运算符
- 下表显示了 C++ 支持的算术运算符,假设变量 A 的值为 10，变量 B 的值为 20，则：
![算术运算符.png](https://upload-images.jianshu.io/upload_images/13407176-cad8860386472877.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)
```
// 算术运算符
    int a = 21;
    int b = 10;
    int c;
    c = a + b;
    cout << "c = " << c << endl;
    c =  a - b;
    cout << "c = " << c << endl;
    c = a * b;
    cout << "c = " << c << endl;
    c = a / b;
    cout << "c = " << c << endl;
    c = a % b;  // 取余运算符
    cout << "c = " << c << endl;

    int d = 10;
    c = d++; // 自加
    cout << "c = " << c << endl;

    d = 10;
    c = d--; // 自减
    cout << "c = " << c << endl;
```
### 3.关系运算符
- 下表显示了 C++ 支持的关系运算符,假设变量 A 的值为 10，变量 B 的值为 20，则：
![关系运算符.png](https://upload-images.jianshu.io/upload_images/13407176-5b095bc52e68774d.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)
```
// 关系运算符
    int aa = 21, bb = 10;
    int cc;
    if (aa == bb)
        cout << "aa == bb\n";
    else    
        cout << "aa != bb\n";
    if (aa > bb)
        cout << "aa > bb\n";
    else    
        cout << "aa < bb\n";
    if (aa < bb)
        cout << "aa < bb\n";
    else    
        cout << "aa > bb\n";
    if (aa != bb)
        cout << "aa != bb\n";
    else
        cout << "aa == bb\n"; 
    aa = 5;
    bb = 20;
    if ( aa <= bb )
        cout << "aa小于或等于bb" << endl ;
    if ( bb >= aa )
        cout << "bb大于或等于aa" << endl ;
```
### 4.逻辑运算符
- 下表显示了 C++ 支持的关系逻辑运算符,假设变量 A 的值为 1，变量 B 的值为 0，则：
![逻辑运算符.png](https://upload-images.jianshu.io/upload_images/13407176-21cf964e21888a94.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)
- 关于逻辑运算符&&和||的巧用方式：
    - && 会先判断左边的值是否为真。如果为假，那么整个表达式毫无疑问也为假。如果为真，那就还需要判断右值，才能知道整个式子的值。这个时候判断右值的过程就起了一个if的作用，可以利用这个过程判断右边表达式是否为真
        ```
            /*不用任何循环语句，不用if，来实现1+2+3+...+10的值*/
            int add(int c)
            {
                int a=0;
                c && (a = add(c-1));//递归循环，直到传入c的值为0则结束循环
                cout << c + a << endl;
                return c + a;
            }
            int main()
            { 
                add(10);
                return 0;
            }
        ```
    - 逻辑或 ||都是先判断左边是否为真，再来考虑右边。因为逻辑与 || 只需要左边为真，那么整个表达式就有值，就不会再去算右边的值了。所以加个!让c值为假时，!c才为真，这样的话逻辑与 || 还需要判断右边的表达式才能计算出整个表达式的值。
        ```
            int add(int c)
            {
                int a = 0;
                (!c) || (a = add(c-1));//递归循环，直到传入c的值为0，(!c)就为真，结束循环
                cout << c+a <<endl;
                return c + a;
            }
            int main()
            { 
                add(10);
                return 0;
            }
        ```
        

### 5.位运算符
- 位运算符作用于位，并逐位执行操作。&、 | 和 ^ 的真值表如下所示：
![位运算符真值表.png](https://upload-images.jianshu.io/upload_images/13407176-88636e0bc1c34fa8.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)
- 假设如果 A = 60，且 B = 13，现在以二进制格式表示，它们如下所示：
```
A = 0011 1100
B = 0000 1101
-----------------
A&B = 0000 1100
A|B = 0011 1101
A^B = 0011 0001
~A  = 1100 0011
```
- 下表显示了 C++ 支持的位运算符。假设变量 A 的值为 60，变量 B 的值为 13，则：
![位运算符.png](https://upload-images.jianshu.io/upload_images/13407176-b89f02a2697908b5.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)
```
    unsigned int a2 = 60;
    unsigned int b2 = 13;
    int c2 = 0;
    c2 = a2 & b2;
    cout << "a2 & b2: " << c2 << endl;
    c2 = a2 | b2;
    cout << "a2 | b2: " << c2 << endl;
    c2 = a2 ^ b2;
    cout << "a2 ^ b2: " << c2 << endl;
    c2 = ~a2;
    cout << "~a2: " << c2 << endl;
    c2 = a2 << 2;
    cout << "a2 << 2: " << c2 << endl;
    c2 = a2 >> 2;
    cout << "a2 >> 2: " << c2 << endl;  
```
### 6.赋值运算符
- 下表列出了 C++ 支持的赋值运算符：
![赋值运算符.png](https://upload-images.jianshu.io/upload_images/13407176-141e6a97a353e4c8.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)
```
// 赋值运算符
    int a3 = 21;
    int c3;
    c3 = a3;
    cout << "c3 = " << c3 << endl;
    c3 += a3;
    cout << "c3 = " << c3 << endl;
    c3 -= a3;
    cout << "c3 = " << c3 << endl;
    c3 *= a3;
    cout << "c3 = " << c3 << endl;
    c3 /= a3;
    cout << "c3 = " << c3 << endl;
    c3 = 200;
    c3 %= a3;
    cout << "c3 = " << c3 << endl;
    c3 <<= 2;
    cout << "c3 = " << c3 << endl;
    c3 >>= 2;
    cout << "c3 = " << c3 << endl;
    c3 &= 2;
    cout << "c3 = " << c3 << endl;
    c3 ^= 2;
    cout << "c3 = " << c3 << endl;
    c |= 2;
    cout << "c3 = " << c3 << endl;
```
### 7.杂项运算符
- 下表列出了 C++ 支持的其他一些重要的运算符:
![杂项运算符.png](https://upload-images.jianshu.io/upload_images/13407176-15fd2d4f0ae79b4d.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)
- 7.1 sizeof是一个关键字，它是一个编译时运算符，用于判断变量或数据类型的字节大小。sizeof 运算符可用于获取类、结构、共用体和其他用户自定义数据类型的大小。
```
语法格式：sizeof(数据类型/变量名);
cout << "Size of char : " << sizeof(char) << endl;
cout << "Size of int : " << sizeof(int) << endl;
cout << "Size of short int : " << sizeof(short int) << endl;
cout << "Size of long int : " << sizeof(long int) << endl;
cout << "Size of float : " << sizeof(float) << endl;
cout << "Size of double : " << sizeof(double) << endl;
cout << "Size of wchar_t : " << sizeof(wchar_t) << endl;
```
- 7.2 条件运算符,语法格式: Exp1 ? Exp2:Exp3; 其中，Exp1、Exp2 和 Exp3 是表达式。请注意冒号的使用和位置。? : 表达式的值取决于 Exp1 的计算结果。如果 Exp1 为真，则计算 Exp2 的值，且 Exp2 的计算结果则为整个 ? : 表达式的值。如果 Exp1 为假，则计算 Exp3 的值，且 Exp3 的计算结果则为整个 ? : 表达式的值。? 被称为三元运算符，因为它需要三个操作数。
```
int main ()
{
   // 局部变量声明
   int x, y = 10;
   x = (y < 10) ? 30 : 40;
   cout << "value of x: " << x << endl;
   return 0;
}
```
- 7.3 Cpp成员运算符
- .（点）运算符和 ->（箭头）运算符用于引用类、结构和共用体的成员。点运算符应用于实际的对象。箭头运算符与一个指向对象的指针一起使用。例如，假设有下面的结构：
```
struct Employee{
    char first_name[18];
    int age;
};
Employ emp;
strcpy(emp.first_name, "zara");   点运算符
// 如果 p_emp 是一个指针，指向类型为 Employee 的对象，则要把值 "zara" 赋给对象 emp 的 first_name 成员，需要编写如下代码：
strcpy(p_emp->first_name, "zara");  箭头运算符
```
- 7.4 C++强制转换运算符
- 强制转换运算符是一种特殊的运算符，它把一种数据类型转换为另一种数据类型。强制转换运算符是一元运算符，它的优先级与其他一元运算符相同。大多数的 C++ 编译器都支持大部分通用的强制转换运算符：(type) 表达式;其中，type 是转换后的数据类型。下面列出了 C++ 支持的其他几种强制转换运算符：
    - const_cast<type> (expr): const_cast运算符用于修改类型的const/volatile属性。除了const 或 volatile 属性之外，目标类型必须与源类型相同。这种类型的转换主要是用来操作所传对象的const属性，可以加上const属性，也可以去掉const属性。
    - dynamic_cast<type> (expr): dynamic_cast 在运行时执行转换，验证转换的有效性。如果转换未执行，则转换失败，表达式 expr 被判定为 null。dynamic_cast 执行动态转换时，type 必须是类的指针、类的引用或者 void*，如果 type 是类指针类型，那么 expr 也必须是一个指针，如果 type 是一个引用，那个 expr 也必须是一个引用。
    - reinterpret_cast<type> (expr): reinterpret_cast 运算符把某种指针改为其他类型的指针。它可以把一个指针转换为一个整数，也可以把一个整数转换为一个指针。
    - static_cast<type> (expr): static_cast 运算符执行非动态转换，没有运行时类检查来保证转换的安全性。例如，它可以用来把一个基类指针转换为派生类指针。
- 7.5 C++ 指针运算符（& 和 *）
- C++ 提供了两种指针运算符，一种是取地址运算符 &，一种是间接寻址运算符\*。指针是一个包含了另一个变量地址的变量，可以**把一个包含了另一个变量地址的变量说成是"指向"另一个变量**。变量可以是任意的数据类型，包括对象、结构或者指针。
- 取地址运算符 &
    - &是一元运算符，返回操作数的内存地址。例如，如果var是一个整型变量，则 &var是它的地址。该运算符与其他一元运算符具有相同的优先级，在运算时它是从右向左顺序进行的。**可以把&运算符读作"取地址运算符"，这意味着，&var 读作"var的地址"。**        
- 间接寻址运算符\*
    - 第二个运算符是间接寻址运算符 \*，它是 & 运算符的补充。\* 是一元运算符，**返回操作数所指定地址的变量的值**。
```
int main ()
{
   int  var;
   int  *ptr;
   int  val;

   var = 3000;

   // 获取 var 的地址
   ptr = &var;

   // 获取 ptr 的值
   val = *ptr;
   cout << "Value of var :" << var << endl;
   cout << "Value of ptr :" << ptr << endl;
   cout << "Value of val :" << val << endl;

   return 0;
}
```
### 8.Cpp中的运算符优先级
- 运算符的优先级确定表达式中项的组合。这会影响到一个表达式如何计算。某些运算符比其他运算符有更高的优先级，例如，乘除运算符具有比加减运算符更高的优先级。**下表将按运算符优先级从高到低列出各个运算符，具有较高优先级的运算符出现在表格的上面，具有较低优先级的运算符出现在表格的下面**。在表达式中，较高优先级的运算符会优先被计算。
![运算符优先级.png](https://upload-images.jianshu.io/upload_images/13407176-53bbb70a68c12ed4.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)
```
  // 运算符优先级
    int a4 = 20;
    int b4 = 10;
    int c4 = 15;
    int d4 = 5;
    int e4;
    
    e4 = (a4 + b4) * c4 / d4;      // ( 30 * 15 ) / 5
    cout << "(a4 + b4) * c4 / d4 的值是 " << e4 << endl ;
    
    e4 = ((a4 + b4) * c4) / d4;    // (30 * 15 ) / 5
    cout << "((a4 + b4) * c4) / d4 的值是 " << e4 << endl ;
    
    e4 = (a4 + b4) * (c4 / d4);   // (30) * (15/5)
    cout << "(a4 + b4) * (c4 / d4) 的值是 " << e4 << endl ;
    
    e4= a4 + (b4 * c4) / d4;     //  20 + (150/5)
    cout << "a4 + (b4 * c4) / d4 的值是 " << e4 << endl ;
```
