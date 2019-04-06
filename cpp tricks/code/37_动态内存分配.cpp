#include "iostream"
#include "malloc.h"


using namespace std;


// 对象的动态内存分配
class Box{
    public:
        Box(){
            cout << "调用构造函数\n";
        }
        ~Box(){
            cout << "调用析构函数\n";
        }
};
// new和malloc的区别
class TEST{
    private:
        int num1;
        int num2;
    public:
        TEST(){
            num1 = 10;
            num2 = 20;
        }
        void Print(){
            cout << num1 << " " << num2 << endl;
        }
};



int main(){
    double *ptr = NULL;   // 初始化为null的指针
    ptr = new double;   // 为变量请求内存

    *ptr = 3.14;   // 在分配的地址存储值
    cout << "*ptr = " << *ptr << endl;
    delete ptr;   // 释放内存
    cout << "-------------------------------\n";
    // 二维数组
    int **p;
    int i, j;  // p[4][8]
    // 开始分配4行8列的二维数组数据
    p = new int *[4];
    for(i = 0; i < 4; i++)
        p[i] = new int [8];
    
    for(i = 0; i < 4; i++){
        for(j = 0; j < 8; j++)
            p[i][j] = j * i;
    }
    // 打印数据
    for(i = 0; i < 4; i++){
        for(j = 0; j < 8; j++){
            if(j == 0)
                cout << endl;
            cout << p[i][j] << "\t";
        }
    }
    cout << endl;
    // 开始释放申请的堆
    for(i = 0; i < 4; i++)
        delete [] p[i];
    delete p;
    cout << "-------------------------------\n";
    // 三维数组
    int i1, j1, k1; //p[2][3][4]
    int ***pt;
    pt = new int **[2];
    for(i1 =0; i1 < 2; i1++){
        pt[i1] = new int *[3];
        for(j1 = 0;j1<3;j1++)
            pt[i1][j1] = new int[4];
    } 
    // 输出pt[i][j][k]三维数据
    for(i1 = 0;i1 <2;i1++){
        for(j1=0;j1 <3;j1++){
            for(k1=0; k1 < 4; k1++){
                pt[i1][j1][k1] = i1 + j1 + k1;
                cout << pt[i1][j1][k1] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
    // 释放内存
    for(i1 = 0; i1 < 2; i1++){
        for(j1 = 0; j1 < 3; j1++)
            delete [] pt[i1][j1];
    }

    for(i1 = 0; i1 < 2; i1++)
        delete [] pt[i1];

    delete [] pt;
    cout << "-------------------------------\n";
    Box *boxarray = new Box[4];
    delete [] boxarray;  // 删除数组
    cout << "-------------------------------\n";
    /*
    用malloc()函数在堆区分配一块内存空间，然后对该块内存空间进行强制类型(TEST*)转换
    解释为是一个TEST类对象，这不会调用TEST的默认构造函数
    */
   TEST *t_obj1 = (TEST *)malloc(sizeof(TEST));
   t_obj1->Print();
   // 用new在堆区创建一个TEST类的对象，这会调用TEST类的默认构造函数
   TEST *t_obj2 = new TEST;
   t_obj2->Print();
    return 0;
}