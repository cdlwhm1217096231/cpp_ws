#include <iostream>

using namespace std;

/*  普通方法实现  */
enum TaxBase
{
    CN_Tax,
    US_Tax,
    DE_Tax,
    FR_Tax // 更改
};

class SalesOrder
{
private:
    TaxBase tax;

public:
    double CalculateTax()
    {
        // ...

        if (tax == CN_Tax)
        {
            // CN***********
        }
        else if (tax == US_Tax)
        {
            // US***********
        }
        else if (tax == DE_Tax)
        {
            // DE***********
        }

        else if (tax == FR_Tax) // 更改
        {
            // FR***********
        }

        // ....
    }
};

/*  策略模式实现  */
// 稳定
class TaxStategy
{
public:
    virtual double Calculate(const Context &context) = 0;
    virtual ~TaxStategy() {}
};

// 变化
class CNTax : public TaxStategy
{
public:
    virtual double Calculate(const Context &context)
    {
        // ***********
    }
};

// 变化
class USTax : public TaxStategy
{
public:
    virtual double Calculate(const Context &context)
    {
        // ***********
    }
};

// 变化
class DETax : public TaxStategy
{
public:
    virtual double Calculate(const Context &context)
    {
        // ***********
    }
};

// 扩展
class FRTax : public TaxStategy
{
public:
    virtual double Calculate(const Context &context)
    {
        // ***********
    }
};

// 稳定
class SalesOrder
{
private:
    TaxStategy *startegy;

public:
    SalesOrder(StrategyFactory *strategyFactory)
    {
        this->startegy = strategyFactory->NewStartegy();
    }
    ~SalesOrder()
    {
        delete this->startegy;
    }

    double CalculateTax()
    {
        // ...
        Context context();

        double val = startegy->Calculate(context); // 多态调用
        // ...
    }
};