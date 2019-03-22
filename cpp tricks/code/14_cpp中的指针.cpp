#include "iostream"
#include "ctime"
#include "cstdlib"

using namespace std;

const int MAX = 3;

void getSeconds(unsigned long *par);
double getAverage(int *arr, int size);
int * getRandom();

int main(){
    int var1;
    int var2[10];
    cout << "变量var1的地址:" << &var1 << endl;  // 访问变量var1的在内存中的位置，使用&地址运算符，获得变量在内存中的地址
    cout << "变量var2的地址:" << &var2 << endl;
    // cpp中使用指针
    int var = 20;  // 普通变量的初始化
    int *ip;  // 指针变量的声明
    ip = &var;   // 用指针变量存储普通变量var的地址
    cout << "var的值是：" << var << endl;
    cout << "普通变量var在内存中的地址: " << &var << endl;
    cout << "指针变量ip在内存中的地址: " << &ip << endl;
    cout << "通过访问指针变量ip中存放的普通变量的地址来得到普通变量var的值: " << *ip << endl;
    // NULL空指针
    int *ptr = NULL;
    cout << "指针变量ptr在内存中的地址:: " << &ptr << endl;
    cout << "ptr的值是: " << ptr << endl;
    // 指针的算术运算
    // 递增一个指针
    int a[MAX] = {10, 100, 200};
    int *pp, *pt, *tt;
    pp = a;
    for (int i = 0; i<MAX; i++){
        cout << "变量a[" << i << "]的地址是: " << &a[i] << endl;
        cout << "变量a[" << i << "]的地址是: " << pp << endl;
        cout << "变量a[" << i << "]的值是: " << a[i]  << endl;
        cout << "通过访问指针变量pp中存放的普通变量的地址来得到数组元素的值: " << *pp << endl;
        cout << "------------------------------------------------\n";
        pp++;  // 移动到下一个位置
    }
    cout << "----------------------分隔线---------------------------\n";
    // 递减一个指针
    pt = &a[MAX - 1];
    for (int i = MAX - 1; i >= 0; i--){
        cout << "变量a[" << i << "]的地址是: " << &a[i] << endl;
        cout << "变量a[" << i << "]的地址是: " << pt << endl;
        cout << "变量a[" << i << "]的值是: " << a[i]  << endl;
        cout << "通过访问指针变量pt中存放的普通变量的地址来得到数组元素的值: " << *pt << endl;
        cout << "------------------------------------------------\n";
        pt--;  // 移动到下一个位置
    }
    cout << "----------------------分隔线---------------------------\n";
    // 指针的比较
    tt = a;
    int j = 0;
    while (tt <= &a[MAX - 1]){
        cout << "变量a[" << j << "]的地址是: " << tt << endl;
        cout << "变量a[" << j << "]的值是: " << a[j] << endl;
        tt++;
        j++;
    }
    // 指针vs数组
    /*
    for (int i = 0; i<MAX; i++){
        cout << "变量a[" << i << "]的地址是: " << &a[i] << endl;
        cout << "变量a[" << i << "]的地址是: " << pp << endl;
        cout << "变量a[" << i << "]的值是: " << a[i]  << endl;
        cout << "通过访问指针变量pp中存放的普通变量的地址来得到数组元素的值: " << *pp << endl;
        cout << "------------------------------------------------\n";
        pp++;  // 移动到下一个位置
    }
    */
    cout << "----------------------分隔线---------------------------\n";
    // 指针与数组不能完全互换
    int b[MAX] = {1, 11, 111};
    cout << "b = " << b << endl;
    cout << "*b = " << *b << endl;
    for (int i = 0; i < MAX; i++){
        *b = i;  // 改变的是数组第一个元素的值  
        // b++;   数组名是一个指针常量，不能进行修改
        *(b + 2) = 555;
    }
    cout << "----------------------分隔线---------------------------\n";
    // 指针数组
    int cc[MAX] = {6, 66, 666};
    int *pc[MAX];  // 定义一个指针数组
    for (int i = 0; i < MAX; i++){
        pc[i] = &cc[i];  // 由于pc数组中的每个元素都是指向int类型的指针，所以这里赋值为cc[i]的每个元素的地址
    }
    for (int i = 0; i < MAX; i++){
        cout << "cc[" << i << "]的地址是: " << pc[i] << endl;
        cout << "cc[" << i << "] = " << *pc[i] << endl;
    }
    // 也可以用一个指向字符的指针数组来存储一个字符串列表
    const char *names[MAX] = { 
        "Curry", 
        "Harden", 
        "Durant",
    };
    for (int i = 0; i < MAX; i++){
        cout << "names[" << i << "] = "<< names[i] << endl; // 输出字符串的值
        cout << "*names[" << i << "]的值是: " << *names[i] << endl; // 输出指针所指向的字符串的首地址的值
        cout << "names[" << i << "]的地址是: " << &names[i] << endl; // 输出指针所指向的字符串的首地址
       
    }
    // 指向指针的指针
    int val = 3000;
    int *p1 = &val;
    int **p2 = &p1;
    int ***p3 = &p2;
    cout << "val的地址是: " << &val << endl;
    cout << "指针p1的地址是: " << &p1 << endl;
    cout << "指向指针p1的指针p2的地址是: " << &p2 << endl;
    cout << "指针指针p2的指针p3的地址是: " << &p3 << endl;
    cout << "--------------------------------------------------------\n";
    cout << "指针p3中存放的是指针p2的地址: " << p3 << endl;
    cout << "指针p2中存放的是指针p1的地址: " << p2 << endl;
    cout << "指针p1中存放的是变量val的地址: " << p1 << endl;
    cout << "*p3得到的是p2的值即p1的地址: " << *p3 << endl;
    cout << "*(*p3)得到的是p1的值即a的地址: " << *(*p3) << endl;
    cout << "*(*(*p3))得到的是a的值: " << *(*(*p3)) << endl;
    // 指向指针的指针实例2
    int a4 = 100;
    int *pr;
    int **ppr;
    pr = &a4;
    ppr = &pr;
    cout << "a4 = " << a4 << endl;
    cout << "*pr = " << *pr << endl;
    cout << "**ppr = " << **ppr << endl;
    cout << "a4的地址是: " << &a4 << endl;
    cout << "指针pr的地址是: " << ppr << endl;
    cout << "指针ppr所存储的是pr的地址,根据pr的地址，找到指针pr所存储的a4的地址: " << *ppr << endl;
    // 传递指针给函数
    unsigned long sec;
    getSeconds(&sec);
    // 输出实际值
    cout << "number of seconds: " << sec << endl;
    // 能接收指针作为函数的参数，也可以接收数组作为参数
    int balance[5] = {1, 2, 3, 4, 5};
    double avg;
    // 传递一个指向数组的指针作为参数
    avg = getAverage(balance, 5);
    cout << "平均值: " << avg << endl;
    // 从函数返回一个指针
    int *ppg;
    ppg = getRandom();   // 调用子函数，从子函数中返回一个指针
    for (int i = 0; i < 10; i++)
        cout << "*(ppg + " << i << ") = " << *(ppg + i) << endl;
    // 定义一个函数指针
    int (*func)(int aa);  
    return 0;
}

void getSeconds(unsigned long *par){
    *par = time(NULL);  // 获取当前秒数
}

double getAverage(int *arr, int size){
    int i, sum = 0;
    double avg;
    for (i = 0; i < size; i++)
        sum += arr[i];
    avg = double(sum) / size;
    return avg;
}

// 要生成和返回随机数的函数
int * getRandom(){
    static int r[10];
    // 设置种子
    srand((unsigned)time(NULL));
    for (int i=0; i<10;i++){
        r[i] = rand();
        cout << "r[" << i << "]=" << r[i] << endl;
    }
    return r;
}