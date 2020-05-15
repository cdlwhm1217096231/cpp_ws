#include <iostream>

using namespace std;


/*  普通方法  */

class Element {
public:
    virtual void Func1() = 0;

    // 新增行为
    virtual void Func2(int data) = 0;

    virtual ~Element(){}
};

class ElementA: public Element {
public:
    void Func1() {
        // ....
    }

    void Func2(int data) {
        // ....
    }
};

class ElementB: public Element {
public:
    void Func1() {
        // ***
    }

    void Func2(int data){
        // ***
    }
};


/*  访问器模式  */
class Visitor{
public:
    virtual void visitElementA(ElementA& element) = 0;
    virtual void visitElementB(ElementB& element) = 0;
    virtual ~Visitor() {}
};


class Element {
public:
    virtual void accept(Visitor& visitor) = 0;  // 第一次动态辨析
    virtual ~Element(){}
};

class ElementA: public Element {
public:
    void accept(Visitor& visitor){
        visitor.visitElementA(*this);
    }

};

class ElementB: public Element {
public:
    void accept(Visitor& visitor){
        visitor.visitElementB(*this);  // 第二次动态辨析
    }
};

// -------------------------上面的代码是稳定的，下面的代码是变化的---------------------------------

// 新增行为
class Visitor1: public Visitor {
public:
    void visitElementA(ElementA& element) {
        cout << "Visitor1 is processing ElementA" << endl;
    }

    void visitorElementB(ElementB& element) {
        cout << "Visitor1 is processing ElementB" << endl;
    }
};


class Visitor2: public Visitor {
public:
    void visitElementA(ElementA& element) {
        cout << "Visitor2 is processing ElementA" << endl;
    }

    void visitorElementB(ElementB& element) {
        cout << "Visitor2 is processing ElementB" << endl;
    }
};


int main() {
    Visitor2 visitor2;
    ElementB elementB;
    elementB.accept(visitor2);  // 二次多态辨析double dispatch

    ElementA elementA;
    elementA.accept(visitor2);

    return 0;
}