#include <iostream>
using namespace std;

double multiply(int count, double *numbers)
{
    double result = 1;
    for (int i = 0; i < count; i++)
        result *= numbers[i];
    return result;
}

int main()
{
    int count;
    cout << "Enter count of numbers to multiply: ";
    cin >> count;
    double *numbers = new double[count];
    cout << "Enter " << count << " numbers to multiply: ";
    for (int i = 0; i < count; i++)
        cin >> numbers[i];
    double result = multiply(count, numbers);
    cout << "Multiplication result is: " << result << "\n";
    delete[] numbers;
    return 0;
}