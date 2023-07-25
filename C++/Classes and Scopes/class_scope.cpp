#include <iostream>

using namespace std;

class sum
{
    int x, y;
    void fun_display(int var1) // default declaration is private
    {
        // Defining a function inside a class makes it inline function
        cout << "The value of var1 is " << var1 << endl;
    }

public:
    sum(int x, int b = 0)
    {
        // constructor
        this->x = x;
        y = b;
    }
    sum(const sum &obj)
    {
        // copy constructor
        x = obj.x;
        y = obj.y;
    }
    ~sum()
    {
        // destructor
    }
    void disp()
    {
        fun_display(1);
        /* the function disp() is accessible outside class and can be used to access the private function in this case */
    }
    int fun2(); // Only defiinition
    int operator+(sum obj)
    {
        // operator overloading
        sum temp(0, 0);
        temp.x = x + obj.x;
        temp.y = y + obj.y;
        return temp.x + temp.y;
    }
};

int main()
{
    sum obj1(1, 2);
    obj1.disp();                                             // accessible outside class. fun_display() is not accessible outside class
    sum obj2(obj1);                                          // copy constructor and also constructor overloading
    cout << "Operator Overloading: " << obj1 + obj2 << endl; // operator overloading

    return 0;
}

int sum::fun2()
{
    // definition of the function declared inside the class. This will not be an inline function
    return 0;
}