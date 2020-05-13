#include <iostream>
#include <string>

using namespace std;


/*  职责链模式  */

enum class RequestType {
    REQ_HANDLER1,
    REQ_HANDLER2,
    REQ_HANDLER3
};

class Request {
private:
    string description;
    RequestType reqType;
public:
    Request(const string& desc, RequestType type): description(desc), reqType(type){}
    RequestType getRequestType() const {return reqType;}
    const string& getDescription() const {return description;}
};

// 稳定的
class ChainHandler{
private:
    ChainHandler* nextChain;
    void sendRequestToNextHandler(const Request& req){
        if(nextChain != nullptr) {
            nextChain->handle(req);
        }
    }
protected:
    virtual bool canHandleRequest(const Request& req) = 0;
    virtual void processRequest(const Request& req) = 0;
public:
    ChainHandler(){
        nextChain = nullptr;
    }

    void sexNextChain(ChainHandler* next) {
        nextChain = next;
    }

    void handle(const Request& req){
        if(canHandleRequest(req)){
            processRequest(req);
        }
        else{
            sendRequestToNextHandler(req);
        }
    }

};   

// 变化的
class Handler1: public ChainHandler {
protected:
// 重写，多态性
    bool canHandlerRequest(const Request& req){
        return req.getRequestType() == RequestType::REQ_HANDLER1;
    }

    void processRequest(const Request& req){
        cout << "Handler1 is handle request: " << req.getDescription() << endl;
    }
};

class Handler2: public ChainHandler {
protected:
    bool canHandlerRequest(const Request& req){
        return req.getRequestType() == RequestType::REQ_HANDLER2;
    }

    void processRequest(const Request& req){
        cout << "Handler2 is handle request: " << req.getDescription() << endl;
    }
};


class Handler3: public ChainHandler {
protected:
    bool canHandlerRequest(const Request& req){
        return req.getRequestType() == RequestType::REQ_HANDLER3;
    }

    void processRequest(const Request& req){
        cout << "Handler3 is handle request: " << req.getDescription() << endl;
    }
};


int main() {
    Handler1 h1;
    Handler2 h2;
    Handler3 h3;
    h1.sexNextChain(&h2);
    h2.sexNextChain(&h3);

    Request req("process task ...", RequestType::REQ_HANDLER3);
    h1.handle(req);
    return 0;
}