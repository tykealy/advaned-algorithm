#include <iostream>

using namespace std;
float sumSuit(float n)
{
    float sum = 0;
    for (int i = 1; i <= n; i++)
    {
        sum += i;
    }
    return sum / n;
}
int main()
{
    float n;
    cout << "enter n: ";
    cin >> n;
    cout << "(";
    for (int i = 1; i <= n; i++)
    {
        cout << i;

        (i == n) ? cout << ")/" << n << "=" : cout << "+";
    }
    cout << sumSuit(n) << endl;
}
