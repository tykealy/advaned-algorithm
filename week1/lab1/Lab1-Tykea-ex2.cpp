#include <iostream>

using namespace std;

int main()
{
    int i = 1;

    for (i = 1; i <= 1000; i++)
    {
        if (i == 100 || i == 200 || i == 300 || i == 400 || i == 500)
        {
            continue;
        }
        cout << i << " ";
    }
}