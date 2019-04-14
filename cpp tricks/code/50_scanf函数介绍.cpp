#include "iostream"
#include "cstdio"
#include "cstdlib"


using namespace std;



int main(){
    // scanf函数介绍
    int a = 0, b = 0, c = 0, d=0;
    scanf("%d", &a);
    scanf("%d", &b);

    printf("a+b = %d\n", a+b);

    scanf("%d", &c);
    scanf("%d", &d);
    printf("c*d = %d\n", c*d);
    // 查看变量的地址
    int a1 = 'E';
    int b1 = 23;
    int c1 = 45;
    printf("&a1 = %p, &b1 = %p, &c1 = %p\n", a1, b1, c1);  // %p是以十六进制的格式输出
    // scanf函数的实例2
    int a_, b_, c_;
    scanf("%d %d", &a_, &b_);
    printf("a_+b_=%d\n", a_+b_);

    scanf("%d   %d", &a_, &b_);
    printf("a_+b_=%d\n", a_+b_);

    scanf("%d, %d, %d", &a_, &b_, &c_);
    printf("a_+b_+c_=%d\n", a_+b_+c_);

    scanf("%d is bigger than %d", &a_, &b_);
    printf("a_-b_=%d\n", a_- b_);
    // scanf函数实例3
    int a2 = 2, b2 = 3,c2 = 4, d2 = 5;  // 给变量赋予不同的初始值
    scanf("%d", &a2);
    scanf("%d", &b2);
    printf("a2=%d,b2=%d\n", a2, b2);

    scanf("%d", &c2);
    scanf("%d", &d2);
    printf("c2=%d, d2=%d\n", c2, d2);
    // scanf函数实例4
    int a1_ = 111, b1_=222;
    scanf("a1_=%d", &a1_);
    scanf("b1_=%d", &b1_);
    printf("a1_=%d, b1_=%d\n", a1_, b1_);
    // scanf函数实例5
    char name;
    int age;
    char url[30];
    float price;
    scanf("%c", &name);
    scanf("%d", &age);
    scanf("%s", url);  // 可以加&也可以不加&
    scanf("%f", &price);
    printf("26个英文字母的最后一个是%c\n", name);
    printf("博客已经写了%d月,网址是%s,赞赏是%f", age, url, price);
    // scanf函数实例6
    char author[30], lang[30], urls[30];
    scanf("%s %s", author, lang);
    printf("author:%s\nlang:%s\n", author, lang);
    scanf("%s", urls);
    printf("urls:%s\n", urls);
    return 0;
}