#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 冒泡排序思路
/*
1. 比较相邻的元素。如果第一个比第二个大，就交换他们两个。
2. 对每一对相邻元素作同样的工作，从开始第一对到结尾的最后一对。这步做完后，最后的元素会是最大的数。
3. 针对所有的元素重复以上的步骤，除了最后一个。
4. 持续每次对越来越少的元素重复上面的步骤，直到没有任何一对数字需要比较。
*/

// 基础版本
void BubbleSort(vector<int>& v){
    int len = v.size();
    for(int i=0; i < len-1; ++i){
        for(int j=0; j < len-1-i; ++j){
            if(v[j] > v[j+1]){
                swap(v[j], v[j+1]);
            }
        }
    }
}

// 模板实现冒泡排序
template<typename T>  // 模板头
void bubble_sort(T arr[], int len){  // 函数头
    for(int i=0; i < len-1; ++i){
        for(int j=0; j < len-1-i; ++j){
            if(arr[j] > arr[j+1]){
                swap(arr[j], arr[j+1]);
            }
        }
    }
}

// 冒泡排序的改进版(减少不必要的交换，只在发生顺序不对时，交换)
void BubbleSortOrderly(vector<int>& v){
    int len = v.size();
    bool orderly = false;
    for(int i=0; i < len-1 && !orderly; ++i){
        orderly = true;
        for(int j=0; j < len - 1- i; ++j){
            if(v[j] > v[j+1]){
                orderly = false;
                swap(v[j], v[j+1]);
            }
        }
    }
}