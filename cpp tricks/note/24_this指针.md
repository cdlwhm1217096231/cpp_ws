### 1.Cpp中的this指针
- 在C++中，**每一个对象都能通过this指针来访问自己的地址。this指针是所有成员函数的隐含参数**。因此，在成员函数内部，它可以用来指向调用对象。**友元函数没有this指针，因为友元不是类的成员，只有成员函数才有this指针。**
- this指针实例1如下：
    ```
        #include "iostream"

        using namespace std;


        class Box{
            public:
            // 构造函数定义
            Box(double l = 2.0, double w = 3.0, double h = 4.0): length(l), width(w), height(h){
                    cout << "这是Box的构造函数...\n";
                }
                // 普通成员函数
                double Volume(){
                    return length * width * height;
                }
                
                int compare(Box box){
                    return this->Volume() > box.Volume();
                }
            private:
                int length;
                int width;
                int height;
        };

        int main(){
            Box box1(3.3, 2.1, 1.5);
            Box box2(8.5, 6.0, 2.0);
            if(box1.compare(box2))
                cout << "box2 小于 box1\n";
            else
                cout << "box2 大于等于 box1\n";
            return 0;
        }
    ```
- 引入this：当我们调用成员函数时，实际上是替某个对象调用它。**成员函数通过一个名为this的额外隐式参数来访问调用它的那个对象，当我们调用一个成员函数时，用请求该函数的对象地址初始化this**。例如，如果调用total.isbn()则编译器负责把total的地址传递给isbn的隐式形参this，可以等价地认为编译器将该调用重写成了以下形式：
    ```
        //伪代码，用于说明调用成员函数的实际执行过程,其中，调用Sales_data类的isbn成员函数时传入了total对象的地址
        Sales_data::isbn(&total)
    ```
- 在成员函数内部，我们可以直接使用调用该函数的对象的成员，而无须通过成员访问运算符来做到这一点，因为this所指的正是这个对象。任何对类成员的直接访问都被看作是对this的隐式引用，也就是说，当isbn使用bookNo时，它隐式地使用this指向的成员，就像我们书写了 this->bookNo一样。对于我们来说，this形参是隐式定义的。实际上，任何自定义名为this的参数或变量的行为都是非法的。我们可以在成员函数体内部使用this，因此尽管没有必要，我们还是能把isbn定义成如下形式：
    ```
        std::string isbn() const { return this->bookNo; }
    ```
- 因为this的目的总是指向“这个”对象，所以this是一个常量指针，我们不允许改变this中保存的地址。
- this指针实例2如下：
    ```
        class Rect{
        public:
            Rect(){;}
            ~Rect(){;}
            Rect* get_address(){  // 指针函数，返回this的地址
                return this;
            }
        };
        // Rect* 定义指针p接受对象r1的get_address()成员函数的返回值，并打印
        Rect* p = r1.get_address();
        cout << "通过this指针来返回调用get_address()成员函数的对象r1的地址p = " << p << endl;
        p = r2.get_address();
        cout << "通过this指针来返回调用get_address()成员函数的对象r2的地址p = " << p << endl;
    ```
### 2.this指针的形象化理解
- 关于C++中this指针的理解：当你进入一个房子后，你可以看到房子内的桌子、椅子、地板等；但是你看不到房子的全貌；对于类来说，你可以看到成员函数、成员变量，但你看不到实例本身，但是应用this可以让我们看到这个实例本身。class类就好比这座房子，this就好比一把钥匙，通过钥匙来打开了这座房子的门，那么里面的东西就随意你取用了。
- 因为this作用域是在类的内部，自己声明一个类的时候，还不知道实例化对象的名字，所以用this来使用对象变量的自身。在非静态成员函数中，编译器在编译的时候加上this作为隐含形参，通过this来访问各个成员（即使你没有写上this指针）。
