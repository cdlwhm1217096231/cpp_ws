#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*  普通方法  */

// 业务操作
class Stream
{
public:
    virtual char Read(int number) = 0;
    virtual void Seek(int position) = 0;
    virtual void Write(char data) = 0;

    virtual ~Stream() {}
};

// 主体类
class FileStream : public Stream
{
public:
    virtual char Read(int number)
    {
        // 读文件流
    }

    virtual void Seek(int position)
    {
        // 定位文件流
    }

    virtual void Write(char data)
    {
        // 写文件流
    }
};

class NetworkStream : public Stream
{
public:
    virtual char Read(int number)
    {
        // 读网络流
    }

    virtual void Seek(int position)
    {
        // 定位网络流
    }

    virtual void Write(char data)
    {
        // 写网络流
    }
};

class MemoryStream : public Stream
{
public:
    virtual char Read(int number)
    {
        // 读内存流
    }

    virtual void Seek(int position)
    {
        // 定位内存流
    }

    virtual void Write(char data)
    {
        // 写内存流
    }
};

// 扩展操作
class CryptoFileStream : public FileStream
{
public:
    virtual char Read(int number)
    {
        // 额外的加密操作...
        FileStream::Read(number); // 读文件流
    }

    virtual void Seek(int position)
    {
        // 额外的加密操作...
        FileStream::Seek(position); // 定位文件流
        // 额外的加密操作...
    }

    virtual void Write(char data)
    {
        // 额外的加密操作...
        FileStream::Write(data); // 写文件流
        // 额外的加密操作...
    }
};

class CryptoNetworkStream : public NetworkStream
{
public:
    virtual char Read(int number)
    {
        // 额外的加密操作...
        NetworkStream::Read(number); // 读网络流
    }

    virtual void Seek(int position)
    {
        // 额外的加密操作...
        NetworkStream::Seek(position); // 定位网络流
        // 额外的加密操作...
    }

    virtual void Write(char data)
    {
        // 额外的加密操作...
        NetworkStream::Write(data); // 写网络流
        // 额外的加密操作...
    }
};

class CryptoMemoryStream : public MemoryStream
{
public:
    virtual char Read(int number)
    {
        // 额外的加密操作...
        MemoryStream::Read(number); // 读内存流
    }

    virtual void Seek(int position)
    {
        // 额外的加密操作...
        MemoryStream::Seek(position); // 定位内存流
        // 额外的加密操作...
    }

    virtual void Write(char data)
    {
        // 额外的加密操作...
        MemoryStream::Write(data); // 写内存流
        // 额外的加密操作...
    }
};

// 缓冲处理
class BufferedFileStream : public FileStream
{
    // ...
};

class BufferedNetworkStream : public NetworkStream
{
    // ...
};

class BufferedMemoryStream : public MemoryStream
{
    // ...
};

// 加密操作+缓冲处理
class CryptoBufferedFileStream : public FileStream
{
public:
    virtual char Read(int number)
    {
        // 额外的加密操作...
        // 额外的缓冲操作...
        FileStream::Read(number); // 读文件流
    }

    virtual void Seek(int position)
    {
        // 额外的加密操作...
        // 额外的缓冲操作...
        FileStream::Seek(position); // 定位文件流
        // 额外的加密操作...
        // 额外的缓冲操作...
    }

    virtual void Write(char data)
    {
        // 额外的加密操作...
        // 额外的缓冲操作...
        FileStream::Write(data); // 写文件流
        // 额外的加密操作...
        // 额外的缓冲操作...
    }
};

class CryptoBufferedNetworkStream : public NetworkStream
{
public:
    virtual char Read(int number)
    {
        // 额外的加密操作...
        // 额外的缓冲操作...
        NetworkStream::Read(number); // 读网络流
    }

    virtual void Seek(int position)
    {
        // 额外的加密操作...
        // 额外的缓冲操作...
        NetworkStream::Seek(position); // 定位网络流
        // 额外的加密操作...
        // 额外的缓冲操作...
    }

    virtual void Write(char data)
    {
        // 额外的加密操作...
        // 额外的缓冲操作...
        NetworkStream::Write(data); // 写网络流
        // 额外的加密操作...
        // 额外的缓冲操作...
    }
};

class CryptoBufferedMemoryStream : public MemoryStream
{
public:
    virtual char Read(int number)
    {
        // 额外的加密操作...
        // 额外的缓冲操作...
        MemoryStream::Read(number); // 读内存流
    }

    virtual void Seek(int position)
    {
        // 额外的加密操作...
        // 额外的缓冲操作...
        MemoryStream::Seek(position); // 定位内存流
        // 额外的加密操作...
        // 额外的缓冲操作...
    }

    virtual void Write(char data)
    {
        // 额外的加密操作...
        // 额外的缓冲操作...
        MemoryStream::Write(data); // 写内存流
        // 额外的加密操作...
        // 额外的缓冲操作...
    }
};

void Process()
{
    // 编译时装配
    CryptoFileStream *fs1 = new CryptoFileStream();
    BufferedFileStream *fs2 = new BufferedFileStream();
    CryptoBufferedNetworkStream *fs3 = new CryptoBufferedNetworkStream();
}




/*  装饰器模式  */
// 业务操作
class Stream  // UML中的Component【稳定】
{
public:
    virtual char Read(int number) = 0;
    virtual void Seek(int position) = 0;
    virtual void Write(char data) = 0;

    virtual ~Stream() {}
};

// 主体类
class FileStream : public Stream  // UML中的ConcreteComponent【变化】
{
public:
    virtual char Read(int number)
    {
        // 读文件流
    }

    virtual void Seek(int position)
    {
        // 定位文件流
    }

    virtual void Write(char data)
    {
        // 写文件流
    }
};

class NetworkStream : public Stream   // UML中的ConcreteComponent【变化】
{
public:
    virtual char Read(int number)
    {
        // 读网络流
    }

    virtual void Seek(int position)
    {
        // 定位网络流
    }

    virtual void Write(char data)
    {
        // 写网络流
    }
};

class MemoryStream : public Stream   // UML中的ConcreteComponent【变化】
{
public:
    virtual char Read(int number)
    {
        // 读内存流
    }

    virtual void Seek(int position)
    {
        // 定位内存流
    }

    virtual void Write(char data)
    {
        // 写内存流
    }
};

// 扩展操作
class DecoratorStream : public Stream // UML中的Decorator【稳定】
{
protected:
    Stream* stream;  // 使用时可以是=new FileStream()、=new NetworkStream()、=new MemoryStream()
    DecoratorStream(Stream* stm): stream(stm){}
};



class CryptoStream : public DecoratorStream // 此处还需继承DecoratorStream是为了满足virtual char Read(int number)等处的接口规范
// UML中的ConcreteDecoratorA【变化】
{
    
public:
    CryptoStream(Stream *stm) : DecoratorStream(stm) {}
    virtual char Read(int number)
    {
        // 额外的加密操作...
        stream->Read(number); // 读文件流
    }

    virtual void Seek(int position)
    {
        // 额外的加密操作...
        stream->Seek(position); // 定位文件流
        // 额外的加密操作...
    }

    virtual void Write(char data)
    {
        // 额外的加密操作...
        stream->Write(data); // 写文件流
        // 额外的加密操作...
    }
};

// 缓冲处理
class BufferedStream : public DecoratorStream  // UML中的ConcreteDecoratorB【变化】
{
public:
    BufferedStream(Stream *stm) : DecoratorStream(stm) {}
    virtual char Read(int number)
    {
        // 额外的缓冲处理...
        stream->Read(number);
    }

    virtual void Seek(int position)
    {
        // 额外的缓冲处理...
        stream->Seek(position);
        // 额外的缓冲处理...
    }

    virtual void Write(char data)
    {
        // 额外的缓冲处理...
        stream->Write(data);
        // 额外的缓冲处理...
    }
};

// 加密操作+缓冲处理
class CryptoBufferedStream : public DecoratorStream  // UML中的ConcreteDecoratorC【变化】
{
public:
    CryptoBufferedStream(Stream *stm) :DecoratorStream(stm) {}

    virtual char Read(int number)
    {
        // 额外的加密操作...
        // 额外的缓冲操作...
        stream->Read(number);
    }

    virtual void Seek(int position)
    {
        // 额外的加密操作...
        // 额外的缓冲操作...
        stream->Seek(position);
        // 额外的加密操作...
        // 额外的缓冲操作...
    }

    virtual void Write(char data)
    {
        // 额外的加密操作...
        // 额外的缓冲操作...
        stream->Write(data);
        // 额外的加密操作...
        // 额外的缓冲操作...
    }
};

void Process()
{
    // 运行时装配
    FileStream *s1 = new FileStream();
    CryptoStream *s2 = new CryptoStream(s1);

    BufferedStream *s3 = new BufferedStream(s1);

    BufferedStream *s4 = new BufferedStream(s2);
}
