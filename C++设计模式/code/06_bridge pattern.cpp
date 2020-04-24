#include <iostream>
#include <string>

using namespace std;

/*    普通方法     */
class Messager
{
public:
    virtual void Login(string username, string password) = 0;
    virtual void SendMessage(string message) = 0;
    virtual void SendPicture(Image image) = 0;

    virtual void PlaySound() = 0;
    virtual void DrawShape() = 0;
    virtual void WriteText() = 0;
    virtual void Connect() = 0;

    virtual ~Messager() {}
};

// 平台实现n
class PCMessagerBase : public Messager
{
public:
    virtual void PlaySound()
    {
        // ***************
    }

    virtual void DrawShape()
    {
        // ****************
    }

    virtual void WriteText()
    {
        // ****************
    }

    virtual void Connect()
    {
        //  ***************
    }
};

class MobileMessagerBase : public Messager
{
public:
    virtual void PlaySound()
    {
        // ****************
    }

    virtual void DrawPicture()
    {
        // ****************
    }

    virtual void WriteText()
    {
        // ****************
    }

    virtual void Connect()
    {
        // ****************
    }
};


// 业务抽象m
// 类的数目：1+n+m*n
class PCMessagerLite: public PCMessagerBase
{
public:
    virtual void Login(string username, string password)
    {
        PCMessagerBase::Connect();
        // ..............
    }

    virtual void SendMessage(string message)
    {
        PCMessagerBase::WriteText();
        // ...............
    }

    virtual void SendPicture(Image image)
    {
        PCMessagerBase::DrawShape();
        // .................
    }
};


class PCMessagerPerfect : public PCMessagerBase
{
public:
    virtual void Login(string username, string password)
    {
        PCMessagerBase::PlaySound();
        // ***********
        PCMessagerBase::Connect();
        // ...........
    }

    virtual void SendMessage(string message)
    {
        PCMessagerBase::PlaySound();
        // ***********
        PCMessagerBase::WriteText();
        // ...............
    }

    virtual void SendPicture(Image image)
    {
        PCMessagerBase::PlaySound();
        // ***********
        PCMessagerBase::DrawShape();
        // .................
    }
};



class MobileMessagerLite: public MobileMessagerBase
{
public:
    virtual void Login(string username, string password)
    {
        MobileMessagerBase::Connect();
        // =========================
    }

    virtual void SendMessage(string message)
    {
        MobileMessagerBase::WriteText();
        // ==========================
    }

    virtual void SendPicture(Image image)
    {
        MobileMessagerBase::DrawShape();
        // ===========================
    }
};

class MobileMessagerPerfect : public MobileMessagerBase
{
public:
    virtual void Login(string username, string password)
    {
        MobileMessagerBase::PlaySound();
        // *************************
        MobileMessagerBase::Connect();
        // =========================
    }

    virtual void SendMessage(string message)
    {
        MobileMessagerBase::PlaySound();
        // ************************
        MobileMessagerBase::WriteText();
        // ==========================
    }

    virtual void SendPicture(Image image)
    {
        MobileMessagerBase::PlaySound();
        // ***************************
        MobileMessagerBase::DrawShape();
        // ===========================
    }
};

void Process(){
    // 编译时装配
    Messager* m = new MobileMessagerPerfect();
}




/*  桥模式方法  */
class Messager  // UML中的Abstraction【稳定】
{
protected:
    MessagerImp* messagerImp;
public:
    Messager(MessagerImp* messagerimp):  messagerImp(messagerimp){}
    virtual void Login(string username, string password) = 0;
    virtual void SendMessage(string message) = 0;
    virtual void SendPicture(Image image) = 0;
    virtual ~Messager() {}
};


class MessagerImp  // UML中的Implementor【稳定】
{
public:
    virtual void PlaySound() = 0;
    virtual void DrawShape() = 0;
    virtual void WriteText() = 0;
    virtual void Connect() = 0;
    virtual ~MessagerImp() {}
};


// 平台实现n
class PCMessagerImp : public MessagerImp  // UML中的ConcreteImplementorA【变化】
{
public:
    virtual void PlaySound()
    {
        // ***************
    }

    virtual void DrawShape()
    {
        // ****************
    }

    virtual void WriteText()
    {
        // ****************
    }

    virtual void Connect()
    {
        //  ***************
    }
};

class MobileMessagerImp : public MessagerImp  // UML中的ConcreteImplementorB【变化】
{
public:
    virtual void PlaySound()
    {
        // ****************
    }

    virtual void DrawPicture()
    {
        // ****************
    }

    virtual void WriteText()
    {
        // ****************
    }

    virtual void Connect()
    {
        // ****************
    }
};


// 业务抽象m
// 类的数目：1+n+m
class MessagerLite: public Messager  // UML中的RefinedAbstraction【变化】
{
public:
    MessagerLite(MessagerImp* messagerimp):Messager(messagerimp){}
    virtual void Login(string username, string password)
    {
        messagerImp->Connect();
        // ..............
    }

    virtual void SendMessage(string message)
    {
        messagerImp->WriteText();
        // ...............
    }

    virtual void SendPicture(Image image)
    {
        messagerImp->DrawShape();
        // .................
    }
};


class MessagerPerfect: public Messager   // UML中的RefinedAbstraction【变化】
{
public:
    MessagerPerfect(MessagerImp* messagerimp):Messager(messagerimp){}
    virtual void Login(string username, string password)
    {
        messagerImp->PlaySound();
        // *************************
        messagerImp->Connect();
        // =========================
    }

    virtual void SendMessage(string message)
    {
       messagerImp->PlaySound();
        // ************************
        messagerImp->WriteText();
        // ==========================
    }

    virtual void SendPicture(Image image)
    {
        messagerImp->PlaySound();
        // ***************************
        messagerImp->DrawShape();
        // ===========================
    }
};

void Process(){
    // 运行时装配
    MessagerImp* mImp = new PCMessagerImp();
    Messager* m = new Messager(mImp);
}