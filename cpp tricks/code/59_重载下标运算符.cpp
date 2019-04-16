#include "iostream"

using namespace std;



class Array{
    public:
        Array(int len=0);
        ~Array();
    public:
        int & operator[] (int i);
        const int & operator[] (int i) const;
    public:
        int length() const{return m_len;}
        void show() const;
    private:
        int m_len;  // 数组长度
        int *m_p;  // 指向数组内存的指针m_p
};

// 构造函数定义 
Array::Array(int len):m_len(len){
    if(len == 0)
        m_p = NULL;
    else
        m_p = new int[len];
}

Array::~Array(){
    delete[] m_p;
}
// 重载[]运算符
int & Array::operator[] (int i){
    return m_p[i];
}

const int & Array::operator[] (int i) const{
    return m_p[i];
}

void Array::show() const{
    for(int i = 0; i < m_len; i++){
        if(i == m_len - 1)
            cout << m_p[i] << endl;
        else    
            cout << m_p[i] << " ";
    }
}

int main(){
    int n;
    cin >> n;
    Array A(n);

    for(int i = 0; i < A.length(); i++)
        A[i] = i * 5;
    A.show();

    const Array B(n);
    cout << B[n-1] << endl;  // 访问最后一个元素
    return 0;
}