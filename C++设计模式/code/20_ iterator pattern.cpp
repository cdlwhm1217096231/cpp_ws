#include <iostream>


using namespace std;


/*   迭代器模式   */

template<typename T> 
class Iterator {
public:
    virtual void first() = 0;
    virtual void next() = 0;
    virtual bool isDone() const = 0;
    virtual T& current() = 0;
};

template<typename T>
class MyCollection{
public:
    Iterator<T> GetIterator(){
        // ....
    }
};


template<typename T>
class CollectionIterator: public Iterator {
private:
    MyCollection<T> mc;
public：
    CollectionIterator(const MyCollection<T>& c): mc(c){}
    
    // 重写 
    void first(){

    }
    void next(){

    }
    bool isDone() const {

    }

    T& current() {

    }
};


void MyAlgorithm(){
    MyCollection<int> mc;
    Iterator<int> iter = mc.GetIterator();

    for(iter.first(); iter.isDone(); iter.next()){
        cout << iter.current() << endl;
    }
}