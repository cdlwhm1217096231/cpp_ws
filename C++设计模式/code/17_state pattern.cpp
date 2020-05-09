#include <iostream>

using namespace std;


/*  普通方法  */

enum NetworkState{
    Network_Open,
    Network_Close,
    Network_Connect,
    Network_Wait,   // 新增状态
};

// 客户程序
class NetworkProcessor{
private:
    NetworkState state;
public:
    void Operation1(){
        if(state == Network_Open){
            
            // *************
            state = Network_Close;
        }
        else if(state == Network_Close){

            // ..............
            state = Network_Connect;
        }
        else if(state == Network_Connect){

            // $$$$$$$$$$$$$$$
            state = Network_Open;
        }
        else if(state == Network_Wait){   // 新增状态对应的行为

            // &&&&&&&&&&&&&&&&&&
        }
    }

    void Operation2(){
        if(state == Network_Open){

            // *******************
            state == Network_Connect;
        }
        else if(state = Network_Close){

            // .....................
            state = Network_Open;
        }
        else if(state == Network_Connect){

            // $$$$$$$$$$$$$$$$$$$$
            state = Network_Close;
        }
    }

    void Operation3(){

    }
};



/*  状态模式  */

class NetworkState{
public:
    NetworkState* pNext;
    virtual void Operation1() = 0;
    virtual void Operation2() = 0;
    virtual void Operation3() = 0;

    virtual ~NetworkState(){}
};


class OpenState: public NetworkState{
private:
    static NetworkState* m_instance;
public:
    static NetworkState* getInstance(){
        if(m_instance == nullptr){
            m_instance = new OpenState();
        }
        return m_instance;
    }

    void Operation1(){

        // ****************
        pNext = CloseState::getInstance();
    }

    void Operation2(){

        // ................
        pNext = ConnectState::getInstance();
    }

    void Operation3(){

        // $$$$$$$$$$$$$$$$$$$$
        pNext = OpenState::getInstance();
    }
};

class CloseState: public NetworkState{
// .......
};


class ConnectState: public NetworkState{
// .......
};


// 新增状态(扩展子类)
class WaitState: public NetworkState{
// .......
};

// 客户程序
class NetworkProcessor{
private:
    NetworkState* pState;
public:
    NetworkProcessor(NetworkState* pState){
        this->pState = pState;
    }

    void Operation1(){
        // ........
        pState->Operation1();
        pState = pState->pNext;
        // ........
    }

    void Operation2(){
        // ........
        pState->Operation2();
        pState = pState->pNext;
        // ........
    }


    void Operation3(){
        // ........
        pState->Operation3();
        pState = pState->pNext;
        // ........
    }
};


