#include <iostream>
#include <cmath>

using namespace std;

void solveQuadratic(int a, int b, int c, float *x1, float *x2)
{
    float delta;

    delta = (b * b) - (4 * a * c);
    if (delta == 0)
    {
        *x1 = *x2 = -b / (2 * a);
    }
    else if (delta > 0)
    {
        *x1 = (-b + sqrt(delta)) / (2 * a);
        *x2 = (-b - sqrt(delta)) / (2 * a);
    }
}

int main()
{
    int a, b, c;
    float x1, x2;
    cout << "Enter a b c: ";
    cin >> a >> b >> c;
    solveQuadratic(a, b, c, &x1, &x2);

    cout << "X1 = " << x1 << endl;
    cout << "X1 = " << x2 << endl;
}
