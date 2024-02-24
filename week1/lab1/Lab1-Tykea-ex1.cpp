#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    float a, b, c;
    float x1, x2;
    float delta;
    cout << "Input a,b,c: ";
    cin >> a >> b >> c;

    delta = (b * b) - (4 * a * c);
    if (delta == 0)
    {
        x1 = x2 = -b / (2 * a);
        cout << "x1 = x2 = " << x1 << endl;
    }
    else if (delta > 0)
    {
        x1 = (-b + sqrt(delta)) / (2 * a);
        x2 = (-b - sqrt(delta)) / (2 * a);
        cout << "x1 = " << x1 << endl;
        cout << "x2 = " << x2 << endl;
    }
    else if (delta < 0)
    {
        float realPart = -b / (2 * a);
        float imaginaryPart = sqrt(-delta) / (2 * a);
        cout << "Roots are complex and different." << endl;
        cout << "x1 = " << realPart << " + " << imaginaryPart << "i" << endl;
        cout << "x2 = " << realPart << " - " << imaginaryPart << "i" << endl;
    }
}