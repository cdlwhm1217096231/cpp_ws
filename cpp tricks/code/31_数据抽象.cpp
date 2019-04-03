#include "iostream"

using namespace std;


class Add{
    public:
        Add(int i=0): total(i){
            cout << "Add类对象的构造函数\n";
        }
        // 对外的接口
        void addNum(int num){
            total += num;
        }
        // 对外的接口
        int getTotal(){
            return total;
        }
        ~Add(){
            cout << "Add对象的析构函数\n";
        }
    private:
        // 对外隐藏的数据
        int total;
};


int main(){
    Add add;
    add.addNum(10);
    add.addNum(20);
    add.addNum(30);
    cout << "Total: " << add.getTotal() << endl;
    return 0;
}
