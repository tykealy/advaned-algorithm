#include <iostream>
#include <stdlib.h>
using namespace std;

int sumSuit(int n)
{
    int sum = 0;
    for (int i = 1; i <= n; i++)
    {
        sum += i;
    }
    return sum;
}

float convertTemp(float temp, int choices)
{
    float result;
    switch (choices)
    {
    case 1:
        result = temp * 1.8 + 32;
        break;
    case 2:
        result = (temp - 32) * 5 / 9;
        break;
    default:
        break;
    }
    return result;
}

int sumDigit(int k)
{
    int sum = 0;
    while (k != 0)
    {
        sum += k % 10;
        k = k / 10;
    }
    return sum;
}

int main()
{
    system("clear");
    int choice;
    while (choice != 0)
    {
        cout << "1. Calculate from 1 to n." << endl;
        cout << "2. Temperature converter (F to C and C to F)" << endl;
        cout << "3. Sum of number's digit." << endl;
        cout << "Enter from 1 to 3 or enter 0 to quit: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            system("clear");
            int n;
            cout << "Enter n: ";
            cin >> n;
            cout << "Result = " << sumSuit(n) << endl;
            cout << "==================================================" << endl;
            break;
        case 2:
            system("clear");
            int temp, choices;
            cout << "1. C to F" << endl;
            cout << "2. F to C" << endl;
            cout << "Choose a converter: ";
            cin >> choices;
            cout << "Enter temp: ";
            cin >> temp;
            cout << "Result = " << convertTemp(temp, choices) << endl;
            cout << "==================================================" << endl;
            break;
        case 3:
            system("clear");
            int k;
            cout << "Enter n: ";
            cin >> k;
            cout << "Result = " << sumDigit(k) << endl;
            cout << "==================================================" << endl;
            break;
        default:
            break;
        }
    }
}