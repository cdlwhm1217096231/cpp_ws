### 1.Cpp中的结构体
- C/C++数组允许定义可存储相同类型数据项的变量，但是结构体是C++中另一种**用户自定义**的可用的数据类型，**它允许存储不同类型的数据项**。结构体用于表示一条记录，假设想要跟踪图书馆中书本的状态，可能需要跟踪每本书的下列属性:
    ```
        Title: 标题
        Author: 作者
        Subject: 类别
        Book ID: 书的ID
    ```
### 2.定义结构体
- 为了定义结构体，必须使用struct语句。struct语句定义了一个包含多个成员的新的数据类型！struct语句的格式如下：
    ```
        struct 结构体类型的名字{
            成员1类型 成员1的名字;
            成员2类型 成员2的名字;
            ...
            成员n类型 成员n的名字;
        }结构体变量名;
    ```
- **在结构体定义的末尾，最后一个分号之前，可以指定一个或多个结构变量，这是可选的**。实例如下：
    ```
        struct Book{  // Book是结构体类型名
            char title[50];
            char author[50];
            char subject[100];
            int book_id;
        }book; // book是变量名
    ```
### 3.访问结构体成员
- 为了访问结构体的成员，使用成员访问运算符'.',成员访问运算符是结构体变量名称和要访问的结构体成员之间的一个点号,见具体的实例:
    ```
        Books book1;   // 定义结构体类型Books的变量book1
        Books book2;   // 定义结构体类型Books的变量book2
        // book1详细介绍
        strcpy(book1.title, "C++教程");
        strcpy(book1.author, "菜鸟教程");
        strcpy(book1.subject, "编程语言");
        book1.book_id = 123;
        // 输出book1的详细信息
        cout << "book1的标题: " << book1.title << endl;
        cout << "book1的作者: " << book1.author << endl;
        cout << "book1的类别: " << book1.subject << endl;
        cout << "book1的id: " << book1.book_id << endl;
        cout << "----------------------------------------------------\n";
        // book2详细介绍
        strcpy(book2.title, "白夜行");
        strcpy(book2.author, "东野圭吾");
        strcpy(book2.subject, "文学");
        book2.book_id = 666;
        // 输出book2的详细信息
        cout << "book2的标题: " << book2.title << endl;
        cout << "book2的作者: " << book2.author << endl;
        cout << "book2的类别: " << book2.subject << endl;
        cout << "book2的id: " << book2.book_id << endl;
    ```
### 4.结构体作为函数参数
- 把结构体作为函数的参数，传递参数的方式与其他类型的变量或指针类型，具体见下面的实例：
    ```
        // 结构体作为函数参数
        void print_book_info(struct Books book){
        cout << "书的标题: " << book.title << endl; 
        cout << "书的作者: " << book.author << endl;
        cout << "书的类别: " << book.subject << endl;
        cout << "书的id: " << book.book_id << endl;
        }
        print_book_info(book1);
        cout << "----------------------------------------------------\n";   
        print_book_info(book2);
    ```
### 5.指向结构体的指针
- 定义指向结构体的指针，方式与定义指向其他类型变量的指针类型：
    ```
        struct Books *struct_pointer;
    ```
- 在上述定义的指针变量中存储结构体变量的地址，为了查找结构体变量的地址，把&运算符放在结构体名称的前面：
    ```
        struct_pointer = &book1;
    ```
- 为了使用指向该结构体的指针来访问结构体的成员，必须使用箭头->运算符：
    ```
        struct_pointer->title;
    ```
- 具体见下面的实例：
    ```
        // 指向结构体的指针,下面的函数以结构体指针作为函数形参
            void print_book_info_with_pointer(struct Books *book_pointer){
            cout << "书的标题: " << book_pointer->title << endl; 
            cout << "书的作者: " << book_pointer->author << endl;
            cout << "书的类别: " << book_pointer->subject << endl;
            cout << "书的id: " << book_pointer->book_id << endl;
        }
         // 指向结构体的指针
        print_book_info_with_pointer(&book1);  // 通过传book1的地址来输出book1信息
        cout << "----------------------------------------------------\n";   
        print_book_info_with_pointer(&book2);  // 通过传book2的地址来输出book2信息
    ```
### 6.typedef关键字
- 下面是一种更简单的定义结构体的方式，可以为创建的类型取一个"别名",实例如下：
    ```
        // 使用typedef创建结构体
        typedef struct Book_Info{
            char title[50];
            char author[50];
            char subject[100];
            int book_id;
        }Book_Info;
    ```
- 可以直接使用Book_Info来定义Book_Info类型的变量，而不需要使用struct关键字，如下面的实例：
    ```
        Book_Info book1_info, book2_info;
    ```
- 可以使用typedef关键字来定义非结构类型，如下面的实例：
    ```
        typedef long int *pint32;
        pint32 x, y, z;  // x,y,z都是指向长整型long int的指针
    ```
### 7.结构体知识点总结
- 结构体和C++中只有三点区别，除此之外无任何区别：
    - class中默认的成员访问权限是private的，而struct中则是public的
    - 从class继承默认是private继承的，而从struct继承默认是piblic继承的
    - class可以定义模板，而struct不可以
- C++中的结构体关键字typedef可以直接省略，甚至不省略的话，还会提示你省略；原因：C语言的 struct 定义了一组变量的集合，C编译器并不认为这是一种新的类型；C++中的struct是一个新类型的定义声明, 所以可以省略typedef, 定义变量的时候也可以省略struct, 而不用像C语言那样没使用typedef取新名字时, 就需要用"struct 结构体名"这种形式定义变量。
- 如果在结构体能够完成的目的的情况下，就没必要使用类；C与C++结构体中，前者不能有函数，后者可以有。
- .与->运算符区别：访问结构的成员时使用点运算符，而通过指针访问结构的成员时，则使用箭头运算符。也就是说，用结构体定义了一个实体，那么这个实体要引用他里面的成员，就用 . 操作符，如果用结构体定义的是一个结构指针，那么要引用他里面的成员就用->。
    ```
        struct Employee{
            char name[50];
            int age;
            char address[50];
        }emp;
    ```
- 点运算符.使用如下：
    ```
        strcpy(emp.name, "Curry_Coder");
    ```
- 如果p_emp是一个指针，指向数据类型为Employee的对象，则要把值zara赋值给对象emp的name,需要使用箭头运算符->，箭头运算符->使用如下：
    ```
        strcpy(p_emp->name, "zara");
    ```