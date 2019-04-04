#include "iostream"

using namespace std;



class Box{
    public:
        Box(int l, int w, int h): length(l), width(w), height(h){
            cout << "Box类对象的构造函数\n";
        }
        int getVolume(){
            return length * width * height;
        }
    private:
        int length;
        int width;
        int height;
};


class Add{
    public:
        Add(int a, int b): x(a), y(b){
            cout << "Add类的对象的构造函数\n";
        }
        int getTotal(){
            return x + y;
        }
    private:
        int x;
        int y;
};




int main(){
    Add add(10, 20);
    cout << "10 + 20 = " << add.getTotal() << endl;
    return 0;
}