### 1.STL中的双向队列deque
- deque也是顺序容器的一种，同时也是一个可变长数组。要使用deque，需要包含头文件deque。所有适用于vector的操作都适用于deque。
- deque和vector有很多类似的地方。在deque中，随机存取任何元素都能在常数时间内完成（但慢于vector）。它相比于vector的优点是，vector在头部删除或添加元素的速度很慢，在尾部添加元素的性能较好，而deque在头尾增删元素都具有较好的性能（大多数情况下都能在常数时间内完成）。它有两种vector没有的成员函数：
    ```
        void push_front (const T & val);  // 将 val 插入容器的头部
        void pop_front();  //删除容器头部的元素
    ```
### 2.实例如下:
    ```
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
    ```