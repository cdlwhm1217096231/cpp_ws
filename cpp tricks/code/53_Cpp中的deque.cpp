#include "iostream"
#include "deque"

using namespace std;

/*双向队列deque:比queue的优势在于队头和队尾都可以进行删除和插入操作*/


int main(){
    deque<int> d;
    for(int i = 0; i < 100; i++)
        d.push_back(i);
    cout << "size1 = " << d.size() << endl;
    d.push_front(-1); // 将val插入容器的头部
    cout << "d[0]=" << d.at(0) << ",size2 = " << d.size() << endl;
    d.pop_front();  // 删除容器头部的元素
    cout << "d[0]=" << d.at(0) << ",size3 = " << d.size() << endl;
    d.resize(0);
    cout << "d.empty() = " << d.empty() << endl;

    return 0;
}