#include "iostream"

using namespace std;

void bubleSort(int * a, int n);


int main(){
    int ix;
    int a[] = {8, 34, 3, 13, 1, 21, 5, 2};
    int a_length = (sizeof(a)) / (sizeof(a[0]));   // 获得数组的长度s
    cout << "冒泡排序前:";
    for (int ix = 0; ix < a_length; ix++)
        cout << a[ix] << " ";
    cout << endl;

    bubleSort(a, a_length);

    cout << "冒泡排序后:";
    for (int ix = 0; ix < a_length; ix++)
        cout << a[ix] << " ";
    cout << endl;

    return 0;
}

void bubleSort(int * a, int n){   // int * a;定义一个数组指针，方便从主函数传入一个变化长度的数组
    int ix, jx, temp;
    for (int ix=0; ix < n; ix++){
        for (jx=ix+1; jx < n; jx++){
            if (a[jx] < a[ix]){
                temp = a[jx];
                a[jx] = a[ix];
                a[ix] = temp;
            }
        }
    }
}