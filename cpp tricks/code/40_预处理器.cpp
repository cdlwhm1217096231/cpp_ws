#include "iostream"

using namespace std;

#define PI 3.14
#define MIN(a, b) (a<b ? a:b)  // 带参数的宏
#define DEBUG 

// #运算符
#define MKSTR(x) #x

// ##运算符
#define CONCAT(a, b) a ## b  // 当CONCAT出现在程序中时，它的参数会被连接起来，并用来取代宏





int main(){
    cout << "PI = " << PI << endl;
    int i =20, j=39;
    cout << "MIN(i, j) = " << MIN(i, j) << endl;
#ifdef DEBUG
    cerr <<"Trace: Inside main function" << endl;
#endif
 
#if 0
   /* 这是注释部分 */
   cout << MKSTR(HELLO C++) << endl;
#endif

#ifdef DEBUG
    cerr <<"Trace: Coming out of main function" << endl;
#endif
    cout << MKSTR(Hello C++) << endl;

    int ij = 100;
    cout << CONCAT(i, j);
    // 预定义宏
    cout << "__LINE__ = " << __LINE__ << endl;
    cout << "__FILE = " << __FILE__ << endl;
    cout << "__DATE = " << __DATE__ << endl;
    cout << "__TIME = " << __TIME__ << endl;
    return 0;
}