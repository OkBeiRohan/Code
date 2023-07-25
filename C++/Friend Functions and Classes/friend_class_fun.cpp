/**
 * Friend Functions and Classes
 * Friend Class is a class whose members have access to the private and protected members of another class.
 * Friend Function is a function that is not a member of a class but has access to the class's private and protected members.
 */

#include <iostream>

using namespace std;

/**
 * class_2 should be declared before class_1 because class_1 uses class_2
 */
class class_2;

class class_1
{
    int x;

public:
    /**
     * Constructor
     * @param num
     *
     * The constructor is declared as public because it is used to initialize the object of the class.
     * If the constructor is declared as private, then the object of the class cannot be created.
     * The constructor is declared as private when the class is a singleton class.
     * A singleton class is a class that can have only one object (an instance of the class) at a time.
     * After first time, if we try to instantiate the Singleton class, the new variable also points to the first instance created.
     * So whatever modifications we do to any variable inside the class through any instance, it affects the variable of the single instance created and is visible if we access that variable through any variable of that class type defined.
     *
     * Here, the constructor assigns a value to the private member x.
     */
    class_1(int num)
    {
        x = num;
    }

    /**
     * Friend function and class declaration should be in the public section of the class.
     * The friend function and class can access the private and protected members of the class.
     */
    friend void friend_fun(class_1 obj); // friend function declaration
    friend class class_2;                // friend class declaration
};

class class_2
{
public:
    /**
     * The friend function can be defined inside the class or outside the class.
     */
    void fun(class_1 obj)
    {
        cout << "(Friend Class) The value of x is " << obj.x << endl;
    }
};

/**
 * The friend function can be defined outside the class.
 */
void friend_fun(class_1 obj)
{
    cout << "(Friend Function) The value of x is " << obj.x << endl;
}

int main()
{
    class_1 obj(1);
    friend_fun(obj);

    class_2 obj2;
    obj2.fun(obj);

    return 0;
}