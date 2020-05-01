#include <iostream>

using namespace std;

/*   工厂方法实现   */

// 工厂基类
class SplitterFactory
{ // UML中的Creator【稳定】
public:
    virtual ISplitter *CreateSplitter() = 0; // 工厂方法：创建对象的接口
    virtual ~SplitterFactory() {}
};

// 抽象类
class ISplitter
{ // UML中的Product【稳定】
public:
    virtual void split() = 0;
    virtual ~ISplitter() {}
};

// 具体类
class BinarySplitter : public ISplitter
{ // UML中的ConcreteProduct【变化】
public:
};

class TxtSplitter : public ISplitter
{
};

class PictureSplitter : public ISplitter
{
};

class VideoSplitter : public ISplitter
{
};

// 具体工厂
class BinarySplitterFactory : public SplitterFactory
{ // UML中的ConcreteCreator【变化】
public:
    virtual ISplitter *CreateSplitter()
    { // 让子类决定实例化哪个类
        return new BinarySplitter();
    }
};

class TxtSplitterFactory : public SplitterFactory
{
public:
    virtual ISplitter *CreateSplitter()
    {
        return new TxtSplitter();
    }
};

class PictureSplitterFactory : public SplitterFactory
{
public:
    virtual ISplitter *CreateSplitter()
    {
        return new PictureSplitter();
    }
};

class VideoSplitterFactory : public SplitterFactory
{
public:
    virtual ISplitter *CreateSplitter()
    {
        return new VideoSplitter();
    }
};

// 客户端程序
class MainForm : public Form
{
private:
    SplitterFactory *factory;

public:
    MainForm(SplitterFactory *factory)
    {
        this->factory = factory;
    }

    void Button1_Click()
    {

        ISplitter *splitter = factory->CreateSplitter(); // 多态new的体现

        splitter->split();
    }
};




/*   Prototype原型模式  */

// 抽象类
class ISplitter
{ // UML中的Prototype【稳定】
public:
    virtual void split() = 0;
    virtual ISplitter *Clone() = 0; // 通过克隆自己来创建对象
    virtual ~ISplitter() {}
};

// 具体类
class BinarySplitter : public ISplitter
{ // UML中的ConcretePrototype1【变化】
public:
    virtual ISplitter *Clone()
    { // 让子类决定实例化哪个类
        return new BinarySplitter(*this);  // 此处执行拷贝构造函数(深拷贝)
    }
};

class TxtSplitter : public ISplitter
{ // UML中的ConcretePrototype2【变化】
public:
    virtual ISplitter *Clone()
    { // 让子类决定实例化哪个类
        return new TxtSplitter(*this);
    }
};

class PictureSplitter : public ISplitter
{  // UML中的ConcretePrototype3【变化】
public:
    virtual ISplitter *Clone()
    { // 让子类决定实例化哪个类
        return new PictureSplitter(*this);
    }
};

class VideoSplitter : public ISplitter
{  // UML中的ConcretePrototype4【变化】
public:
    virtual ISplitter *Clone()
    { // 让子类决定实例化哪个类
        return new VideoSplitter(*this);
    }
};


// 客户端程序,UML中的Client
class MainForm : public Form
{
private:
    ISplitter* prototype;  // 原型对象

public:
    MainForm(ISplitter *prototype)
    {
        this->prototype = prototype;
    }

    void Button1_Click()
    {

        ISplitter *splitter = prototype->Clone(); // 通过克隆原型prototype得到一个新对象splitter

        splitter->split();
    }
};
