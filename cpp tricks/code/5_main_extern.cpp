#include "iostream"

using namespace std;



int count;

extern void write_extern();

int main(){
    count = 5;
    write_extern();
    return 0;
}

