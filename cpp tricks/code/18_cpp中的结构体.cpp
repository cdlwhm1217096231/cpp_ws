#include "iostream"
#include "cstring"  // C语言的字符串库

using namespace std;


void print_book_info(struct Books book);
void print_book_info_with_pointer(struct Books *book_pointer);

// 声明一个结构体类型
struct Books{  // Books是结构体类型名
    char title[50];
    char author[50];
    char subject[100];
    int book_id;
}; 

// 使用typedef创建结构体
typedef struct Book_Info{
    char title[50];
    char author[50];
    char subject[100];
    int book_id;
}Book_Info;


int main(){
    // 访问结构体的成员
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
    cout << "----------------------------------------------------\n";   
    // 结构体作为函数参数
    print_book_info(book1);
    cout << "----------------------------------------------------\n";   
    print_book_info(book2);
    cout << "----------------------------------------------------\n";   
    // 指向结构体的指针
    print_book_info_with_pointer(&book1);  // 通过传book1的地址来输出book1信息
    cout << "----------------------------------------------------\n";   
    print_book_info_with_pointer(&book2);  // 通过传book2的地址来输出book2信息
    // 使用typedef创建结构体
    Book_Info book1_info, book2_info;
    return 0;
}

// 结构体作为函数参数
void print_book_info(struct Books book){
    cout << "书的标题: " << book.title << endl; 
    cout << "书的作者: " << book.author << endl;
    cout << "书的类别: " << book.subject << endl;
    cout << "书的id: " << book.book_id << endl;
}
// 指向结构体的指针,下面的函数以结构体指针作为函数形参
void print_book_info_with_pointer(struct Books *book_pointer){
    cout << "书的标题: " << book_pointer->title << endl; 
    cout << "书的作者: " << book_pointer->author << endl;
    cout << "书的类别: " << book_pointer->subject << endl;
    cout << "书的id: " << book_pointer->book_id << endl;
}
