#include "iostream"

using namespace std;


inline int Max(int a, int b){
    return (a > b)? a:b;
}

int main(){
    cout << "Max(20, 10): " << Max(20, 10) << endl;
    cout << "Max(0, 100): " << Max(0, 100) << endl;
    cout << "Max(100, 1010): " << Max(100, 1010) << endl;
    return 0;
}
