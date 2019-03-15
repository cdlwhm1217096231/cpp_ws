### 1.循环类型
- cpp中提供了以下几种循环类型：
![循环类型.png](https://upload-images.jianshu.io/upload_images/13407176-76f0a3c7a10d4f85.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)
- 1.1 while循环
- cpp中的while循环格式：
    ```
        while(循环条件){
            语句1;
            ...
            语句n;
        }
    ```
- while 循环的关键点是循环可能一次都不会执行。当条件被测试且结果为假时，会跳过循环主体，直接执行紧接着 while 循环的下一条语句。
- 1.2 for循环
- cpp中的for循环格式：
    ```
        for(初始化语句; 判断条件; 变化条件){
            语句1;
            ...
            语句n;
        }
    ```
- for循环控制过程：
    - 初始化会首先被执行，且只会执行一次。这一步允许您声明并初始化任何循环控制变量。也可以不在这里写任何语句，只要有一个分号出现即可。
    - 接下来，会判断判断条件是否成立。如果为真，则执行循环主体。如果为假，则不执行循环主体，且控制流会跳转到紧接着for循环的下一条语句
    - 在执行完for循环主体后，控制流会跳回上面的变化条件语句。该语句允许您更新循环控制变量。该语句可以留空，只要在条件后有一个分号出现即可。
    - 条件再次被判断。如果为真，则执行循环，这个过程会不断重复（循环主体，然后增加步值，再然后重新判断条件）。在条件变为假时，for 循环终止。
- 1.3 do-while循环
- **不像for和while循环，它们是在循环头部测试循环条件。do...while 循环是在循环的尾部检查它的条件。**do...while循环与while循环类似，但是**do...while循环会确保至少执行一次循环**。
- 语法格式：
    ```
        do{
            语句1;
            ...
            语句n;
        }while(判断条件);
    ```
- **请注意，条件表达式出现在循环的尾部，所以循环中的语句会在条件被测试之前至少执行一次。**如果条件为真，控制流会跳转回上面的 do，然后重新执行循环中的语句。这个过程会不断重复，直到给定条件变为假为止。
- 1.4 嵌套循环
- 一个循环内可以嵌套另一个循环,C++允许至少 256 个嵌套层次。可以在任何类型的循环内嵌套其他任何类型的循环。比如，一个 for 循环可以嵌套在一个 while 循环内，反之亦然。
- 语法：
```
// 嵌套for循环
for ( init; condition; increment )
{
   for ( init; condition; increment )
   {
      statement(s);
   }
   statement(s); // 可以放置更多的语句
}

// 嵌套while循环
while(condition)
{
   while(condition)
   {
      statement(s);
   }
   statement(s); // 可以放置更多的语句
}

// 嵌套do...while循环
do
{
   statement(s); // 可以放置更多的语句
   do
   {
      statement(s);
   }while( condition );
 
}while( condition );
```
### 2.循环控制语句
- 循环控制语句更改执行的正常序列。当执行离开一个范围时，所有在该范围中创建的自动对象都会被销毁。
![循环控制语句.png](https://upload-images.jianshu.io/upload_images/13407176-807aadf172679e1e.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)
- 2.1 break语句
- C++中break语句有以下两种用法：
    - 当break语句出现在一个循环内时，循环会立即终止，且程序流将继续执行紧接着循环的下一条语句。
    - 它可用于终止 switch 语句中的一个 case
- 如果使用的是嵌套循环（即一个循环内嵌套另一个循环），break语句会停止执行最内层的循环，然后开始执行该块之后的下一行代码。
- 2.2 continue语句
- C++ 中的 continue 语句有点像 break 语句。但它不是强迫终止，continue 会跳过当前循环中的代码，强迫开始下一次循环。
- 对于for循环，continue语句会导致执行条件测试和循环增量部分。对于while和do...while循环，continue语句会导致程序控制回到条件测试上。
