#include "iostream"

using namespace std;


struct student_info{
    char name;
    int age;
    int number;
    char add;
};

struct myStruct{
    char a;
    double b;
    int c;
};

int main(){
    cout << "sizeof(student_info): " << sizeof(student_info) << endl;
    cout << "sizeof(myStruct): " << sizeof(myStruct) << endl;
    return 0;
}
