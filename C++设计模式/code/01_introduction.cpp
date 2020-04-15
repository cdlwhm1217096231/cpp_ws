#include <iostream>
#include <vector>

using namespace std;

/*   面向过程(分解)    VS  面向对象(抽象)*/

// shape类
class Point
{
public:
    int x;
    int y;
};

// Line类
class Line
{
public:
    Point start;
    Point end;

    Line(const Point &start, const Point &end)
    {
        this->start = start;
        this->end = end;
    }
};

// Rect类
class Rect
{
public:
    Point leftUp;
    int width;
    int height;

    Rect(const Point &leftUp, int width, int height)
    {
        this->leftUp = leftUp;
        this->width = width;
        this->height = height;
    }
};


/*  面向过程(分解)  */

class Form
{
};

class MainForm : public Form
{
private:
    Point p1;
    Point p2;

    vector<Line> lineVector;
    vector<Rect> rectVector;
    // 改变
    vector<Circle> circleVector;
public:
    MainForm()
    {
        // ...
    }

protected:
    virtual void OnMouseDown(const MouseEventArgs &e);
    virtual void OnMouseUp(const MouseEventArgs &e);
    virtual void OnPaint(const PaintEventArgs &e);
};

void MainForm::OnMouseDown(const MouseEventArgs &e)
{
    p1.x = e.X;
    p1.y = e.Y;

    //...
    Form::OnMouseDown(e);
}

void MainForm::OnMouseUp(const MouseEventArgs &e)
{
    p2.x = e.X;
    p2.y = e.Y;
}

// 增加Circle类
class Circle{
public:
    // ...
};






/*  面向对象(抽象)  */
class Shape
{
public:
    virtual void Draw(const Graphics &g) = 0;   // 纯虚函数!!!
    virtual ~Shape() {}
};

class Line : public Shape
{
public:
    Point start;
    Point end;
    Line(const Point &start, const Point &end)
    {
        this->start = start;
        this->end = end;
    }

    // 实现自己的Draw,负责画自己
    virtual void Draw(const Graphics &g)
    {
        g.DrawLine(Pens.Red, start.x, start.y, end.x, end.y);
    }
};

class Rect : public Shape
{
public:
    Point leftUp;
    int width;
    int height;
    Rect(const Point &leftUp, int width, int height)
    {
        this->leftUp = leftUp;
        this->width = width;
        this->height = height;
    }

    // 实现自己的Draw,负责画自己
    virtual void Draw(const Graphics &g)
    {
        g.DrawRectangle(Pen.Red, leftUp, width, height);
    }
};

class MainForm : public Form
{
private:
    Point p1;
    Point p2;

    // 针对所有的形状
    vector<Shape*> shapeVector;  // 此处使用的是指向Shape类的指针，需要多态性
public:
    MainForm()
    {
        // ...
    }

protected:
    virtual void OnMouseDown(const MouseEventArgs &e);
    virtual void OnMouseUp(const MouseEventArgs &e);
    virtual void OnPaint(const PaintEventArgs &e);
};

void MainForm::OnPaint(const PaintEventArgs& e){
    // 针对所有形状
    for(int i = 0; i < shapeVector.size(); i++){
        shapeVector[i]->Draw(e.Graphics);  // 多态调用，各负其责
    }

    //  ...
    Form::OnPaint(e);
}

// 增加
class Circle: public Shape{
public:
    Point dot;
    int radius;
    // 实现自己的Draw,负责画自己
    virtual void Draw(const Graphics &g)
    {
        g.DrawCircle(Pen.Red, dot, radius);
    }
};