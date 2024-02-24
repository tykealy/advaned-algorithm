
#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter n: ";
    cin >> n;
    int *p = &n;
    *p = *p + 7;
    cout << n << endl;
}
