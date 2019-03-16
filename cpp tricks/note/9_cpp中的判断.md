### 1.Cpp中的判断语句
- C++ 编程语言提供了以下类型的判断语句：
![循环语句.png](https://upload-images.jianshu.io/upload_images/13407176-9f13fc19995cf699.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)
- 1.1 if语句
- 一个if语句由一个布尔表达式后跟一个或多个语句组成。如果布尔表达式为true，则if语句内的代码块将被执行。如果布尔表达式为false，则if语句结束后的第一组代码（闭括号后）将被执行。C语言把任何非零和非空的值假定为true，把零或null假定为false。
    ```
    语法格式:
        if(布尔表达式){
            语句1;
            ...
            语句n;
        }
    ```
- 1.2 if...else语句
- 一个if语句后可跟一个可选的else语句，else语句在布尔表达式为假时执行。如果布尔表达式为true，则执行if块内的代码。如果布尔表达式为false，则执行else块内的代码。
    ```
    语法格式：
        if(布尔表达式){
            语句1;
            ...
            语句n;
        }else{
            语句1;
            ...
            语句n;
        }
    ```
- 一个if语句后可跟一个可选的else if...else语句，这可用于测试多种条件。当使用if...else if...else语句时，以下几点需要注意：
    - 一个if后可跟零个或一个else，else必须在所有else if之后。
    - 一个if后可跟零个或多个else if，else if必须在else之前。
    - 一旦某个else if匹配成功，其他的else if或else将不会被测试。
    ```
        语法格式：
            if (布尔表达式1){
                布尔表达1成立时执行
            }else if(布尔表达式2){
                布尔表达式2成立时执行
            }else if(布尔表达式3){
                布尔表达式3成立时执行
            }else{
                以上条件都不满足时执行
            }
    ```
- 1.3 嵌套if语句
- 在C++中，嵌套if-else语句是合法的，这意味着可以在一个if或else if语句内使用另一个if或else if语句。
    ```
    语法格式：
        if(布尔表达式1){
            // 布尔表达式1成立时执行
            if(布尔表达式2){
                // 布尔表达式2成立时执行
            }
        }
    ```
- 1.4 switch语句
- 一个switch语句允许测试一个变量等于多个值时的情况。每个值称为一个case，且被测试的变量会对每个 switch case进行检查。
    ```
    语法格式：
        switch(expression){
            case 常量表达式1:
                语句1;
                ...
                语句n;
                break;  // 可选
            case 常量表达式2:
                语句1;
                ...
                语句n;
                break;  // 可选
            ...
            case 常量表达式n:
                语句1;
                ...
                语句n;
                break;  // 可选
            default:  // 可选
                语句1;
                ...
                语句n;
                break;  // 可选
        }
    ```
- switch语句必须遵循下面的规则：
    - switch语句中的expression必须是一个整型或枚举类型，或者是一个class类型，其中class有一个单一的转换函数将其转换为整型或枚举类型。
    - 在一个switch中可以有任意数量的case语句。每个case后跟一个要比较的值和一个冒号。
    - case的常量表达式必须与switch中的变量具有相同的数据类型，且必须是一个常量或字面量。
    - 当被测试的变量等于case中的常量时，case后跟的语句将被执行，直到遇到break语句为止。
    - 当遇到break语句时，switch终止，控制流将跳转到switch语句后的下一行。
    - 不是每一个case都需要包含break。如果case语句不包含break，控制流将会继续后续的case，直到遇到break为止。
    - 一个switch语句可以有一个可选的 default case，出现在switch的结尾。default case可用于在上面所有case都不为真时执行一个任务。default case中的break语句不是必需的。
- 1.5 嵌套switch语句
- 可以把一个switch作为一个外部switch 的语句序列的一部分，即可以在一个switch语句内使用另一个 switch语句。即使内部和外部switch的case常量包含共同的值，也没有矛盾。
    ```
    语法格式：
    switch(ch1) {
    case 'A': 
        cout << "这个 A 是外部 switch 的一部分";
        switch(ch2) {
            case 'A':
                cout << "这个 A 是内部 switch 的一部分";
                break;
            case 'B': // 内部 B case 代码
        }
        break;
    case 'B': // 外部 B case 代码
    }
    ```
### 2.?:运算符
- ?:可以用来替代 if...else 语句。它的一般形式如下：
    ```
    Exp1 ? Exp2 : Exp3;
    ```
- 其中，Exp1、Exp2和Exp3是表达式。**请注意，冒号的使用和位置。**? 表达式的值是由Exp1决定的。如果Exp1为真，则计算Exp2的值，结果即为整个?表达式的值。如果Exp1为假，则计算Exp3的值，结果即为整个 ? 表达式的值。

