#include <iostream>
#include <thread> 
#include <mutex> 

using namespace std;


/*  单例模式  */
class Singleton{
private:
    Singleton();
    Singleton(const Singleton& other);
public:
    static Singleton* getInstance();
    static Singleton* m_instance;
};

Singleton* Singleton::m_instance = nullptr;

// 线程非安全版本---适用于单线程
Singleton* Singleton::getInstance(){
    if (m_instance == nullptr){
        m_instance = new Singleton();
    }
    return m_instance;
}


// 线程安全版本，但锁的代价过高----适用于多线程
Singleton* Singleton::getInstance(){
    Lock lock;
    if(m_instance == nullptr){
        m_instance = new Singleton();
    }
    return m_instance;
}


// 双检查锁，但由于内存读写reorder不安全
Singleton* Singleton::getInstance(){
    if(m_instance == nullptr){
        Lock lock;
        if(m_instance == nullptr){
            m_instance = new Singleton();
        }
    }
    return m_instance;
}


// c++11版本之后的跨平台实现(volatile)
atomic<Singleton*> Singleton::m_instance;
mutex Singleton::m_mutex;

Singleton* Singleton::getInstance(){
    Singleton* tmp = m_instance.load(memory_order_relaxed);
    atomic_thread_fence(memory_order_acquire);  // 获取内存fence
    if (tmp == nullptr){
        lock_guard<mutex> lock(m_mutex);
        tmp = m_instance.load(memory_order_relaxed);
        if(tmp == nullptr){
            tmp = new Singleton();
            atomic_thread_fence(memory_order_release);  // 释放内存fence
            m_instance.store(tmp, memory_order_relaxed);
        }
    }
    return tmp;
}

