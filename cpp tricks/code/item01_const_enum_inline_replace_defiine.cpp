#include <iostream>
#include <string>
using namespace std;

#define PI 3.14

#define CALL_MAX(a, b) f((a) > (b) ? (a):(b))
// 使用inline代替带参数的宏
template<typename T>
inline void call_max(const T &a, const T &b){
    f(a > b) ? a:b;
}

class GamePlayer{
    public:
        static const int NumTurns = 5;
        static const double Factor;
        int scores[NumTurns];
        enum {numTurns = 8};
        int scoress[numTurns];
};

static const double Factor = 5.55;  // 静态成员变量在类外进行初始化


const int GamePlayer::NumTurns;  // NumTurns的定义，没有赋值，因为之前已经设初值5，定义时不可以设初值



int main(){
    cout << PI << endl;
    const double Pi = 3.14;
    cout << Pi << endl;
    const char* const authorName = "Curry_Coder";  // 指向常量的常量指针
    cout << authorName << endl;
    const string author_Name("Curry_Coder");
    cout << author_Name << endl;
    cout << GamePlayer::NumTurns << endl;
    return 0;
}