#include "iostream"

using namespace std;   // 使用标准命名空间

// 第一个命名空间
namespace first_space{
    void func(){
        cout << "I come from frist space.\n";
    }
}

// 第二个命名空间
namespace second_space{
    void func(){
        cout << "I come from second space.\n";
    }
}

// 第三个命名空间
namespace third_space{
    void func(){
        cout << "I come from third space.\n";
    }
}

using namespace third_space;  // 注意这一句！！！

// 命名空间的嵌套
namespace four_space{
    void fun(){
        cout << "I come from four space.\n";
    }
    namespace five_space{
        void fun(){
            cout << "I come from five space.\n";
        }
    }
}

// using namespace four_space::five_space;
using namespace four_space;

int main(){
    // 调用第一个命名空间中的函数
    first_space::func();
    // 调用第二个命名空间中的函数
    second_space::func();
    // 调用第三个命名空间中的函数
    func();
    // 调用第二个命名空间中的函数
    five_space::fun();
    return 0;
}