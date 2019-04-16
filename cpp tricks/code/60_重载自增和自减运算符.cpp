#include "iostream"
#include "iomanip"

using namespace std;

// 秒表类
class times{
    public:
        times():m_min(0), m_sec(0){};
    public:
        void set_zero(){m_min = 0; m_sec = 0;}
        times run();  // 运行
        times operator++();  // 前置++
        times operator++(int n);  // 后置++,在这个函数中参数n是没有任何意义的，它的存在只是为了区分是前置形式还是后置形式
        friend ostream & operator<< (ostream &out, const times &t);
    private:
        int m_min;
        int m_sec;
};

times times::run(){
    ++m_sec;
    if(m_sec == 60){
        m_min++;
        m_sec = 0;
    }
    return *this; 
}

times times::operator++(){
    return run();
}

times times::operator++(int n){
    times t = *this;
    run();
    return t;  // 对象本身
}

ostream & operator<< (ostream &out, const times &t){
    out << setfill('0') << setw(2) << t.m_min << ":" << setw(2) << t.m_sec;
    return out;
}




int main(){
    times t1, t2;
    t1 = t2++;

    cout << "t1: "<< t1 <<endl;
    cout << "t2: "<< t2 <<endl;
    t1.set_zero();
    t2.set_zero();
    t1 = ++t2;
    cout << "t1: "<< t1 <<endl;
    cout << "t2: "<< t2 <<endl;

    return 0;
}