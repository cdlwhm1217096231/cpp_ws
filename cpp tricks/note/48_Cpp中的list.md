### 1.Cpp中的list双向链表
- list是顺序容器的一种，list是一个双向链表。**使用list需要包含头文件list**。双向链表的每个元素中都有一个指针指向后一个元素，也有一个指针指向前一个元素，如图1所示。
![双向链表.png](https://upload-images.jianshu.io/upload_images/13407176-ae03f4b1b8cc3550.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)
- 在list容器中，在已经定位到要增删元素的位置的情况下，增删元素能在常数时间内完成。如图2所示，在ai和ai+1之间插入一个元素，只需要修改ai和ai+1中的指针即可。
![插入操作.png](https://upload-images.jianshu.io/upload_images/13407176-644c24f6ed295031.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)
- list容器不支持根据下标随机存取元素,因为其不是顺序存储结构。list的构造函数和许多成员函数的用法都与vector类似，此处不再列举。除了顺序容器都有的成员函数外，list容器还独有如表1所示的成员函数（此表不包含全部成员函数，且有些函数的参数较为复杂，表中只列出函数名）。
![list中的成员函数.png](https://upload-images.jianshu.io/upload_images/13407176-f512a356f2564b9c.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)
- STL中的算法sort可以用来对vector和deque排序，它需要随机访问迭代器的支持。因为list不支持随机访问迭代器，所以不能用算法sort对list容器排序。因此，list容器引入了sort成员函数以完成排序。list的示例程序如下:
    ```
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
            printFun(lst2.begin(), lst2.end());
            list<A>::iterator p1, p2, p3;
            p1 = find(lst1.begin(), lst1.end(), 30);  
            p2 = find(lst2.begin(), lst2.end(), 2);
            p3 = find(lst2.begin(), lst2.end(), 4);
            lst1.splice(p1, lst2, p2, p3); // 将[p2, p3)插入p1之前，并从lst2中删除[p2,p3)
            printFun(lst1.begin(), lst1.end());
            printFun(lst2.begin(), lst2.end());
            return 0;
        }
    ```