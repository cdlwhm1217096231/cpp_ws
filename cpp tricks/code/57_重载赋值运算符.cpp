#include "iostream"
#include "cstdlib"
#include "cstring"

using namespace std;



class Array{
    public:
        Array(int len);
        Array(const Array &arr);   // 拷贝构造函数
        ~Array();
    public:
        int operator[](int i) const {return m_p[i];}  // 以常成员函数(只读)形式重载[]运算符
        int & operator[](int i) {return m_p[i];}  // 获取元素(写入)
        Array & operator=(const Array &arr);  // 重载赋值运算符！！！operator=()的形参类型是const Array &,这样不但能够避免在传参时调用拷贝构造函数，还能够同时接收const类型和非const类型的实参
        int length() const {return m_len;}
        void show();
    private:
        int m_len;
        int *m_p;
};
// 构造函数的定义
Array::Array(int len):m_len(len){
    m_p = (int *)calloc(len, sizeof(int));  // 动态分配内存空间，使得指针m_p指向新分配的内存空间
}
// 拷贝构造函数的定义
Array::Array(const Array &arr){
    this->m_len = arr.m_len;
    this->m_p = (int *)calloc(this->m_len, sizeof(int));
    memcpy( this->m_p, arr.m_p, m_len * sizeof(int));
}

Array::~Array(){
    free(m_p);
}
// 重载赋值运算符
Array & Array::operator=(const Array &arr){ // operator=()的返回值类型是Array &,这样不但能够避免在返回数据时调用拷贝构造函数，还能够达到连续赋值的目的
    if(this != &arr){  // 判断是否是给同一个对象赋值
        this->m_len = arr.m_len;
        free(this->m_p);
        this->m_p = (int*)calloc(this->m_len, sizeof(int));
        memcpy(this->m_p, arr.m_p, m_len * sizeof(int));
    }
    return *this;  // 表示返回当前对象
}

// 普通成员函数的定义
void Array::show(){
    cout << "我是普通成员函数....\n";
}

// 打印数组元素
void printArray(const Array &arr){
    int len = arr.length();
    for(int i=0; i<len; i++){
        if(i == len-1){
            cout<<arr[i]<<endl;
        }else{
            cout<<arr[i]<<", ";
        }
    }
}
int main(){
    Array arr1(10);
    for(int i=0; i<10; i++){
        arr1[i] = i;
    }
    cout << "arr1:";
    printArray(arr1);
   
    Array arr2(5);
    for(int i=0; i<5; i++){
        arr2[i] = i;
    }
    cout << "arr2:";
    printArray(arr2);
    cout << "------------------------------------\n";
    arr2 = arr1;  // 调用operator=()
    cout << "将arr1赋值给arr2:";
    printArray(arr2);
    arr2[3] = 234;  // 修改arr2的数据不会影响arr1,如果把operator=()注释掉,修改arr2的值就会影响arr1的值
    arr2[7] = 920;
    cout << "修改arr2的值不会影响arr1:";
    printArray(arr1);
    return 0;
}