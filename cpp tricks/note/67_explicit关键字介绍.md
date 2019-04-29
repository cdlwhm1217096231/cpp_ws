### 1.explicit函数介绍
- 作用：explicit构造函数是用来防止隐式转换的
- 实例1如下:
    ```
        #include <iostream>

        using namespace std;

        // explicit函数的介绍!!!

        // explicit函数的作用：explicit构造函数是用来防止隐式转换的
        class Test1{
            public:
                Test1(int n){  // 普通隐式的构造函数
                    num = n;
                }
            private:
                int num;
        };

        class Test2{
            public:
                explicit Test2(int n){   //explicit(显式)构造函数
                    num = n;
                }
            private:
                int num;
        };

        int main(){
            Test1 t1 = 12;  // 隐式调用其构造函数,成功
            // Test2 t2 = 12;  编译错误,不能隐式调用其构造函数
            Test2 t3(12);  //  显式调用成功
            return 0;
        }
    ```
- Test1的构造函数带一个int型的参数，会隐式转换成调用Test1的这个构造函数。而Test2的构造函数被声明为explicit（显式），这表示不能通过隐式转换来调用这个构造函数，因此Test2 t2 = 12会出现编译错误。普通构造函数能够被隐式调用,而explicit构造函数只能被显式调用。
- 实例2如下:
    ```
        class Test{
            public:
                Test():a(0){
                    cout << "void\n";
                }
                explicit Test(int i):a(i){
                    cout << "int\n";
                }
                Test(short s):a(s){
                    cout << "short\n";
                }
                Test & operator=(int n){
                    a = n;
                    cout << "operator = ";
                }
            private:
                int a;
        };
        int main(){
            int n;
            Test a = n;
            return 0;
        }
    ```
- A:接受一个参数的构造函数允许使用赋值语句隐式调用来初始化对象; 而explicit构造函数只能被显式调用!所以，输出的是short！