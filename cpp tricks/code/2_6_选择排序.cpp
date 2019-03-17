#include "iostream"

using namespace std;

void printSequence(int a[], int size);
void selectSort(int a[], int size);

/*        选择排序      */
int main(){
    const int SIZE = 7;
    int a[SIZE] = {5, 7, 2, 8, 9, 1, 4};
    cout << "选择排序前: ";
    printSequence(a, SIZE);

    selectSort(a, SIZE);

    cout << "选择排序后: ";
    printSequence(a, SIZE);
    return 0;
}


void printSequence(int a[], int size){
    for (int i = 0; i <= size - 1; i++){
        cout << a[i] << " ";
    }
    cout << endl;
}

// 选择排序
void selectSort(int a[], int size){
    int minIndex, temp;
    for (int ix = 0; ix < size - 1; ix++){  // 通过外层for循环对索引进行遍历，保存最小元素所对应的索引
        minIndex = ix; // 外层for循环开始循环时，将minIndex初始化为数组第一个元素的索引
        for (int jx = ix + 1; jx < size; jx++){ // 通过内层for循环找出最小元素，并把最小元素所对应的索引赋值给minIndex
            if (a[jx] < a[minIndex])
                minIndex = jx;
        }
        temp = a[ix];
        a[ix] = a[minIndex];
        a[minIndex] = temp;
    }
}