#include <iostream>

using namespace std;

int main()
{
    int arr[7];
    int *arrpt = &arr[0];
    cout << "Enter 7 integer." << endl;
    for (int i = 0; i < 7; i++)
    {
        cout << i + 1 << ": ";
        cin >> arr[i];
    }
    for (int i = 0; i < 7; i++)
    {
        cout << *arrpt << endl;
        arrpt++;
    }
}