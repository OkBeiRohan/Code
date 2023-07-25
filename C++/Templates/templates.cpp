/**
 * Templates are the foundation of generic programming, which involves writing code in a way that is independent of any particular type.
 * A template is a blueprint or formula for creating a generic class or a function.
 * The library containers like iterators and algorithms are examples of generic programming and have been developed using template concept.
 * There is a single definition of each container, such as vector, but we can define many different kinds of vectors for example, vector <int> or vector <string>.
 * You can use templates to define functions as well as classes, let us see how they work:
 */

#include <iostream>

using namespace std;

template <class T> // template declaration
T sum(T a, T b)    // template function with typename T
{
    return a + b;
}

/**
 * Inputs two types of data and returns the sum in the type of the first parameter
 */
template <class U, class V>
U sum(U a, V b)
{
    return a + b;
}

template <class T>
void add(T a, T b)
{
    cout << "Template Function: " << a + b << endl;
}

template <class T, class U>
void add(T a, U b)
{
    cout << "Template Function: " << a + b << endl;
}

// template <class T>
// float sum(T a, int b)
// {
//     // this is also possible
//     return a + b;
// }

// Template Class
template <class T>
class mypair
{
    T a, b;

public:
    mypair(T first, T second)
    {
        a = first;
        b = second;
    }
    T getmax()
    {
        T max;
        max = a > b ? a : b;
        return max;
    }
};

int main()
{
    cout << "Template Function: " << sum(1, 2) << endl; // template function call
    cout << "Template Function: " << sum(1.1, 2.2) << endl;
    cout << "Template Function: " << sum(11, 2.2) << endl;
    cout << "Template Function: " << sum('A', 'b') << endl;

    cout << "Using void add() template function: " << endl;

    add(1, 2);
    add(1.1, 2.2);
    add(11, 2.2);
    add('A', 'b');

    cout << "Using template class: " << endl;

    mypair<int> myobj(100, 75);
    cout << "Max of 100, 75 is " << myobj.getmax() << endl;

    mypair<char> myobj2('A', 'B');
    cout << "Max of A, B is " << myobj2.getmax() << endl;

    return 0;
}
