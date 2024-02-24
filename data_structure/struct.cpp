#include <iostream>

using namespace std;

struct Student
{
    string name;
    string id;
    int age;
};
int main()
{
    Student st[10];

    int i = 0;
    while (i <= 1)
    {
        cout << "Getting info for student " << i + 1 << endl;
        cout << "Enter your name: ";
        cin >> st[i].name;
        // getline(cin, st[i].name);
        cout << "Enter your age: ";
        cin >> st[i].age;
        cout << "Enter your ID: ";
        cin >> st[i].id;
        i++;
    }

    cout << "\t\t\tStudent information" << endl;

    int k = 0;
    while (k <= 1)
    {
        cout << st[k].id << "\t" << st[k].name << "\t" << st[k].age << endl;
        k++;
    }
};