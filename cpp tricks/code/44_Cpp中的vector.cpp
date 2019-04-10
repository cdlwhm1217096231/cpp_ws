#include "iostream"
#include "vector" // 使用vector需要包含此头文件

using namespace std;

// 函数模板
template <typename T>
void PrintVector(const vector<T> &v)
{
    // 用于输出vector容器的全部元素的函数模板
    typename vector<T>::const_iterator i; // typename用来说明 vector <T>::const_iterator是一个类型，在 Visual Studio 中不写也可以
    for (i = v.begin(); i != v.end(); ++i)
        cout << *i << " ";
    cout << endl;
}

int main()
{
    int a[5] = {1, 2, 3, 4, 5};
    vector<int> v(a, a + 5);             // 将数组a的内容放入v
    cout << v.end() - v.begin() << endl; // 两个随机迭代器可以相减
    PrintVector(v);
    v.insert(v.begin() + 2, 13); // 在 begin()+2 位置插人 13
    PrintVector(v);
    v.erase(v.begin() + 2); // 删除位于 begin()+2 位置的元素
    PrintVector(v);
    vector<int> v2(4, 100);                              // v2有 4 个元素，都是 100
    v2.insert(v2.begin(), v.begin() + 1, v.begin() + 3); // 将v的一段插入v2开头
    PrintVector(v2);
    v.erase(v.begin() + 1, v.begin() + 3); // 删除 v 上的一个区间，即 [2,3)
    PrintVector(v);
    cout << "----------------------------------------------------------\n";
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
    return 0;
}