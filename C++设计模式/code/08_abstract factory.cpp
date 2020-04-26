#include <iostream>
#include <vector>


using namespace std;

/*  普通方法  */
class EmployeeDAO{
public:
    vector<EmployeeDAO> GetEmployees(){
        SqlConnection* connection = new Sqlconnection();
        connection->ConnectionString("...");

        SqlCommand* command = new SqlCommand();
        command->CommandText("...");
        command->SetConnection(connection);

        SqlDataReader* reader = command->ExecuteReader();
        while(reader->Read()){

        }
    }
};



/* 工厂方法  */

// 数据库访问有关的基类
class IDBConnection{

};
class IDBConnectionFactory{
public:
    virtual IDBConnection* CreateDBConnection() = 0;
};



class IDBCommand{

};
class IDBCommandFactory{
public:
    virtual IDBCommand* CreateDBCommand() = 0;
};


class IDBDataReader{

};
class IDBDataReaderFactory{
public:
    virtual IDBDataReader* CreateDBDataReader() = 0; 
};


// 支持SQL Server
class SqlConnection: public IDBConnection{

};
class SqlConnectionFactory: public IDBConnectionFactory{

};


class SqlCommand: public IDBCommand{

};
class SqlCommandFactory: public IDBCommandFactory{

};


class SqlDataReader: public IDBDataReader{

};
class SqlDataReaderFactory: public IDBDataReaderFactory{

};


// 支持Oracle
class OracleConnection: public IDBConnection{

};

class OracleCommand: public IDBCommand{

};

class OracleReader: public IDataReader{

};


// 客户程序
class EmployeeDAO{
private:
    IDBConnectionFactory* dbConnectionFactory;
    IDBCommandFactory* dbCommandFactory;
    IDBDataReaderFactory* dbDataReaderFactory;

public:
    vector<EmployeeDAO> GetEmployees(){
        IDBConnection* connection = dbConnectionFactory->CreateDBConnection();
        connection->ConnectionString("...");

        IDBCommand* command = dbCommandFactory->CreateDBCommand();command->CommandText("...");
        command->SetConnection(connection);  // 关联性

        IDBDataReader* reader = command->ExecuteReader(); // 关联性
        while(reader->Read()){

        }
    }
};



/* 抽象工厂  */

// 数据库访问有关的基类
class IDBConnection{  // UML中的AbstractProductA【稳定】

};
class IDBCommand{  // UML中的AbstractProductB【稳定】

};

class IDBDataReader{  // UML中的AbstractProductC【稳定】

};



class IDBFactory{  // UML中的AbstractFactory【稳定】
public:  // 负责一系列相互依赖的对象创建工作
    virtual IDBConnection* CreateDBConnection() = 0;
    virtual IDBCommand* CreateDBCommand() = 0;
    virtual IDBDataReader* CreateDBDataReader() = 0; 
};


// 支持SQL Server
class SqlConnection: public IDBConnection{    // UML中的AbstractProductA下面依赖的ProductA1

};
class SqlCommand: public IDBCommand{  // UML中的AbstractProductB下面依赖的ProductB1

};
class SqlDataReader: public IDBDataReader{  // UML中的AbstractProductC下面依赖的ProductC1

};

class SqlDBFactory: public IDBFactory{  // UML中的ConcreteFactory【变化】
public:
    virtual IDBConnection* CreateDBConnection() = 0;
    virtual IDBCommand* CreateDBCommand() = 0;
    virtual IDBDataReader* CreateDBDataReader() = 0;
};



// 支持Oracle
class OracleConnection: public IDBConnection{  

};

class OracleCommand: public IDBCommand{

};

class OracleReader: public IDataReader{

};


// 客户程序
class EmployeeDAO{
private:
    IDBFactory* dbFactory;
public:
    vector<EmployeeDAO> GetEmployees(){
        IDBConnection* connection = dbFactory->CreateDBConnection();
        connection->ConnectionString("...");

        IDBCommand* command = dbFactory->CreateDBCommand();command->CommandText("...");
        command->SetConnection(connection);  // 关联性

        IDBDataReader* reader = command->ExecuteReader(); // 关联性
        while(reader->Read()){

        }
    }
};
