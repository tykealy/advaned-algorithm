#include <iostream>
#include <stdlib.h>
using namespace std;

struct person
{
    string name;
    int age;
    string zodiac;
};

int main()
{
    system("clear");
    person p[4];
    int i = 1;
    while (i <= 4)
    {
        cout << "Person" << i << endl;
        cout << "Enter your name: ";
        cin >> p[i].name;
        cout << "Enter your age: ";
        cin >> p[i].age;
        cout << "Enter your zodiac sign: ";
        cin >> p[i].zodiac;
        i++;
        system("clear");
    }
    system("clear");
    i = 1;
    while (i <= 4)
    {
        cout << "Person" << i << endl;
        cout << "   name: " << p[i].name << endl;
        cout << "   age: " << p[i].age << endl;
        cout << "   zodiac: " << p[i].zodiac << endl;
        i++;
    }
    int old = 1;
    for (int k = 1; k <= 4; k++)
    {
        if (p[old].age < p[k].age)
        {
            old = k;
        }
        else
        {
            continue;
        }
    }
    cout << "===============================" << endl;
    cout << "The oldest person is " << endl;
    cout << p[old].name << endl;
}