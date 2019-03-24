### 1.C++中的时间和日期
- C++标准库没有提供所谓的日期类型，C++继承了C语言用于日期和时间操作的结构和函数。为了使用日期和时间相关的函数和结构，需要在C++程序中引用"ctime"头文件。有四个与时间相关的类型：clock_t,time_t,size_t,tm。类型clock_t,size_t,time_t能够把系统时间和日期表示为某种整数；结构体类型tm把时间和日期以C结构体的形式保存，tm结构体的定义如下：
    ```
        struct tm{
            int tm_sec;   // 秒，正常范围从 0 到 59，但允许至 61
            int tm_min;  // 分，范围从 0 到 59
            int tm_hour;  // 小时，范围从 0 到 23
            int tm_mday;  // 一月中的第几天，范围从 1 到 31
            int tm_mon;   // 月，范围从 0 到 11
            int tm_year;  // 自 1900 年起的年数
            int tm_wday;  // 一周中的第几天，范围从 0 到 6，从星期日算起  
            int tm_yday;  // 一年中的第几天，范围从 0 到 365，从 1 月 1 日算起
            int tm_isdst;  // 夏令时
        };
    ```
- 下面是C/C++中关于日期和时间的重要函数。所有这些函数都是C/C++标准库的组成部分，可以在C++标准库中查看一下各个函数的细节：
![与时间有关的函数.png](https://upload-images.jianshu.io/upload_images/13407176-2755b126d6b6ed6f.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)
- 1.1 C库函数--time()
    - 描述：C库函数time_t time(time_t *seconds)返回自纪元 Epoch（1970-01-01 00:00:00 UTC）起经过的时间，以秒为单位。如果seconds不为空，则返回值也存储在变量seconds中。
    - 声明：time_t time(time_t *t);
    - 参数：seconds--指针类型为time_t的对象的指针，用来存储seconds的值
    - 返回值：以time_t对象返回当前日历的时间
    - 实例如下:
        ```
            #include "iostream"
            #include "ctime"   // C++中没有处理时间的库，所以继承自C语言
            #include "cstdio"
            time_t seconds;
            seconds = time(NULL);
            cout << "自1970-01-01起的小时数: " << seconds / 3600 << endl;
        ```
- 1.2 C库函数--ctime()
    - 描述：C库函数char *ctime(const time_t *timer) 返回一个表示当地时间的字符串，当地时间是基于参数timer。返回的字符串格式如下：Www Mmm dd hh:mm:ss yyyy其中，Www表示星期几，Mmm是以字母表示的月份，dd表示一月中的第几天，hh:mm:ss表示时间，yyyy表示年份。
    - 声明： char *ctime(const time_t *timer);   指针函数
    - 参数： 指向time_t对象的指针，该对象包含一个日历时间
    - 返回值：该函数返回一个 C 字符串，该字符串包含了可读格式的日期和时间信息。
    - 实例如下：
        ```
            time_t curtime;
            time(&curtime);
            cout << "当前时间: " << ctime(&curtime) << endl;
        ```
- 1.3 C库函数--localtime()
    - 描述：C库函数struct tm *localtime(const time_t *timer)使用timer的值来填充tm结构。timer的值被分解为tm结构体，并用本地时区表示。
    - 声明：struct tm *localtime(const time_t *timer)
    - 参数：timer是指向表示日历时间的time_t值的指针
    - 返回值：该函数返回指向 tm 结构的指针，该结构带有被填充的时间信息。下面是 tm 结构的细节：
        ```
            struct tm{
                int tm_sec;   // 秒，正常范围从 0 到 59，但允许至 61
                int tm_min;  // 分，范围从 0 到 59
                int tm_hour;  // 小时，范围从 0 到 23
                int tm_mday;  // 一月中的第几天，范围从 1 到 31
                int tm_mon;   // 月，范围从 0 到 11
                int tm_year;  // 自 1900 年起的年数
                int tm_wday;  // 一周中的第几天，范围从 0 到 6，从星期日算起  
                int tm_yday;  // 一年中的第几天，范围从 0 到 365，从 1 月 1 日算起
                int tm_isdst;  // 夏令时
            };
        ```
    - 实例如下：
        ```
            time_t rawtime;
            struct tm *info;
            char buffer[80];

            time(&rawtime);
            info = localtime(&rawtime);
            cout << "当前的本地时间和日期: " << asctime(info) << endl;
        ```
- 1.4 C库函数--clock()
    - 描述：C库函数clock_t clock(void)返回程序执行起（一般为程序的开头），处理器时钟所使用的时间。为了获取 CPU 所使用的秒数，您需要除CLOCKS_PER_SEC。在32位系统中，CLOCKS_PER_SEC=1000000，该函数大约每72分钟会返回相同的值。
    - 声明：clock_t clock(void)
    - 参数：无
    - 实例如下：
        ```
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
        ```
- 1.5 C库函数--asctime()
    - 描述：C库函数char *asctime(const struct tm *timeptr)返回一个指向字符串的指针，它代表了结构体struct timeptr的日期和时间
    - 声明：char *asctime(const struct tm *timeptr);
    - 参数：timeptr是指向tm结构体的指针，包含了分解为如下各部分的日历时间：
        ```
            struct tm{
                int tm_sec;   // 秒，正常范围从 0 到 59，但允许至 61
                int tm_min;  // 分，范围从 0 到 59
                int tm_hour;  // 小时，范围从 0 到 23
                int tm_mday;  // 一月中的第几天，范围从 1 到 31
                int tm_mon;   // 月，范围从 0 到 11
                int tm_year;  // 自 1900 年起的年数
                int tm_wday;  // 一周中的第几天，范围从 0 到 6，从星期日算起  
                int tm_yday;  // 一年中的第几天，范围从 0 到 365，从 1 月 1 日算起
                int tm_isdst;  // 夏令时
            };
        ```
    - 返回值：该函数返回一个C字符串，包含了可读格式的日期和时间信息Www Mmm dd hh:mm:ss yyyy，其中，Www表示星期几，Mmm是以字母表示的月份，dd表示一月中的第几天，hh:mm:ss表示时间，yyyy表示年份。
    - 实例如下：
        ```
            struct tm t;
            t.tm_sec = 10;
            t.tm_min = 10;
            t.tm_hour = 6;
            t.tm_mday = 25;
            t.tm_mon = 2;
            t.tm_year = 89;
            t.tm_wday = 6;
            puts(asctime(&t));
        ```
- 1.6 C库函数--gmtime()
    - 描述：C库函数struct tm *gmtime(const time_t *timer) 使用timer的值来填充tm结构体，并用协调世界时（UTC）也被称为格林尼治标准时间（GMT）表示。
    - 声明：struct tm *gmtime(const time_t *timer);
    - 参数：timeptr是指向表示日历时间的 time_t 值的指针
    - 该函数返回指向tm结构的指针，该结构带有被填充的时间信息。下面是timeptr结构体的细节：  
        ```
            struct tm{
                int tm_sec;   // 秒，正常范围从 0 到 59，但允许至 61
                int tm_min;  // 分，范围从 0 到 59
                int tm_hour;  // 小时，范围从 0 到 23
                int tm_mday;  // 一月中的第几天，范围从 1 到 31
                int tm_mon;   // 月，范围从 0 到 11
                int tm_year;  // 自 1900 年起的年数
                int tm_wday;  // 一周中的第几天，范围从 0 到 6，从星期日算起  
                int tm_yday;  // 一年中的第几天，范围从 0 到 365，从 1 月 1 日算起
                int tm_isdst;  // 夏令时
            };
        ```
    - 实例如下:
        ```
            time_t raw_time;
            struct tm *info1;

            time(&raw_time);
            /* 获取 GMT 时间 */
            info = gmtime(&raw_time );
            printf("伦敦：%2d:%02d\n", (info1->tm_hour + BST)%24, info1->tm_min);
            printf("中国：%2d:%02d\n", (info1->tm_hour + CCT)%24, info1->tm_min);
        ```
- 1.7 C库函数--mktime()
    - 描述：C库函数time_t mktime(struct tm *timeptr) 把 timeptr所指向的结构体转换为一个依据本地时区的time_t值
    - 声明：time_t mktime(struct tm *timeptr);
    - 参数：timeptr是指向表示日历时间的time_t值的指针，该日历时间被分解为以下各部分。下面是 timeptr 结构的细节：
        ```
            struct tm{
                int tm_sec;   // 秒，正常范围从 0 到 59，但允许至 61
                int tm_min;  // 分，范围从 0 到 59
                int tm_hour;  // 小时，范围从 0 到 23
                int tm_mday;  // 一月中的第几天，范围从 1 到 31
                int tm_mon;   // 月，范围从 0 到 11
                int tm_year;  // 自 1900 年起的年数
                int tm_wday;  // 一周中的第几天，范围从 0 到 6，从星期日算起  
                int tm_yday;  // 一年中的第几天，范围从 0 到 365，从 1 月 1 日算起
                int tm_isdst;  // 夏令时
            };
        ```
    - 返回值：该函数返回一个time_t值，该值对应于以参数传递的日历时间。如果发生错误，则返回 -1 值
    - 实例如下：
        ```
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
        ```
- 1.8 C库函数--difftime()   
    - 描述：C库函数 double difftime(time_t time1, time_t time2)返回time1 和time2之间相差的秒数(time1 - time2)。这两个时间是在日历时间中指定的，表示了自纪元Epoch（协调世界时 UTC：1970-01-01 00:00:00）起经过的时间。
    - 声明：double difftime(time_t time1, time_t time2);
    - 参数：time1是表示结束时间的time_t对象，time2是表示开始时间的time_t对象
    - 返回值：该函数返回以双精度浮点型double值表示的两个时间之间相差的秒数 (time2 - time1)
    - 实例如下：
        ```
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
        ```
- 1.9 C库函数--strftime()
    - 描述：C库函数size_t strftime(char *str, size_t maxsize, const char *format, const struct tm *timeptr)根据format中定义的格式化规则，格式化结构体timeptr表示的时间，并把它存储在str中。
    - 声明：size_t strftime(char *str, size_t maxsize, const char *format, const struct tm *timeptr);
    - 参数：
        - str是指向目标数组的指针，用来复制产生的C字符串
        - maxsize是被复制到str的最大字符数
        - format是C字符串，包含了普通字符和特殊格式说明符的任何组合。这些格式说明符由函数替换为表示tm中所指定时间的相对应值。格式说明符是：
            ![格式1.png](https://upload-images.jianshu.io/upload_images/13407176-8486a0621b015565.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)
            ![格式2.png](https://upload-images.jianshu.io/upload_images/13407176-8d2b58ed0b407514.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)
        - timeptr是指向tm结构体的指针，该结构包含了一个被分解为以下各部分的日历时间：   
            ```
                struct tm{
                int tm_sec;   // 秒，正常范围从 0 到 59，但允许至 61
                int tm_min;  // 分，范围从 0 到 59
                int tm_hour;  // 小时，范围从 0 到 23
                int tm_mday;  // 一月中的第几天，范围从 1 到 31
                int tm_mon;   // 月，范围从 0 到 11
                int tm_year;  // 自 1900 年起的年数
                int tm_wday;  // 一周中的第几天，范围从 0 到 6，从星期日算起  
                int tm_yday;  // 一年中的第几天，范围从 0 到 365，从 1 月 1 日算起
                int tm_isdst;  // 夏令时
            };
            ```
        - 实例如下：
            ```
                time_t raw_time3;
                struct tm *info3;
                char buffer[80];
                time( &raw_time3 );
                info3 = localtime( &raw_time3 );
                strftime(buffer, 80, "%Y-%m-%d %H:%M:%S", info3);
                printf("格式化的日期 & 时间 : |%s|\n", buffer);
            ```
### 2.当前时间和日期
- 下面的实例获取当前系统的日期和时间，包括本地时间和协调世界时（UTC）    
    ```
        // 2.当前日期和时间
        time_t now = time(0);
        // 把 now 转换为字符串形式
        char* dt = ctime(&now);
        cout << "本地日期和时间：" << dt << endl;
        // 把 now 转换为 tm 结构
        tm *gmtm = gmtime(&now);
        dt = asctime(gmtm);
        cout << "UTC日期和时间："<< dt << endl;
    ```
### 3.使用结构体tm格式化时间
- tm结构体在C/C++中处理日期和时间相关的操作时，显得尤为重要。tm结构体以C结构体的形式保存日期和时间。大多数与时间相关的函数都使用了tm结构体。下面的实例使用了tm结构体和各种与日期和时间相关的函数。在练习使用结构之前，需要对C结构体有基本的了解，并懂得如何使用箭头s->运算符来访问结构成员。
    ```
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
    ```


