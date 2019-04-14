#include "stdio.h"
#include "stdlib.h"
#include "conio.h"   // getche()需要包含的头文件

int main(){

    // getchar()
    char c;
    c = getchar();
    printf("c=%c\n", c);
    // getche()
    char cc = getche();
    printf("cc=%c\n", cc);
    // getch()
    char ccc = getche();
    printf("ccc=%c\n", ccc);
    // gets()
    char author[30], lang[30], url[30];
    gets(author);
    printf("author: %s\n", author);
    gets(lang);
    printf("lang: %s\n", lang);
    gets(url);
    printf("url: %s\n", url);
    return 0;
}