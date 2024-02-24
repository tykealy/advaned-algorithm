#include <iostream>
#include <stdlib.h>
using namespace std;

void sum1(double *sum, unsigned int n)
{
    for (float i = 1; i <= n; i++)
    {
        *sum += (1 / i);
    }
}
double sum2(unsigned int n)
{
    double sum = 0;
    for (float i = 1; i <= n; i++)
    {
        sum += (1 / i);
    }
    return sum;
}

int main()
{
    system("clear"); 
    double result;
    double sum = 0;
    sum1(&sum, 7);
    result = sum2(5);
    cout << result << endl;
    cout << sum << endl;
}