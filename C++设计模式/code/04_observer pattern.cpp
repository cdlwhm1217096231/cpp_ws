#include <cstdlib>
#include <iostream>
#include <string>
#include <list>

using namespace std;

/*  普通方法实现 */
class FileSplitter
{
private:
    string m_filePath;
    int m_fileNumber;
    ProgressBar *m_progressBar;

public:
    FileSplitter(const string &filePath, int fileNumber, ProgressBar *progressBar) : m_filePath(filePath), m_fileNumber(fileNumber), m_progressBar(progressBar)
    {
    }

    void split()
    {
        // 1.读取大文件

        // 2.分批次向小文件写入
        for (int i = 0; i < m_fileNumber; i++)
        {
            // ...
            if (m_progressBar != nullptr)
            {
                m_progressBar->setValue((i + 1) / m_fileNumber); // 更新进度条
            }
        }
    }
};

class MainForm : public Form
{
private:
    TextBox *txtFilePath;
    TextBox *txtFileNumber;

    ProgressBar *progressBar;

public:
    void Button1_Click()
    {
        string filePath = txtFilePath->getText();
        int number = atoi(txtFileNumber->getText().c_str());

        FileSplitter splitter(filePath, number, progressBar);

        splitter.split();
    }
};




/*  Observer/Event模式 */

// 使用一个抽象的方式来表示通知(IProgress)
class IProgress
{
public:
    virtual void DoProgress(float value) = 0;
    virtual ~IProgress() {}
};

// FileSplitter即UML中的ConcreteSubject【变化】
class FileSplitter   
{
private:
    string m_filePath;
    int m_fileNumber;
    // ProgressBar *m_progressBar;  m_progressBar是一个通知控件，是实现细节(变化)，可以使用一个相当抽象的方式(IProgress类)来表示通知
    list<IProgress *> m_iprogressList; // 实现细节(变化),利用抽象通知机制，支持多个观察者

public:
    FileSplitter(const string &filePath, int fileNumber) : m_filePath(filePath), m_fileNumber(fileNumber)
    {
    }

    void addIProgress(IProgress* iprogress)  // 即UML中的Subject的Attach()方法【稳定】
    {
        m_iprogressList.add(iprogress);
    }

    void removeIProgress(IProgress* iprogress)  // 即UML中的Subject的Detach()方法【稳定】
    {
        m_iprogressList.remove(iprogress);
    }

    void split()
    {
        // 1.读取大文件

        // 2.分批次向小文件写入
        for (int i = 0; i < m_fileNumber; i++)
        {
            // ...

            float progressValue = m_fileNumber;
            progressValue = (i + 1) / progressValue;
            OnProgress(progressValue); // 发送通知，不需要指定观察者
        }
    }

protected:
    virtual void OnProgress(float value)  // 即UML中的Subject的Notify()方法【稳定】方法
    {
        list<IProgress *>::iterator itor = m_iprogressList.begin();
        while (itor != m_iprogressList.end())
        {
            (*itor)->DoProgress(value); // 更新进度条
            itor++;
        }
    }
};

// 此处的多继承：只有一个父类，其余都是接口
// MainForm是UML中的ConcreteObserver，即具体的观察者【变化】
class MainForm : public Form, public IProgress
{
private:
    TextBox *txtFilePath;
    TextBox *txtFileNumber;

    ProgressBar *progressBar;

public:
    void Button1_Click()
    {
        string filePath = txtFilePath->getText();
        int number = atoi(txtFileNumber->getText().c_str());

        ConsoleNotifer cn;

        FileSplitter splitter(filePath, number);

        splitter.addIProgress(this); // 观察者1订阅通知
        splitter.addIProgress(&cn);  // 观察者2订阅通知

        splitter.split();

        splitter.removeIProgress(this);
    }

    virtual void DoProgress(float value)
    {
        progressBar->setValue(value);
    }
};

// ConsoleNotifer是UML中的ConcreteObserver，即具体的观察者【变化】
class ConsoleNotifer : public IProgress
{
public:
    virtual void DoProgress(float value)
    {
        cout << '.';
    }
};