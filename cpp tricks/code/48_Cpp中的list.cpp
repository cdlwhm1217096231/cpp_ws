#include "iostream"   // 使用 list 需要包含此头文件
#include "list"
#include "algorithm"  // 使用STL中的算法需要包含此头文件

using namespace std;

class A{
    private:
        int n;
    public:
        A(int n_){
            n = n_;
        }
        friend bool operator < (const A &a1, const A &a2);
        friend bool operator == (const A &a1, const A &a2);
        friend ostream & operator << (ostream & o, const A &a);
};

// 重载运算符函数的定义
bool operator < (const A &a1, const A &a2){
    return a1.n < a2.n ;
}

bool operator == (const A &a1, const A &a2){
    return a1.n == a2.n;
}

ostream & operator << (ostream & o, const A &a){
    o << a.n;
    return o;
}

// 函数模板
template<typename T>
void printFun(T first, T last){
    for(;first != last; ++first)
        cout << *first << " ";
    cout << endl;
}


int main(){
    A a[5] = {1, 3, 2, 4, 2};
    A b[7] = {10, 30, 20, 30, 30, 40, 40};
    list<A> lst1(a, a+5), lst2(b, b+7);
    lst1.sort();
    printFun(lst1.begin(), lst1.end());
    lst1.remove(2); // 删除所有和A(2)相等的元素
    printFun(lst1.begin(), lst1.end());
    lst2.pop_front();  // 删除第一个元素
    printFun(lst2.begin(), lst2.end());
    lst2.unique();  // 删除所有和前一个元素相等的元素
    printFun(lst2.begin(), lst2.end());
    lst2.sort();
    lst1.merge(lst2);  // lst2合并到lst1,并清空lst2
    printFun(lst1.begin(), lst1.end());
    printFun(lst2.begin(), lst2.end());
    lst1.reverse();   // 翻转lst1
    printFun(lst1.begin(), lst1.end());
    lst2.insert(lst2.begin(), a+1, a+4);  // 在lst2中插入3， 2， 4
    printFun(lst2.begin(), lst2.end())
    list<A>::iterator p1, p2, p3;
    p1 = find(lst1.begin(), lst1.end(), 30);  
    p2 = find(lst2.begin(), lst2.end(), 2);
    p3 = find(lst2.begin(), lst2.end(), 4);
    lst1.splice(p1, lst2, p2, p3); // 将[p2, p3)插入p1之前，并从lst2中删除[p2,p3)
    printFun(lst1.begin(), lst1.end());
    printFun(lst2.begin(), lst2.end());
    return 0;
}