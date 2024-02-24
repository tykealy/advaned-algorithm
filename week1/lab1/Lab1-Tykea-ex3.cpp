#include <iostream>

using namespace std;

int main()
{
    int sum = 0, input = 0;
    while (input != -1)
    {
        cout << "Enter the number to sum: ";
        cin >> input;
        if (input == -1)
        {
            cout << "total = " << sum << endl;
            break;
        }
        sum += input;
    }
}