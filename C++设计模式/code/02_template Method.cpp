#include <iostream>
#include <vector>

using namespace std;

/*  结构化软件设计  */
// Library开发人员：开发1、3、5三个步骤
// Application开发人员：开发2和4两个步骤；程序主流程
// Application开发人员调用Library开发人员（早绑定）


// 程序库开发人员
class Library
{
public:
    void step1()
    {
        //...
    }
    void step3()
    {
        //...
    }
    void step5()
    {
        //...
    }
};

// 应用程序开发人员
class Application
{
public:
    bool step2()
    {
        // ...
    }
    void step4()
    {
        // ...
    }
};

int main()
{
    Library lib();
    Application app();

    lib.step1();

    if (app.step2())
    {
        lib.step3();
    }

    for (int i = 0; i < 4; i++)
    {
        app.step4();
    }
    lib.step5();
    return 0;
}


/*   面向对象软件设计:template Method模式  */
// Library开发人员：开发1、3、5三个步骤；程序主流程
// Application开发人员：开发2、4两个步骤
// Library开发人员调用Application开发人员（晚绑定）



// 程序库开发人员
class Library
{
public:
    // 稳定  template method
    void Run()
    {
        step1();

        if (step2()) // 支持变化  ===> 虚函数的多态调用
        { 
            step3();
        }

        for (int i = 0; i < 4; i++)
        {
            step4(); // 支持变化  ===> 虚函数的多态调用
        }

        step5();
    }

    virtual ~Library() {}

protected:
    void step1()
    { // 稳定
        // ...
    }

    void step3()
    { // 稳定
        // ...
    }

    void step5()
    { // 稳定
        // ...
    }
    virtual bool step2() = 0; // 变化
    virtual void step4() = 0; // 变化
};

// 应用程序开发人员
class Application : public Library
{
protected:
    virtual bool step2()
    {
        // ...  子类重写实现
    }

    virtual void step4()
    {
        // ...  子类重写实现
    }
};

int main()
{
    Library *pLib = new Application();
    pLib->Run();

    delete pLib;
    return 0;
}
