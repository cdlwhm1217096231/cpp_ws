### 1.Cpp中的vector(可变长的动态数组)
- vector是顺序容器的一种。vector是可变长的动态数组，支持随机访问迭代器，所有STL算法都能对vector进行操作。**要使用vector，需要包含头文件vector**。在vector容器中，根据下标随机访问某个元素的时间是常数，在尾部添加一个元素的时间大多数情况下也是常数，总体来说速度很快。在中间插入或删除元素时，因为要移动多个元素，因此速度较慢，平均花费的时间和容器中的元素个数成正比。在vector容器中，用一个动态分配的数组来存放元素，因此根据下标访问某个元素的时间是固定的，与元素个数无关。
- vector容器在实现时，动态分配的存储空间一般都大于存放元素所需的空间。例如，哪怕容器中只有一个元素，也会分配32个元素的存储空间。这样做的好处是，在尾部添加一个新元素时不必重新分配空间，直接将新元素写入适当位置即可。在这种情况下，添加新元素的时间也是常数。但是，如果不断添加新元素，多出来的空间就会用完，此时再添加新元素，就不得不重新分配内存空间，把原有内容复制过去后再添加新的元素。碰到这种情况，添加新元素所花的时间就不是常数，而是和数组中的元素个数成正比。**至于在中间插入或删除元素，必然涉及元素的移动，因此时间不是固定的，而是和元素个数有关**。
### 2.vector有很多成员函数，常用的如表1所示:
 ![vector中的常用成员函数.png](https://upload-images.jianshu.io/upload_images/13407176-cad56b0942ced4e8.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)
### 3.vector的基本用法如下:
    ```
        #include "iostream"
        #include "vector"  // 使用vector需要包含此头文件

        using namespace std;

        // 函数模板
        template <typename T>
        void PrintVector(const vector<T> &v){
            // 用于输出vector容器的全部元素的函数模板
            typename vector<T>::const_iterator i;  // typename用来说明 vector <T>::const_iterator是一个类型，在 Visual Studio 中不写也可以
            for(i = v.begin(); i != v.end(); ++i)
                cout << *i << " ";
            cout << endl;
        }


        int main(){
            int a[5] = {1, 2, 3, 4, 5};
            vector<int> v(a, a+5);  // 将数组a的内容放入v
            cout << v.end() - v.begin() << endl;  // 两个随机迭代器可以相减
            PrintVector(v);
            v.insert(v.begin()+2, 13);  // 在 begin()+2 位置插人 13
            PrintVector(v);
            v.erase(v.begin()+2);   // 删除位于 begin()+2 位置的元素
            PrintVector(v);
            vector<int> v2(4, 100);   // v2有 4 个元素，都是 100
            v2.insert(v2.begin(), v.begin()+1, v.begin()+3);  // 将v的一段插入v2开头
            PrintVector(v2);
            v.erase(v.begin()+1, v.begin()+3);   // 删除 v 上的一个区间，即 [2,3)
            PrintVector(v);
            return 0;
        }
    ```
- vector还可以嵌套以形成可变长的二维数组，**下面写法中int后面的两个>之间需要有空格，否则有的编译器会把它们当作>>运算符，编译会出错**。例如:
    ```
        // vector嵌套形成二维数组
        vector<vector<int> > v3(3); // v3中有3个元素，每个元素都是vector<int>容器
        for (int i = 0; i < v3.size(); ++i)
        {
            for (int j = 0; j < 4; ++j)
                v3[i].push_back(j);
        }
        for (int i = 0; i < v3.size(); ++i)
        {
            for (int j = 0; j < v3[i].size(); ++j)
                cout << "v3[" << i << "][" << j << "] = " << v3[i][j] << " ";
            cout << endl;
        }
    ```
