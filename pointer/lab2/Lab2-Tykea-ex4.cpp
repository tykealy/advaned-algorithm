#include <iostream>

using namespace std;

void findMinMax(int number[7], int *min, int *max)
{
    *min = *max = number[0];
    for (int i = 0; i < 7; i++)
    {
        if (number[i] < *min)
        {
            *min = number[i];
        }
        if (number[i] > *max)
        {
            *max = number[i];
        }
    }
}

int main()
{
    int number[7], min, max;
    cout << "Enter 7 integer." << endl;
    for (int i = 0; i < 7; i++)
    {
        cout << i + 1 << ": ";
        cin >> number[i];
    }

    findMinMax(number, &min, &max);
    cout << "Min is" << min << endl;
    cout << "Max is" << max << endl;
}