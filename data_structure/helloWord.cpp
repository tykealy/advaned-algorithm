#include <iostream>

using namespace std;
int addingfromOneToN(int n)
{
    int i = 1, k = 0;
    while (i <= n)
    {
        k += i;
        cout << i;
        (i == n) ? cout << "=" : cout << "+";
        i++;
    }

    return k;
}

int main()
{
    int n;
    // string name;
    // int age;
    // cout << "Hello" << endl;
    // cout << "Welcome to the Boyloy Community" << endl;
    // cout << "Enter your name: ";
    // getline(cin, name);
    // cout << "Hi there " << name << "!" << endl;
    // cout << "How old are you? ";
    // cin >> age;
    // cout << "So your age is " << age << endl;
    // int year = 2022 - age;
    // cout << "Your birth year is " << year << endl;
    cout << "Enter n: ";
    cin >> n;
    // cout << addingfromOneToN(n) << endl;
    cout << addingfromOneToN(n) << endl;
}
