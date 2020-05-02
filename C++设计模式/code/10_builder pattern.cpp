#include <iostream>

using namespace std;

/* 普通方法  */

class House
{
public:
    void Init()
    {
        this->BuildPart1();

        for (int i = 0; i < 4; i++)
        {
            this->BuildPart2();
        }

        bool flag = this->BuildPart3();
        if (flag)
        {
            this->BuildPart4();
        }
        this->BuildPart5();
    }

    virtual ~House(){}
protected:
    virtual void BuildPart1() = 0;
    virtual void BuildPart2() = 0;
    virtual bool BuildPart3() = 0;
    virtual void BuildPart4() = 0;
    virtual void BuildPart5() = 0;
};

class StoneHouse: public House{
protected:
    virtual void BuildPart1(){

    }
    virtual void BuildPart2(){

    }
    virtual bool BuildPart3() {
        
    }
    virtual void BuildPart4(){
        
    }
    virtual void BuildPart5() {
        
    }
};


int main(){
    House* pHouse = new StoneHouse();
    pHouse->Init();
    return 0;
}



/* 构建器模式  */

// 对象的表示
class House
{
public:
    void Init()
    {
        this->BuildPart1();

        for (int i = 0; i < 4; i++)
        {
            this->BuildPart2();
        }

        bool flag = this->BuildPart3();
        if (flag)
        {
            this->BuildPart4();
        }
        this->BuildPart5();
    }
    
    virtual ~House(){}
protected:
    virtual void BuildPart1() = 0;
    virtual void BuildPart2() = 0;
    virtual bool BuildPart3() = 0;
    virtual void BuildPart4() = 0;
    virtual void BuildPart5() = 0;
};

// 对象的构建
class HouseBuilder{  // UML中的Builder【稳定】
public:
    House* getResult(){  
        return pHouse;
    }

    virtual ~HouseBuilder(){}

protected:
    House* pHouse;
    virtual void BuildPart1() = 0;
    virtual void BuildPart2() = 0;
    virtual bool BuildPart3() = 0;
    virtual void BuildPart4() = 0;
    virtual void BuildPart5() = 0;
};


class StoneHouse: public House{
protected:
    virtual void BuildPart1(){
        // pHouse->Part1 = ....
    }
    virtual void BuildPart2(){

    }
    virtual bool BuildPart3() {
        
    }
    virtual void BuildPart4(){
        
    }
    virtual void BuildPart5() {
        
    }
};


class StoneHouseBuilder: public HouseBuilder{
protected:
    virtual void BuildPart1(){

    }
    virtual void BuildPart2(){

    }
    virtual bool BuildPart3() {
        
    }
    virtual void BuildPart4(){
        
    }
    virtual void BuildPart5() {
        
    }
};


class HouseDirector{  // UML中的Director【稳定】
public:
    HouseBuilder* pHouseBuilder; 
    HouseDirector(HouseBuilder* pHouseBuilder){
        this->pHouseBuilder = pHouseBuilder;
    }


    House* Construct()
    {
       pHouseBuilder->BuildPart1();

        for (int i = 0; i < 4; i++)
        {
            pHouseBuilder->BuildPart2();
        }

        bool flag = pHouseBuilder->BuildPart3();
        if (flag)
        {
            pHouseBuilder->BuildPart4();
        }
        pHouseBuilder->BuildPart5();
        return pHouseBuilder->getResult();
    }
};


