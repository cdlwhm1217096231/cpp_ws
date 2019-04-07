### 1.Cpp中的命名空间
- 假设这样一种情况，当一个班上有两个名叫Zara的学生时，为了明确区分它们，我们在使用名字之外，不得不使用一些额外的信息，比如他们的家庭住址，或者他们父母的名字等等。同样的情况，在C++程序中，可能会写一个xyz()的函数，而在另一个可用的库中也存在一个同名的函数xyz()。这样，编译器就无法判断我们到底使用的是哪一个xyz()函数。因此，引入**命名空间**这个概念用于解决上面的问题，它可以作为附加信息来区分不同库中相同名称的函数、类、变量等。使用了命名空间即定义了上下文，**本质上就是定义了一个范围**。
### 2.定义命名空间
- 命名空间的定义使用关键字namespace,后面接着命名空间的名字，如下所示：
    ```     
        namespace 命名空间的名字{
            // 代码声明
        }
    ```
- 为了调用带有命名空间的函数或变量，需要在前面加上命名空间的名字，如下所示：
    ```
        命名空间的名字::code;   // code可以是变量或函数
    ```
- 使用命名空间为变量或函数等实体定义范围:
    ```
        #include "iostream"

        using namespace std;

        // 第一个命名空间
        namespace first_space{
            void func(){
                cout << "I come from frist space.\n";
            }
        }

        // 第二个命名空间
        namespace second_space{
            void func(){
                cout << "I come from second space.\n";
            }
        }

        int main(){
            // 调用第一个命名空间中的函数
            first_space::func();
            // 调用第二个命名空间中的函数
            second_space::func();
            return 0;
        }
    ```
### 3.using指令
- **可以使用using namespace指令，这样在使用命名空间时就可以不用在前面加上命名空间的名称**。这个指令会告诉编译器，后续的代码将使用指定的命名空间中的名称，实例见下面：
    ```
        #include "iostream"

        using namespace std;   // 使用标准命名空间

        // 第一个命名空间
        namespace first_space{
            void func(){
                cout << "I come from frist space.\n";
            }
        }

        // 第二个命名空间
        namespace second_space{
            void func(){
                cout << "I come from second space.\n";
            }
        }

        // 第三个命名空间
        namespace third_space{
            void func(){
                cout << "I come from third space.\n";
            }
        }

        using namespace third_space;  // 注意这一句！！！

        int main(){
            // 调用第一个命名空间中的函数
            first_space::func();
            // 调用第二个命名空间中的函数
            second_space::func();
            // 调用第三个命名空间中的函数
            func(); // 注意调用格式！！！
            return 0;
        }
    ```
- using指令也可以用来指定命名空间中的特定项目。如果，这只打算使用标准命名空间std中的cout部分，可以使用如下的语句:
    ```
        using std::cout;
    ```
- 随后的代码中，在使用cout时就可以不用加上命名空间的名字作为前缀，但是std命名空间中的其他项目仍然需要加上命名空间的名字作为前缀，如：
    ```
        #include "iostream"

        using std::cout;

        int main(){
            cout << "hello world." << std::endl;   // 注意，此处的std::endl与cout的格式区别！！！
            return 0;
        }
    ```
- using指令引入的命名空间的名字遵循正常的范围规则，名字从使用using指令开始是可见的，直到该范围结束。此时，在范围以外定义的同名实例是隐藏的。
### 4.不连续的命名空间
- **命名空间可以定义在几个不同的部分中。因此，命名空间是由几个单独定义的部分组成的。一个命名空间的各个组成部分可以分散在多个文件中**。所以，如果命名空间中的某个组成部分需要请求定义在另一个文件中的名称，则仍然需要声明该名称。下面的命名空间定义可以是定义一个新的命名空间，也可以是为已有的命名空间增加新的元素：
    ```
        namespace 命名空间的名字{
            // 代码声明
        }
    ```
### 5.命名空间的嵌套
- 命名空间可以嵌套，可以在一个命名空间中定义另一个命名空间，如下所示：
    ```
        namespace 命名空间1的名字{
            // 代码声明
            namespace 命名空间2的名字{
                // 代码声明
            }
        }
    ```
- 可以通过使用::运算符访问嵌套的命名空间中的成员，如下所示:
    ```
        // 访问命名空间2中的成员
        using namespace 命名空间1的名字::命名空间2的名字
        // 访问命名空间1中的成员
        using namespace 命名空间1的名字
    ```
- 上面的语句中，如果使用的是命名空间1,那么在该范围内命名空间2中的元素也是可以使用的，如下所示:
    ```
        // 命名空间的嵌套
        namespace four_space{
            void fun(){
                cout << "I come from four space.\n";
            }
            namespace five_space{
                void fun(){
                    cout << "I come from five space.\n";
                }
            }
        }

        using namespace four_space::five_space;
        using namespace four_space;

        int main(){
            // 调用第二个命名空间中的函数
            fun();
            // 调用第二个命名空间中的函数
            five_space::fun();
            return 0;
        }
    ```