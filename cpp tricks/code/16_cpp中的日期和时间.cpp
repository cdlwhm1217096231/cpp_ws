#include "iostream"
#include "ctime"   // C++中没有处理时间的库，所以继承自C语言
#include "cstdio"

#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

#define BST (+1)
#define CCT (+8)

using namespace std;



int main(){
    time_t seconds;
    seconds = time(NULL);
    cout << "自1970-01-01起的小时数: " << seconds / 3600 << endl;
    /*-----------------------------------*/
    time_t curtime;
    time(&curtime);
    cout << "当前时间: " << ctime(&curtime) << endl;
    /*-----------------------------------*/
    time_t rawtime;
    struct tm *info;
    char buffer[80];

    time(&rawtime);
    info = localtime(&rawtime);
    cout << "当前的本地时间和日期: " << asctime(info) << endl;
    /*-----------------------------------*/
    clock_t start_t, end_t;
    double total_t;
    int i;
    start_t = clock();
    cout << "程序启动, start_t = " << start_t << endl;
    cout << "开始一个大循环, start_t = " << start_t << endl;
    for (i = 0; i < 10000000; i++){

    }
    end_t = clock();
    cout << "大循环结束,end_t = " << end_t << endl;
    total_t = (double)(end_t - start_t) / CLOCKS_PER_SEC;
    cout << "cpu占用的总时间: " << total_t << endl;
    cout << "程序结束，退出...\n";
    /*-----------------------------------*/
    struct tm t;
    t.tm_sec = 10;
    t.tm_min = 10;
    t.tm_hour = 6;
    t.tm_mday = 25;
    t.tm_mon = 2;
    t.tm_year = 89;
    t.tm_wday = 6;
    puts(asctime(&t));
    /*-----------------------------------*/
    time_t raw_time;
    struct tm *info1;

    time(&raw_time);
    /* 获取 GMT 时间 */
    info = gmtime(&raw_time );
    printf("伦敦：%2d:%02d\n", (info1->tm_hour + BST)%24, info1->tm_min);
    printf("中国：%2d:%02d\n", (info1->tm_hour + CCT)%24, info1->tm_min);
    /*-----------------------------------*/
    time_t raw_time1;
    struct tm * timeinfo;
    int year,month,day;
    const char * weekday[] = {"周日", "周一","周二", "周三","周四", "周五", "周六"};
    /* 用户输入日期 */
    printf ("请输入哪年: "); fflush(stdout); scanf ("%d",&year);
    printf ("请输入哪月: "); fflush(stdout); scanf ("%d",&month);
    printf ("请输入哪日: "); fflush(stdout); scanf ("%d",&day);
 
    /* 获取当前时间信息，并修改用户输入的输入信息 */
    time ( &raw_time1 );
    timeinfo = localtime ( &raw_time1 );
    timeinfo->tm_year = year - 1900;
    timeinfo->tm_mon = month - 1;
    timeinfo->tm_mday = day;
 
    /* 调用 mktime: timeinfo->tm_wday  */
    mktime ( timeinfo );
 
    printf ("那一天是：%s\n", weekday[timeinfo->tm_wday]);
    /*-----------------------------------*/
    time_t start_t1, end_t1;
    double diff_t1;
    cout << "程序启动\n";
    time(&start_t1);
    cout << "休眠1000s\n";
    Sleep(1000);
    time(&end_t1);
    diff_t1 = difftime(end_t1, start_t1);
    cout << "执行时间: " << diff_t1<< endl;
    cout << "程序退出\n";
    /*-----------------------------------*/
    // 2.当前日期和时间
    time_t now = time(0);
    // 把 now 转换为字符串形式
    char* dt = ctime(&now);
    cout << "本地日期和时间：" << dt << endl;
    // 把 now 转换为 tm 结构
    tm *gmtm = gmtime(&now);
    dt = asctime(gmtm);
    cout << "UTC日期和时间："<< dt << endl;
    // 3.使用结构tm格式化时间
    time_t now = time(0);  //  基于当前系统的当前日期/时间
    cout << "1970 到目前经过秒数:" << now << endl;
    
    tm *ltm = localtime(&now);
    
    // 输出 tm 结构的各个组成部分
    cout << "年: "<< 1900 + ltm->tm_year << endl;
    cout << "月: "<< 1 + ltm->tm_mon<< endl;
    cout << "日: "<<  ltm->tm_mday << endl;
    cout << "时间: "<< ltm->tm_hour << ":";
    cout << ltm->tm_min << ":";
    cout << ltm->tm_sec << endl;
    return 0;
}