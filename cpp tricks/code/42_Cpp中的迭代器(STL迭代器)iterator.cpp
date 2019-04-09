#include "iostream"
#include "vector"
#include "list"
#include "algorithm"  // 要使用操作迭代器的函数模板，需要包含此文件!!

using namespace std;



int main(){
    // 迭代器用法实例
    vector<int> v;  // v中存放int类型变量的可变长的数组，开始时没有元素
    for(int n=0; n < 5; n++)
        v.push_back(n);  // push_back()成员函数在vector容器尾部添加一个元素
    vector<int>::iterator i;  // 定义正向迭代器
    cout << "正向迭代器遍历容器: ";
    for(i = v.begin(); i!=v.end();++i){  // 用正向迭代器从前往后遍历容器,使用前置++,不使用后置++,因为这将会降低运算时间，原因是++运算符的重载！后置++会多生成一个局部对象temp!
        cout << *i << " ";   // *n就是迭代器n指向的元素
        *i *= 2;   // 每个元素变为原来的2倍
    }
    cout << endl;
    // 用反向迭代器遍历容器
    cout << "反向迭代器遍历容器: ";
    vector<int>::reverse_iterator j;
    for(j=v.rbegin(); j != v.rend();++j)   // 用反向迭代器从后往前遍历容器,使用前置++,不使用后置++,因为这将会降低运算时间，原因是++运算符的重载！后置++会多生成一个局部对象temp!
        cout << *j << " ";
    cout << "-------------------------------------\n";
    // 迭代器的功能分类
    vector<int> v1(10);   // v1初始化成有10个元素
    for(int i = 0; i < v.size(); ++i)  // size()返回元素的个数
        cout << "v1[" << i << "] = " << v1[i] << " ";
    cout << endl;
    vector<int>::iterator i1;
    for(i1 = v1.begin(); i1 != v1.end(); ++i1)  // 用 != 比较两个迭代器
        cout << *i1;
    cout << endl;
    for(i1 = v1.begin(); i1 < v1.end(); ++i1)  // 用 < 比较两个迭代器
        cout << *i1;
    cout << endl;
    i1 = v.begin();
    while(i1 < v.end()){  // 间隔一个输出
        cout << *i1;
        i1 += 2;   // 随机访问迭代器支持 "+= 整数"  的操作
    }
    cout << endl;
    cout << "-------------------------------------\n";
    // 迭代器的辅助函数
    int a[5] = {6, 66, 666, 6666, 0};
    list<int> lst(a, a+5);
    list<int>::iterator p = lst.begin();  // 迭代器p，类似于一个指针
    advance(p, 2);    // p向后移动两个元素，指向666
    cout << *p << endl;  // 输出666
    advance(p, -1);  // p向前移动一个元素，指向66
    cout << *p << endl;  // 输出66
    list<int>::iterator q = lst.end();
    q--;  // q指向5
    cout << distance(p, q) << endl;  // 输出3
    iter_swap(p, q);  // 序号从1开始，交换2号和5号元素
    for(p = lst.begin(); p != lst.end(); ++p)
        cout << *p << " ";
    return 0;
}
