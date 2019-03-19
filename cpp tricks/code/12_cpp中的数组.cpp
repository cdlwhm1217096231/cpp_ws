#include "iostream"
#include "iomanip"
#include "cstdlib"
#include "ctime"
#include "vector"


using namespace std;
using std::setw;   //  setw() 函数来格式化输出

const int MAX = 3;


double getAverage(int arr[], int size);
double getAverage1(int *arr, int size);
int * getRandom();


int main(){
    int a[10];   // 声明一个包含10个元素的整型数组
    // 初始化数组
    for (int i = 0; i < 10; i++)
        a[i] = i + 100;
    cout << "元素索引" << setw(13) << "元素值" << endl;
    // 输出数组中的每个元素
    for (int j = 0; j < 10; j++)
        cout << setw(7) << j << setw(13) << a[j] << endl;
    /*与数组相关概念*/
    // 1.二维数组
    int aa[5][2] = {{0, 0}, {1, 2}, {2, 4}, {5, 7}, {9, 10}};
    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 2; j++){
            cout << "aa[" << i << "][" << j << "] = " << aa[i][j] << endl;
        }
    }
    // 2.指向数组的指针：数组指针
    double b[5] = {12.4, 3.1, 5.6, 0.8, 5.4};
    double *p;  // 一个指向double型的指针,可以存储一个double类型变量的地址
    p = b;
    cout << "使用指针的数组值 " << endl;
    for (int i = 0; i < 5; i++)
        cout << "*(p + " << i << ") = " << *(p + i) << endl;
    cout << "使用b作为地址的数组值 " << endl;
    for (int i = 0; i < 5; i++)
        cout << "*(b + " << i << ") = " << *(b + i) << endl; 
    // C++中，将char*或char[]传递给cout进行输出，结果会是整个字符串。如果想要获得字符串的地址，强制转化为其他指针（非char*）
    char var[MAX] = {'a', 'b', 'c'};
    char *ptr;
    ptr = var;
    for (int i = 0; i < 3; i++){
        cout << "var[" << i << "]的地址是 = " << (int *)ptr << endl;
        cout << "var[" << i << "] = " << *ptr << endl;
        ptr++;  // 移动到下一个位置
    }
    // 3.C++中把数组传递给函数(方法1)
    int bb[5] = {1000, 2, 3, 17, 50};
    double avg, avg1;
    // 传递一个指向数组的指针作为参数
    avg = getAverage(bb, 5);
    cout << "平均值: " << avg << endl;
    /*-----------------------方法2-----------------------*/
    int bbb[5] = {1000, 2, 3, 17, 50};
    int *ptr1 = bbb;
    // 分别计算数组元素个数，以及整型指针的字节数
    size_t bbb_size = sizeof(bbb) / sizeof(int);
    size_t ptr1_size = sizeof(ptr1);
    cout << "bbb size = " << bbb_size << endl;
    cout << "ptr1 size = " << ptr1_size << endl;
    avg1 = getAverage1(bbb, 5);
    cout << "平均值: " << avg1 << endl;
    // 4.从函数返回数组----指针函数
    int *p1; 
    p1 = getRandom();
    for (int i = 0; i < 10; i++)
        cout << "*( p1 + " << i << ") = " << *(p1 + i) << endl;
    // 细节知识
    char a1[] = {'p', 'y', 't', 'h', 'o', 'n'};  // 初始化，没有 null
    char a2[] = {'p', 'y', 't', 'h', 'o', 'n', '\0'};   // 初始化，明确有 null
    char a3[] = "python";  // null 终止符自动添加
    // const char a4[6] = "python";  // 报错，没有 null 的位置,正确的是const char a4[7] = "python"
    // 数组的大小是固定的，不能额外增加元素，当想定义不固定大小的字符时，使用vector！
    vector<int> vec;  // 创建向量用于存储整型数据
    int m;
    // 显示vec初始大小
    cout << "vector size = " << vec.size() << endl;
    // 向向量vec追加5个整数值
    for(int m = 0; m < 5; m++)
        vec.push_back(m);
    // 显示追加后vec的大小
    cout << "追加后的vector size = " << vec.size() << endl;
    cout << setfill('*') << setw(5) << 'a' << endl;
    return 0;
}

// 方法1(下面的例子中把数组作为参数，同时还传递了另一个参数)
double getAverage(int arr[], int size){
    int i, sum = 0;
    double avg;
    cout << "sizeof(arr) = " << sizeof(arr) << endl;
    for (i = 0; i < size; i++)
        sum += arr[i];
    avg = double(sum) / size;
    return avg;
}

// 方法2
double getAverage1(int *arr, int size){
    int i, sum = 0;
    double avg;
    cout << "inside sizeof(arr) = " << sizeof(arr) << endl;
    for (i = 0; i < size; i++)
        sum += arr[i];
    avg = double(sum) / size;
    return avg;
}

// 要生成和返回随机数的函数
int * getRandom(){
    static int r[10];  // C++不支持在函数外返回局部变量的地址，除非定义局部变量为static变量
    // 设置随机数种子
    srand((unsigned)time(NULL));
    for (int i = 0; i < 10; i++){
        r[i] = rand();
        cout << "r[" << i << "] = " << r[i] << endl;
    }
    return r;
}