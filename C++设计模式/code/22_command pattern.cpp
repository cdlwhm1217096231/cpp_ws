#include <iostream>
#include <string>
#include <vector>

using namespace std;


/*  命令模式   */

class Command{
public:
    virtual void execute() = 0;
};


class ConcreteCommand1: public Command {
private:
    string arg;
public:
    ConcreteCommand1(const string& a): arg(a) {

    }
    // 重写
    void execute() {
        cout << "#1 process..." << arg << endl;
    }
};


class ConcreteCommand2: public Command {
private:
    string arg;
public:
    ConcreteCommand2(const string& a): arg(a) {

    }
    // 重写
    void execute() {
        cout << "#2 process..." << arg << endl;
    }
};


class MacroCommand: public Command {
private:
    vector<Command*> commands;
public:
    void addCommand(Command* c) {
        commands.push_back(c);
    }
    // 重写
    void execute() {
        for(auto &c:commands){
            c->execute();
        }
    }
};

int main(){
    ConcreteCommand1 command1("Arg ###");
    ConcreteCommand2 command2("Arg $$$");

    MacroCommand macro;
    macro.addCommand(&command1);
    macro.addCommand(&command2);

    macro.execute();
    return 0;
}