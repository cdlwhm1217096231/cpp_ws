#include "iostream"


using namespace std;


class Box{
    public:
        // 纯虚函数
        virtual double getVolume() = 0;
    private:
        int length;
        int width;
        int height;
};

// 基类Shape是个抽象类
class Shape{
    public:
    // 提供接口框架的纯虚函数
        virtual int getArea() = 0;
        void setLength(int l){
            length = l;
        }
        void setWidth(int w){
            width = w;
        }
    protected:
        int length;
        int width;
};

// 派生类1
class Rect: public Shape{
    public:
        int getArea(){
            return length * width;
        }
};
// 派生类2
class Triangle: public Shape{
    public:
        int getArea(){
            return length * width / 2;
        }
};
       


int main(){
    Rect r;
    Triangle t;

    r.setLength(4);
    r.setWidth(5);
    cout << "矩形的面积是: " << r.getArea() << endl;

    t.setLength(4);
    t.setWidth(5);
    cout << "三角形的面积是: " << t.getArea() << endl;
    return 0;
}