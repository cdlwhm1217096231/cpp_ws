#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

/* 普通方法实现 */

class ISplitter{
public:
    virtual void split() = 0;
    virtual ~ISplitter(){}
};

class BinarySplitter: public ISplitter{
public:

};


class TxtSplitter: public ISplitter{

};

class PictureSplitter: public ISplitter{

};

class VideoSplitter: public ISplitter{

};

// 客户端程序
class MainForm: public Form{
public:
    void Button1_Click(){
       
        ISplitter* splitter  = new BinarySplitter();  // 此处违反了依赖倒置原则，左边是依赖抽象，右边却是依赖具体类！
        splitter->split();
    }
};



/*   工厂方法实现   */

// 工厂基类
class SplitterFactory{  // UML中的Creator【稳定】
public:
   virtual ISplitter* CreateSplitter() = 0;  // 工厂方法：创建对象的接口
   virtual ~SplitterFactory(){}
};

// 抽象类
class ISplitter{  // UML中的Product【稳定】
public:
    virtual void split() = 0;
    virtual ~ISplitter(){}
};


// 具体类  
class BinarySplitter: public ISplitter{  // UML中的ConcreteProduct【变化】
public:

};


class TxtSplitter: public ISplitter{

};

class PictureSplitter: public ISplitter{

};

class VideoSplitter: public ISplitter{

};


// 具体工厂
class BinarySplitterFactory: public SplitterFactory{  // UML中的ConcreteCreator【变化】
public:
    virtual ISplitter* CreateSplitter(){   // 让子类决定实例化哪个类
        return new BinarySplitter();
    }
};

class TxtSplitterFactory: public SplitterFactory{
public:
    virtual ISplitter* CreateSplitter(){
        return new TxtSplitter();
    }
};

class PictureSplitterFactory: public SplitterFactory{
public:
    virtual ISplitter* CreateSplitter(){
        return new PictureSplitter();
    }
};

class VideoSplitterFactory: public SplitterFactory{
public:
    virtual ISplitter* CreateSplitter(){
        return new VideoSplitter();
    }
};


// 客户端程序
class MainForm: public Form{
private:
    SplitterFactory* factory;  
public:
    MainForm(SplitterFactory* factory){
        this->factory = factory;
    }

    void Button1_Click(){
       
        ISplitter* splitter  = factory->CreateSplitter();  // 多态new的体现

        splitter->split();
    }
};