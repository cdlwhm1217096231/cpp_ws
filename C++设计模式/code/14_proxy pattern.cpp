#include <iostream>

using namespace std;


/* 普通方法 */
class ISubject{
public:
    virtual void process();
};

class RealSubject: public ISubject{
public:
    virtual void process(){
        // ...
    }
};


class ClientApp{
private:
    ISubject* subject;
public:
    ClientApp(){
        subject = new RealSubject();
    }
    void doTask(){
        // ...
        subject->process();
    }
};


/* 代理模式 */
class ISubject{
public:
    virtual void process();
};

// Proxy的设计
class SubjectProxy: public ISubject{
public:
    virtual void process(){
        // 对RealSubject的一种间接访问
        // ....
    }
};


class ClientApp{
private:
    ISubject* subject;
public:
    ClientApp(){
        subject = new SubjectProxy();  // SubjectProxy实际上是RealSubject的代理
    }
    void doTask(){
        // ...
        subject->process();
    }
};