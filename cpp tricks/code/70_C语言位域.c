#include <stdio.h>

int main(){
    struct bs{
        unsigned m:12;
        int : 20;
        unsigned n: 4;
    };
    printf("%d\n", sizeof(struct bs));
    return 0;
}