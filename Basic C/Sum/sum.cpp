#include <iostream>
using namespace std;

double sum(int count, double *numbers)
{
    double result = 0;
    for (int i = 0; i < count; i++)
    {
        result += numbers[i];
    }
    return result;
}

int main()
{
    int count;
    cout << "Enter count of numbers to sum: ";
    cin >> count;
    double *numbers = new double[count];
    cout << "Enter " << count << " numbers to sum: ";
    for (int i = 0; i < count; i++)
    {
        cin >> numbers[i];
    }
    double result = sum(count, numbers);
    cout << "Sum result is: " << result << "\n";
    delete[] numbers;
    return 0;
}